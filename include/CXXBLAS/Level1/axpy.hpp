#ifndef CXXBLAS_LEVEL1_AXPY_HPP
#define CXXBLAS_LEVEL1_AXPY_HPP
namespace BLAS
{
    // Adds x scaled by alpha to y:
    //       y = \alpha x + y
    template <class DataType>
        void axpy(const CXXBLAS_INT &n,
                  const DataType &alpha,
                  const DataType *x, const CXXBLAS_INT &incx,
                  DataType *y, const CXXBLAS_INT &incy)
        {
#pragma omp parallel for
            for (CXXBLAS_INT i = 0; i < n; i++)
            {
                y[i * incy] += x[i * incx] * alpha;
            }
        }
}

#endif
