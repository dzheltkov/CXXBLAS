#ifndef CXXBLAS_LEVEL1_COPY_HPP
#define CXXBLAS_LEVEL1_COPY_HPP
namespace BLAS
{
    // Copies strided vector x to strided vector y
    template <class DataType>
        void copy(const CXXBLAS_INT &n,
                  const DataType *x, const CXXBLAS_INT &incx,
                  DataType *y, const CXXBLAS_INT &incy)
        {
#pragma omp parallel for
            for (CXXBLAS_INT i = 0; i < n; i++)
            {
                y[i * incy] = x[i * incx];
            }
        }
}

#endif
