## Contents

0. [Prerequisites](#prereq)
1. [Compilation](#compilation)
2. [Installation](#install)
____

## Prerequisites

Minimal prerequisites includes:
- CMake version 3.22 or newer.
- C++-17 compiler with OpenMP support.
- To use BLAS interface also BLAS implementation and interoperable C and Fortran compilers are required.

## Compilation


Library can be built using the following commands:
```
mkdir build
cd build
cmake ..
cmake --build .
```

Template implementation of BLAS functions can be enabled using `-DCXXBLAS_TEMPLATES=On` during CMake project configuration.

64-bit integer for BLAS can be enabled using `-DCXXBLAS_64BIT=On` during CMake project configuration.

Address sanitizers can be enabled using `-DCXXBLAS_ASAN=On` during CMake project configuration.

Fortran checks can be enabled using `-DCXXBLAS_FCHECK=On` during CMake project configuration.

Interface to BLAS implementation can be disabled using `-DCXXBLAS_BLAS=Off` during CMake project configuration.

At leas one of the `CXXBLAS_BLAS` and `CXXBLAS_TEMPLATES` should be set on.

For example, both template implementation and interface to BLAS implementation can be included using
```
mkdir build
cd build
cmake -DBUILD_TEMPLATES=On ..
cmake --build .
```

## Instalation
Library can be installed using the following command in build directory
```
cmake --prefix=<path> .
```
