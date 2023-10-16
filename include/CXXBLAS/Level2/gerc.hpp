#ifndef CXXBLAS_LEVEL2_GERC_HPP
#define CXXBLAS_LEVEL2_GERC_HPP
namespace BLAS
{
    //General dense matrix rank-1 update with conjugation of second vector:
    //       A = \alpha x y^H + A
    template <class DataType>
        void gerc(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
                const DataType &alpha,
                const DataType *x, const CXXBLAS_INT &incx,
                const DataType *y, const CXXBLAS_INT &incy,
                DataType *A, const CXXBLAS_INT &ldA)
        {
#pragma omp parallel for
            for (CXXBLAS_INT j = 0; j < n; j++)
            {
                DataType alpha_y = alpha * std::conj(y[j * incy]);
                for (CXXBLAS_INT i = 0; i < m; i++)
                {
                    A[i + j * ldA] += x[i * incx] * alpha_y;
                }
            }
        }
}

#endif
