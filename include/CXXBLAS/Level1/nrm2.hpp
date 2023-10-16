#ifndef CXXBLAS_LEVEL1_NRM2_HPP
#define CXXBLAS_LEVEL1_NRM2_HPP
namespace BLAS
{
    // Computes Euclidian (second, mean square) norm of strided vector x
    template <class DataType>
        decltype(std::abs(DataType())) nrm2(const CXXBLAS_INT &n,
                                            const DataType *x, const CXXBLAS_INT &incx)
        {
            typedef decltype(std::abs(DataType())) RealType;
            RealType r(0.0);
#pragma omp parallel
            {
                RealType lr(0.0);
#pragma omp for nowait
                for (CXXBLAS_INT i = 0; i < n; i++)
                {
                    lr += std::norm(x[i * incx]);
                }
#pragma omp critical
                {
                    r += lr;
                }
            }
            return std::sqrt(r);
        }
}

#endif
