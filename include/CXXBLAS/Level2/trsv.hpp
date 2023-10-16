#ifndef CXXBLAS_LEVEL2_TRSV_HPP
#define CXXBLAS_LEVEL2_TRSV_HPP
#include <BLAS.hpp>
namespace BLAS
{
    // Solution of the triangular system
    template <class DataType>
        void trsv(const char &UpperLower,
                  const char &transpose,
                  const char &diagonal,
                  const CXXBLAS_INT &n,
                  const DataType *A, const CXXBLAS_INT &ldA,
                  DataType *x, const CXXBLAS_INT &incx);
}

#endif
