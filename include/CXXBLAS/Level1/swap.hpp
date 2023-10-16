#ifndef CXXBLAS_LEVEL1_SWAP_HPP
#define CXXBLAS_LEVEL1_SWAP_HPP
namespace BLAS
{
    // Swaps vectors x and y
    template <class DataType>
        void swap(const CXXBLAS_INT &n,
                  DataType *x, const CXXBLAS_INT &incx,
                  DataType *y, const CXXBLAS_INT &incy)
        {
#pragma omp parallel for
            for (CXXBLAS_INT i = 0; i < n; i++)
            {
                std::swap(x[i * incx], y[i * incy]);
            }
        }
}

#endif
