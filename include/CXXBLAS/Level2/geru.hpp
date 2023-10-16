#ifndef CXXBLAS_LEVEL2_GERU_HPP
#define CXXBLAS_LEVEL2_GERU_HPP
namespace BLAS
{
    //General dense matrix rank-1 update WITHOUT conjugation of second vector:
    //       A = \alpha x y^T + A
    template <class DataType>
    void geru(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const DataType &alpha,
              const DataType *x, const CXXBLAS_INT &incx,
              const DataType *y, const CXXBLAS_INT &incy,
              DataType *A, const CXXBLAS_INT &ldA)
    {
#pragma omp parallel for
        for (CXXBLAS_INT j = 0; j < n; j++)
        {
            DataType alpha_y = alpha * y[j * incy];
            for (CXXBLAS_INT i = 0; i < m; i++)
            {
                A[i + j * ldA] += x[i * incx] * alpha_y;
            }
        }
    }
}

#endif
