cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 11)
project(CXXBLAS VERSION 0.1 DESCRIPTION "C++ interface to BLAS functions" LANGUAGES CXX)

include(cmake/common.cmake)

include(cmake/options.cmake)

include(cmake/flags.cmake)

configure_file(CXXBLAS_config.h.in ${PROJECT_BINARY_DIR}/include/CXXBLAS_config.h)

if (CXXBLAS_BLAS)
    add_subdirectory(src)
endif()

if (CXXBLAS_TEMPLATES)
    find_package(OpenMP COMPONENTS CXX REQUIRED)
    if (NOT CXXBLAS_BLAS)
        add_library(cxxblas INTERFACE)
    endif()
    target_link_libraries(cxxblas OpenMP::OpenMP_CXX)
endif()

target_compile_definitions(cxxblas PRIVATE $<$<CONFIG:Debug>:DEBUG>)
add_library(BLAS::BLAS_CXX ALIAS cxxblas)

include(cmake/install.cmake)
