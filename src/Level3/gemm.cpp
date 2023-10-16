#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define sgemm BLAS_GLOBAL(sgemm,SGEMM)
#define dgemm BLAS_GLOBAL(dgemm,DGEMM)
#define cgemm BLAS_GLOBAL(cgemm,CGEMM)
#define zgemm BLAS_GLOBAL(zgemm,ZGEMM)

extern "C"
{
    void sgemm(const char &,
               const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const float &,
               const float *, const CXXBLAS_INT &,
               const float *, const CXXBLAS_INT &,
               const float &,
               float *, const CXXBLAS_INT &);

    void dgemm(const char &,
               const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const double &,
               const double *, const CXXBLAS_INT &,
               const double *, const CXXBLAS_INT &,
               const double &,
               double *, const CXXBLAS_INT &);

    void cgemm(const char &,
               const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const std::complex<float> &,
               const std::complex<float> *, const CXXBLAS_INT &,
               const std::complex<float> *, const CXXBLAS_INT &,
               const std::complex<float> &,
               std::complex<float> *, const CXXBLAS_INT &);

    void zgemm(const char &,
               const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const std::complex<double> &,
               const std::complex<double> *, const CXXBLAS_INT &,
               const std::complex<double> *, const CXXBLAS_INT &,
               const std::complex<double> &,
               std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    void gemm(const char &transA,
              const char &transB,
              const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const float &alpha,
              const float *A, const CXXBLAS_INT &ldA,
              const float *B, const CXXBLAS_INT &ldB,
              const float &beta,
              float *C, const CXXBLAS_INT &ldC)
    {
        char TransA = transA;
        if (TransA == 'C' || TransA == 'c') {
            TransA = 'T';
        }
        char TransB = transB;
        if (TransB == 'C' || TransB == 'c') {
            TransB = 'T';
        }
        sgemm(TransA, TransB, m, n, k, alpha, A, ldA, B, ldB, beta, C, ldC);
    }

    void gemm(const char &transA,
              const char &transB,
              const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const double &alpha,
              const double *A, const CXXBLAS_INT &ldA,
              const double *B, const CXXBLAS_INT &ldB,
              const double &beta,
              double *C, const CXXBLAS_INT &ldC)
    {
        char TransA = transA;
        if (TransA == 'C' || TransA == 'c') {
            TransA = 'T';
        }
        char TransB = transB;
        if (TransB == 'C' || TransB == 'c') {
            TransB = 'T';
        }
        dgemm(TransA, TransB, m, n, k, alpha, A, ldA, B, ldB, beta, C, ldC);
    }

    void gemm(const char &TransA,
              const char &TransB,
              const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const std::complex<float> &alpha,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              const std::complex<float> *B, const CXXBLAS_INT &ldB,
              const std::complex<float> &beta,
              std::complex<float> *C, const CXXBLAS_INT &ldC)
    {
        cgemm(TransA, TransB, m, n, k, alpha, A, ldA, B, ldB, beta, C, ldC);
    }

    void gemm(const char &TransA,
              const char &TransB,
              const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const std::complex<double> &alpha,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              const std::complex<double> *B, const CXXBLAS_INT &ldB,
              const std::complex<double> &beta,
              std::complex<double> *C, const CXXBLAS_INT &ldC)
    {
        zgemm(TransA, TransB, m, n, k, alpha, A, ldA, B, ldB, beta, C, ldC);
    }
}
