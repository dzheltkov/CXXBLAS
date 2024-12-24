# C++ interface and template implementation of BLAS library

## Contents

0. [Minimal prerequisites](#min-prereq)
1. [Quick start](#quick-start)

____

## Minimal prerequisites
- CMake version 3.22 or newer.
- C++-11 compiler with OpenMP support.
- To use BLAS interface also BLAS implementation and interoperable C and Fortran compilers are required.

____

## Quick start

C++ Library can be build and installed using the following commands:
```
mkdir build
cd build
cmake ..
cmake --build .
cmake --install . --prefix /path/to/install
```

For detailed information about installation refer INSTALL.md

## Usage
`main.cpp`:
```cpp
#include <iostream>
#include <vector>
#include "CXXBLAS.hpp"

int main(){
  int n = 10;
  std::vector<double> v(n, 1);
  std::cout << BLAS::nrm2(n, v.data(), 1) << std::endl;
}
```

`CmakeLists.txt`:
```cmake
cmake_minimum_required(VERSION 3.20)
project(TEST_CXXBLAS)

find_package(CXXBLAS REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE CXXBLAS::cxxblas)
```
