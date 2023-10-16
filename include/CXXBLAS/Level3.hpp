#ifndef CXXBLAS_LEVEL3_HPP
#define CXXBLAS_LEVEL3_HPP
namespace BLAS
{
    template <class DataType>
        void gemm(const char &TransA,
                  const char &TransB,
                  const CXXBLAS_INT &m, const CXXBLAS_INT &n,
                  const CXXBLAS_INT &k,
                  const DataType &alpha,
                  const DataType *A, const CXXBLAS_INT &ldA,
                  const DataType *B, const CXXBLAS_INT &ldB,
                  const DataType &beta,
                  DataType *C, const CXXBLAS_INT &ldC);
/*
    template <class DataType>
        void trsm(const char &Side,
                  const char &UpperLower,
                  const char &transpose,
                  const char &diagonal,
                  const CXXBLAS_INT &n,
                  const DataType *A, const CXXBLAS_INT &ldA,
                  DataType *B, const CXXBLAS_INT &ldB);
                  */
}
#include "Level3/gemm.hpp"
//#include "Level3/trsm.hpp"
#endif
