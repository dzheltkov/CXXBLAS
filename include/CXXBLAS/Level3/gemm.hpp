#ifndef CXXBLAS_LEVEL3_GEMM_HPP
#define CXXBLAS_LEVEL3_GEMM_HPP
namespace BLAS
{
    // Matrix by matrix multiplication for general matrices
    template <class DataType>
        void gemm(const char &TransA,
                  const char &TransB,
                  const CXXBLAS_INT &m, const CXXBLAS_INT &n,
                  const CXXBLAS_INT &k,
                  const DataType &alpha,
                  const DataType *A, const CXXBLAS_INT &ldA,
                  const DataType *B, const CXXBLAS_INT &ldB,
                  const DataType &beta,
                  DataType *C, const CXXBLAS_INT &ldC)
        {
#pragma omp parallel for collapse(2)
            for (CXXBLAS_INT j = 0; j < n; j++)
            {
                for (CXXBLAS_INT i = 0; i < m; i++)
                {
                    C[i + j * m] *= beta;
                }
            }
            if ((TransA == 'N' || TransA == 'n') && (TransB == 'N' || TransB == 'n'))
            {
#pragma omp parallel for
                for (CXXBLAS_INT j = 0; j < n; j++)
                {
                    for (CXXBLAS_INT l = 0; l < k; l++)
                    {
                        for (CXXBLAS_INT i = 0; i < m; i++)
                        {
                            C[i + j * n] += A[i + l * ldA] * B[l + j * ldB];
                        }
                    }
                }
            }
            else if ((TransA == 'T' || TransA == 't') && (TransB == 'N' || TransB == 'n'))
            {
#pragma omp parallel for collapse(2)
                for (CXXBLAS_INT j = 0; j < n; j++)
                {
                    for (CXXBLAS_INT i = 0; i < m; i++)
                    {
                        for (CXXBLAS_INT l = 0; l < k; l++)
                        {
                            C[i + j * n] += A[i * ldA + l] * B[l + j * ldB];
                        }
                    }
                }
            }
            else if ((TransA == 'C' || TransA == 't') && (TransB == 'N' || TransB == 'n'))
            {
#pragma omp parallel for collapse(2)
                for (CXXBLAS_INT j = 0; j < n; j++)
                {
                    for (CXXBLAS_INT i = 0; i < m; i++)
                    {
                        for (CXXBLAS_INT l = 0; l < k; l++)
                        {
                            C[i + j * n] += std::conj(A[i * ldA + l]) * B[l + j * ldB];
                        }
                    }
                }
            }
            else if ((TransA == 'N' || TransA == 'N') && (TransB == 'T' || TransB == 't'))
            {
#pragma omp parallel for collapse(2)
                for (CXXBLAS_INT j = 0; j < n; j++)
                {
                    for (CXXBLAS_INT l = 0; l < k; l++)
                    {
                        for (CXXBLAS_INT i = 0; i < m; i++)
                        {
                            C[i + j * n] += A[i + l * ldA] * B[l * ldB + j];
                        }
                    }
                }
            }
            else if ((TransA == 'T' || TransA == 't') && (TransB == 'T' || TransB == 't'))
            {
#pragma omp parallel for collapse(2)
                for (CXXBLAS_INT j = 0; j < n; j++)
                {
                    for (CXXBLAS_INT i = 0; i < m; i++)
                    {
                        for (CXXBLAS_INT l = 0; l < k; l++)
                        {
                            C[i + j * n] += A[i * ldA + l] * B[l * ldB + j];
                        }
                    }
                }
            }
            else if ((TransA == 'C' || TransA == 'c') && (TransB == 'T' || TransB == 't'))
            {
#pragma omp parallel for collapse(2)
                for (CXXBLAS_INT j = 0; j < n; j++)
                {
                    for (CXXBLAS_INT i = 0; i < m; i++)
                    {
                        for (CXXBLAS_INT l = 0; l < k; l++)
                        {
                            C[i + j * n] += std::conj(A[i * ldA + l]) * B[l * ldB + j];
                        }
                    }
                }
            }
            else if ((TransA == 'N' || TransA == 'N') && (TransB == 'C' || TransB == 'c'))
            {
#pragma omp parallel for
                for (CXXBLAS_INT j = 0; j < n; j++)
                {
                    for (CXXBLAS_INT l = 0; l < k; l++)
                    {
                        for (CXXBLAS_INT i = 0; i < m; i++)
                        {
                            C[i + j * n] += A[i + l * ldA] * std::conj(B[l * ldB + j]);
                        }
                    }
                }
            }
            else if ((TransA == 'T' || TransA == 't') && (TransB == 'C' || TransB == 'c'))
            {
#pragma omp parallel for collapse(2)
                for (CXXBLAS_INT j = 0; j < n; j++)
                {
                    for (CXXBLAS_INT i = 0; i < m; i++)
                    {
                        for (CXXBLAS_INT l = 0; l < k; l++)
                        {
                            C[i + j * n] += A[i * ldA + l] * std::conj(B[l * ldB + j]);
                        }
                    }
                }
            }
            else if ((TransA == 'C' || TransA == 'c') && (TransB == 'C' || TransB == 'c'))
            {
#pragma omp parallel for collapse(2)
                for (CXXBLAS_INT j = 0; j < n; j++)
                {
                    for (CXXBLAS_INT i = 0; i < m; i++)
                    {
                        for (CXXBLAS_INT l = 0; l < k; l++)
                        {
                            C[i + j * n] += std::conj(A[i * ldA + l]) * std::conj(B[l * ldB + j]);
                        }
                    }
                }
            }
        }
}

#endif
