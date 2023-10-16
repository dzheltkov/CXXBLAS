#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define strsm BLAS_GLOBAL(strsm,STRSM)
#define dtrsm BLAS_GLOBAL(dtrsm,DTRSM)
#define ctrsm BLAS_GLOBAL(ctrsm,CTRSM)
#define ztrsm BLAS_GLOBAL(ztrsm,ZTRSM)

extern "C"
{
    void strsm(const char &Side,
               const char &UpperLower,
               const char &transpose,
               const char &diagonal,
               const CXXBLAS_INT &n,
               const float *A, const CXXBLAS_INT &ldA,
               float *B, const CXXBLAS_INT &ldB);

    void dtrsm(const char &Side,
               const char &UpperLower,
               const char &transpose,
               const char &diagonal,
               const CXXBLAS_INT &n,
               const double *A, const CXXBLAS_INT &ldA,
               double *B, const CXXBLAS_INT &ldB);

    void ctrsm(const char &Side,
               const char &UpperLower,
               const char &transpose,
               const char &diagonal,
               const CXXBLAS_INT &n,
               const std::complex<float> *A, const CXXBLAS_INT &ldA,
               std::complex<float> *B, const CXXBLAS_INT &ldB);

    void ztrsm(const char &Side,
               const char &UpperLower,
               const char &transpose,
               const char &diagonal,
               const CXXBLAS_INT &n,
               const std::complex<double> *A, const CXXBLAS_INT &ldA,
               std::complex<double> *B, const CXXBLAS_INT &ldB);
}

namespace BLAS
{
    void trsm(const char &Side,
              const char &UpperLower,
              const char &trans,
              const char &Diagonal,
              const CXXBLAS_INT &n,
              const float *A, const CXXBLAS_INT &ldA,
              float *B, const CXXBLAS_INT &ldB)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        strsm(Side, UpperLower, Trans, Diagonal, n, A, ldA, B, ldB);
    }

    void trsm(const char &Side,
              const char &UpperLower,
              const char &trans,
              const char &Diagonal,
              const CXXBLAS_INT &n,
              const double *A, const CXXBLAS_INT &ldA,
              double *B, const CXXBLAS_INT &ldB)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        dtrsm(Side, UpperLower, Trans, Diagonal, n, A, ldA, B, ldB);
    }

    void trsm(const char &Side,
              const char &UpperLower,
              const char &Transpose,
              const char &Diagonal,
              const CXXBLAS_INT &n,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              std::complex<float> *B, const CXXBLAS_INT &ldB)
    {
        ctrsm(Side, UpperLower, Transpose, Diagonal, n, A, ldA, B, ldB);
    }

    void trsm(const char &Side,
              const char &UpperLower,
              const char &Transpose,
              const char &Diagonal,
              const CXXBLAS_INT &n,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              std::complex<double> *B, const CXXBLAS_INT &ldB)
    {
        ztrsm(Side, UpperLower, Transpose, Diagonal, n, A, ldA, B, ldB);
    }
}
