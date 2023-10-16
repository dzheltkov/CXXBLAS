#ifndef CXXBLAS_LEVEL2_GEMV_HPP
#define CXXBLAS_LEVEL2_GEMV_HPP
#include <omp.h>
namespace BLAS
{
    //General dense matrix by vector multiplication:
    //       y = \alpha A x + \beta y
    template <class DataType>
        void gemv(const char &transpose,
                const CXXBLAS_INT &m, const CXXBLAS_INT &n,
                const DataType &alpha,
                const DataType *A, const CXXBLAS_INT &ldA,
                const DataType *x, const CXXBLAS_INT &incx,
                const DataType &beta,
                DataType *y, const CXXBLAS_INT &incy)
        {
#pragma omp parallel
            {
                if (transpose == 'n' || transpose == 'N')
                {
                    CXXBLAS_INT P = omp_get_num_threads();
                    CXXBLAS_INT p = omp_get_thread_num();
                    CXXBLAS_INT sm = (m / P) * p + std::min(p, m % P);
                    CXXBLAS_INT em = (m / P) * (p + 1) + std::min(p + 1, m % P);
                    if (beta == DataType(0.0))
                    {
                        for (CXXBLAS_INT i = sm; i < em; i++)
                        {
                            y[i * incy] = DataType(0.0);
                        }
                    }
                    else
                    {
                        for (CXXBLAS_INT i = sm; i < em; i++)
                        {
                            y[i * incy] *= beta;
                        }
                    }
                    for (CXXBLAS_INT j = 0; j < n; j++)
                    {
                        for (CXXBLAS_INT i = sm; i < em; i++)
                        {
                            y[i * incy] += alpha * A[i + ldA * j] * x[j * incx];
                        }
                    }
                }
                else if (transpose == 't' || transpose == 'T')
                {
                    if (beta == DataType(0.0))
                    {
#pragma omp for
                        for (CXXBLAS_INT i = 0; i < n; i++)
                        {
                            y[i * incy] = DataType(0.0);
                        }
                    }
#pragma omp for
                    for (CXXBLAS_INT j = 0; j < n; j++)
                    {
                        y[j * incy] *= beta;
                        for (CXXBLAS_INT i = 0; i < m; i++)
                        {
                            y[j * incy] += alpha * A[i + j * m] * x[i * incx];
                        }
                    }
                }
                else if (transpose == 'c' || transpose == 'C')
                {
                    if (beta == DataType(0.0))
                    {
#pragma omp for
                        for (CXXBLAS_INT i = 0; i < n; i++)
                        {
                            y[i * incy] = DataType(0.0);
                        }
                    }
#pragma omp for
                    for (CXXBLAS_INT j = 0; j < n; j++)
                    {
                        y[j * incy] *= beta;
                        for (CXXBLAS_INT i = 0; i < m; i++)
                        {
                            y[j * incy] += alpha * std::conj(A[i + j * m]) * x[i * incx];
                        }
                    }
                }
            }
        }
}

#endif
