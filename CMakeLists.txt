cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 11)
project(CXXBLAS VERSION 0.1 DESCRIPTION "C++ interface to BLAS functions" LANGUAGES CXX)

include(cmake/common.cmake)

include(cmake/options.cmake)

include(cmake/flags.cmake)

configure_file(CXXBLAS_config.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/CXXBLAS_config.h)
include(GNUInstallDirs)


if (CXXBLAS_BLAS)
    add_subdirectory(src)
endif()

if (CXXBLAS_TEMPLATES)
    find_package(OpenMP COMPONENTS CXX REQUIRED)
    if (NOT CXXBLAS_BLAS)
        add_library(cxxblas INTERFACE)
        target_link_libraries(cxxblas INTERFACE OpenMP::OpenMP_CXX)
        target_compile_definitions(cxxblas INTERFACE $<$<CONFIG:Debug>:DEBUG>)
        target_include_directories(cxxblas INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                     $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
                                                     $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
    else()
        target_link_libraries(cxxblas PUBLIC OpenMP::OpenMP_CXX)
    endif()
endif()

add_library(BLAS::BLAS_CXX ALIAS cxxblas)

include(cmake/install.cmake)
