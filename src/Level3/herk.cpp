#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define sherk BLAS_GLOBAL(ssyrk,SSYRK)
#define dherk BLAS_GLOBAL(dsyrk,DSYRK)
#define cherk BLAS_GLOBAL(cherk,CHERK)
#define zherk BLAS_GLOBAL(zherk,ZHERK)

extern "C"
{
    void sherk(const char &,
               const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const float &,
               const float *, const CXXBLAS_INT &,
               const float &,
               float *, const CXXBLAS_INT &);

    void dherk(const char &,
               const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const double &,
               const double *, const CXXBLAS_INT &,
               const double &,
               double *, const CXXBLAS_INT &);

    void cherk(const char &,
               const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const float &,
               const std::complex<float> *, const CXXBLAS_INT &,
               const float &,
               std::complex<float> *, const CXXBLAS_INT &);

    void zherk(const char &,
               const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const double &,
               const std::complex<double> *, const CXXBLAS_INT &,
               const double &,
               std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    void herk(const char &transA,
              const char &transB,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const float &alpha,
              const float *A, const CXXBLAS_INT &ldA,
              const float &beta,
              float *C, const CXXBLAS_INT &ldC)
    {
        char UpperLower = transA;
        if (UpperLower == 'C' || UpperLower == 'c') {
            UpperLower = 'T';
        }
        char TransA = transB;
        if (TransA == 'C' || TransA == 'c') {
            TransA = 'T';
        }
        sherk(UpperLower, TransA, n, k, alpha, A, ldA, beta, C, ldC);
    }

    void herk(const char &transA,
              const char &transB,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const double &alpha,
              const double *A, const CXXBLAS_INT &ldA,
              const double &beta,
              double *C, const CXXBLAS_INT &ldC)
    {
        char UpperLower = transA;
        if (UpperLower == 'C' || UpperLower == 'c') {
            UpperLower = 'T';
        }
        char TransA = transB;
        if (TransA == 'C' || TransA == 'c') {
            TransA = 'T';
        }
        dherk(UpperLower, TransA, n, k, alpha, A, ldA, beta, C, ldC);
    }

    void herk(const char &UpperLower,
              const char &TransA,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const float &alpha,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              const float &beta,
              std::complex<float> *C, const CXXBLAS_INT &ldC)
    {
        cherk(UpperLower, TransA, n, k, alpha, A, ldA, beta, C, ldC);
    }

    void herk(const char &UpperLower,
              const char &TransA,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const double &alpha,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              const double &beta,
              std::complex<double> *C, const CXXBLAS_INT &ldC)
    {
        zherk(UpperLower, TransA, n, k, alpha, A, ldA, beta, C, ldC);
    }
}
