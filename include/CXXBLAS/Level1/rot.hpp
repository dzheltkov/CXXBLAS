#ifndef CXXBLAS_LEVEL1_ROT_HPP
#define CXXBLAS_LEVEL1_ROT_HPP
namespace BLAS
{
    // Rotates strided vectors using provided cosine and sine value
    template <class DataType>
        void rot(const CXXBLAS_INT &n,
                 DataType *x, const CXXBLAS_INT &incx,
                 DataType *y, const CXXBLAS_INT &incy,
                 const decltype(std::abs(DataType())) &c, const DataType &s)
        {
#pragma omp parallel for
            for (CXXBLAS_INT i = 0; i < n; i++)
            {
                DataType t = c * x[i * incx] + s * y[i * incy];
                y[i * incy] = -std::conj(s) * x[i * incx] + c * y[i * incy];
                x[i * incx] = t;
            }
        }
}

#endif
