#ifndef CXXBLAS_LEVEL3_TRSM_HPP
#define CXXBLAS_LEVEL3_TRSM_HPP
#include <BLAS.hpp>
namespace BLAS
{
    // Solution of the triangular system
    template <class DataType>
    void trsm(const char &Side,
              const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const DataType *A, const CXXBLAS_INT &ldA,
              DataType *B, const CXXBLAS_INT &ldB);
}

#endif
