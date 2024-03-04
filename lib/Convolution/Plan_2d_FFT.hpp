// Example header file

#pragma once

#include <fftw3.h>
#include <vector>
#include <complex>
#include <omp.h>
#include <iostream>
#include <string>

class Plan_2d_FFT
{
public:
    Plan_2d_FFT(int rows, int cols) : numRows(rows), numCols(cols)
    {
        in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * numRows * numCols);
        out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * numRows * numCols);
        plan = fftw_plan_dft_2d(numRows, numCols, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    }

    ~Plan_2d_FFT()
    {
        fftw_destroy_plan(plan);
        fftw_free(in);
        fftw_free(out);
    }

    void execute()
    {
        fftw_execute(plan);
    }

    int getRows() const
    {
        return numRows;
    }

    int getCols() const
    {
        return numCols;
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
    int numRows;
    int numCols;
    fftw_complex *in;
    fftw_complex *out;
    fftw_plan plan;
};
