#ifndef CXXBLAS_LEVEL1_SCAL_HPP
#define CXXBLAS_LEVEL1_SCAL_HPP
namespace BLAS
{
    // Scales strided vector
    template <class DataType>
        void scal(const CXXBLAS_INT &n,
                  const DataType &alpha,
                  DataType *x, const CXXBLAS_INT &incx)
        {
#pragma omp parallel for
            for (CXXBLAS_INT i = 0; i < n; i++)
            {
                x[i * incx] *= alpha;
            }
        }
}

#endif
