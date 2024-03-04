// Example header file

#pragma once

#include <fftw3.h>
#include <vector>
#include <unordered_map>
#include <omp.h>
#include <iostream>
#include <string>

class Plan_1d_FFT
{
public:
    Plan_1d_FFT(int n) : size(n)
    {
        in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * size);
        out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * size);
        plan = fftw_plan_dft_1d(size, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    }

    ~Plan_1d_FFT()
    {
        fftw_destroy_plan(plan);
        fftw_free(in);
        fftw_free(out);
    }

    void execute()
    {
        fftw_execute(plan);
    }

    int getSize() const
    {
        return size;
    }

    fftw_complex *getIn() const
    {
        return in;
    }

    fftw_complex *getOut() const
    {
        return out;
    }

private:
    int size;
    fftw_complex *in;
    fftw_complex *out;
    fftw_plan plan;
};