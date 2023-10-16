#ifndef CXXBLAS_LEVEL1_RSCAL_HPP
#define CXXBLAS_LEVEL1_RSCAL_HPP
namespace BLAS
{
    // Scales strided vector by real number (for real DataTypes is the same as scal)
    template <class DataType>
        void rscal(const CXXBLAS_INT &n,
                   const decltype(std::abs(DataType())) &alpha,
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
