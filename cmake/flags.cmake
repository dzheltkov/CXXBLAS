if (CMAKE_CXX_COMPILER)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS_DEBUG "-Og -g -Wall -Wextra -pedantic")
        if (CXXBLAS_ASAN)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitiza-recover")
        endif()
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel" OR CMAKE_CXX_COMPILER_ID STREQUAL "IntelLLVM")
        if (UNIX)
            set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall")
        elseif(WIN32)
            set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O3 /fp:fast=2")
        endif()
    endif()
endif()

if (CMAKE_Fortran_COMPILER)
    if (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_Fortran_FLAGS_DEBUG "-Og -g -Wall -Wextra -pedantic")
        if (CXXBLAS_ASAN)
            set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fsanitize=address -fsanitiza-recover")
        endif()
        if (CXXBLAS_FCHECK)
            set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fcheck=all")
        endif()
    elseif (CMAKE_Fortran_COMPILER_ID STREQUAL "Intel" OR CMAKE_Fortran_COMPILER_ID STREQUAL "IntelLLVM")
        if (UNIX)
            set(CMAKE_Fortran_FLAGS_DEBUG "-O0 -g -warn all")
            if (CXXBLAS_FCHECK)
                set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -check all")
            endif()
        elseif(WIN32)
            set (CMAKE_Fortran_FLAGS_RELEASE "${CMAKE_Fortran_FLAGS_RELEASE} /O3 /fp:fast=2")
        endif()
    endif()
endif()

if (CMAKE_C_COMPILER)
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_C_FLAGS_DEBUG "-Og -g -Wall -Wextra -pedantic")
        if (CXXBLAS_ASAN)
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitiza-recover")
        endif()
    elseif (CMAKE_C_COMPILER_ID STREQUAL "Intel" OR CMAKE_C_COMPILER_ID STREQUAL "IntelLLVM")
        if (UNIX)
            set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall")
        elseif(WIN32)
            set (CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O3 /fp:fast=2")
        endif()
    endif()
endif()
