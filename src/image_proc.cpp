
#include "Plan_1d_FFT.hpp"
#include "Plan_2d_FFT.hpp"
#include "PNG_Reader.hpp"
#include <iostream>

int main()
{
   std::cout << "This app should perform a convolution on the original Lenna image\n";

   std::string filename = "Lenna.png";
   PNG_Reader pngReader(filename);
   std::vector<std::vector<std::vector<int>>> image;

   if (pngReader.read(image))
   {
      // Access image data here
      for (int y = 0; y < image.size(); y++)
      {
         for (int x = 0; x < image[y].size(); x++)
         {
            std::cout << "RGB value at (" << x << ", " << y << "): ";
            std::cout << image[y][x][0] << ", " << image[y][x][1] << ", " << image[y][x][2] << std::endl;
         }
      }
   }

   return 0;
}