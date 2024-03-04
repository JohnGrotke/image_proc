
#pragma once

#include <png.h>
#include <iostream>
#include <cstdio>
#include <vector>

struct PNGData
{
    int width;
    int height;
    std::vector<unsigned char> pixels; // Vector to store RGB pixel values
};

class PNG_Reader
{
public:
    PNG_Reader(const std::string &filename) : filename_(filename) {}

    bool read(std::vector<std::vector<std::vector<int>>> &image)
    {
        FILE *fp = fopen(filename_.c_str(), "rb");
        if (!fp)
        {
            std::cerr << "Error: Unable to open file " << filename_ << std::endl;
            return false;
        }

        png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        if (!png)
        {
            std::cerr << "Error: png_create_read_struct failed" << std::endl;
            fclose(fp);
            return false;
        }

        png_infop info = png_create_info_struct(png);
        if (!info)
        {
            std::cerr << "Error: png_create_info_struct failed" << std::endl;
            png_destroy_read_struct(&png, NULL, NULL);
            fclose(fp);
            return false;
        }

        if (setjmp(png_jmpbuf(png)))
        {
            std::cerr << "Error during PNG read" << std::endl;
            png_destroy_read_struct(&png, &info, NULL);
            fclose(fp);
            return false;
        }

        png_init_io(png, fp);
        png_set_sig_bytes(png, 0);

        png_read_info(png, info);
        int width = png_get_image_width(png, info);
        int height = png_get_image_height(png, info);
        png_byte color_type = png_get_color_type(png, info);
        png_byte bit_depth = png_get_bit_depth(png, info);

        if (bit_depth != 8 || color_type != PNG_COLOR_TYPE_RGB)
        {
            std::cerr << "Error: Unsupported image format (bit depth: " << (int)bit_depth
                      << ", color type: " << (int)color_type << ")" << std::endl;
            png_destroy_read_struct(&png, &info, NULL);
            fclose(fp);
            return false;
        }

        std::vector<png_byte> row(width * 3);
        image.resize(height, std::vector<std::vector<int>>(width, std::vector<int>(3)));

        for (int y = 0; y < height; y++)
        {
            png_read_row(png, row.data(), NULL);
            for (int x = 0; x < width * 3; x += 3)
            {
                image[y][x / 3][0] = row[x];
                image[y][x / 3][1] = row[x + 1];
                image[y][x / 3][2] = row[x + 2];
            }
        }

        png_destroy_read_struct(&png, &info, NULL);
        fclose(fp);

        return true;
    }

private:
    std::string filename_;
};