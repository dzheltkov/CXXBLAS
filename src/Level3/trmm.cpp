#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define strmm BLAS_GLOBAL(strmm,STRMM)
#define dtrmm BLAS_GLOBAL(dtrmm,DTRMM)
#define ctrmm BLAS_GLOBAL(ctrmm,CTRMM)
#define ztrmm BLAS_GLOBAL(ztrmm,ZTRMM)

extern "C"
{
    void strmm(const char &Side,
               const char &UpperLower,
               const char &transpose,
               const char &diagonal,
               const CXXBLAS_INT &n,
               const CXXBLAS_INT &m,
               const float *A, const CXXBLAS_INT &ldA,
               float *B, const CXXBLAS_INT &ldB);

    void dtrmm(const char &Side,
               const char &UpperLower,
               const char &transpose,
               const char &diagonal,
               const CXXBLAS_INT &n,
               const CXXBLAS_INT &m,
               const double *A, const CXXBLAS_INT &ldA,
               double *B, const CXXBLAS_INT &ldB);

    void ctrmm(const char &Side,
               const char &UpperLower,
               const char &transpose,
               const char &diagonal,
               const CXXBLAS_INT &n,
               const CXXBLAS_INT &m,
               const std::complex<float> *A, const CXXBLAS_INT &ldA,
               std::complex<float> *B, const CXXBLAS_INT &ldB);

    void ztrmm(const char &Side,
               const char &UpperLower,
               const char &transpose,
               const char &diagonal,
               const CXXBLAS_INT &n,
               const CXXBLAS_INT &m,
               const std::complex<double> *A, const CXXBLAS_INT &ldA,
               std::complex<double> *B, const CXXBLAS_INT &ldB);
}

namespace BLAS
{
    void trmm(const char &Side,
              const char &UpperLower,
              const char &trans,
              const char &Diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const float *A, const CXXBLAS_INT &ldA,
              float *B, const CXXBLAS_INT &ldB)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        strmm(Side, UpperLower, Trans, Diagonal, n, m, A, ldA, B, ldB);
    }

    void trmm(const char &Side,
              const char &UpperLower,
              const char &trans,
              const char &Diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const double *A, const CXXBLAS_INT &ldA,
              double *B, const CXXBLAS_INT &ldB)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        dtrmm(Side, UpperLower, Trans, Diagonal, n, m, A, ldA, B, ldB);
    }

    void trmm(const char &Side,
              const char &UpperLower,
              const char &Transpose,
              const char &Diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              std::complex<float> *B, const CXXBLAS_INT &ldB)
    {
        ctrmm(Side, UpperLower, Transpose, Diagonal, n, m, A, ldA, B, ldB);
    }

    void trmm(const char &Side,
              const char &UpperLower,
              const char &Transpose,
              const char &Diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              std::complex<double> *B, const CXXBLAS_INT &ldB)
    {
        ztrmm(Side, UpperLower, Transpose, Diagonal, n, m, A, ldA, B, ldB);
    }
}
