subroutine cdotc_stackreturn(r, n, x, incx, y, incy) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx, incy
    complex(C_FLOAT_COMPLEX) r, x(*), y(*), cdotc
    external cdotc
    r = cdotc(n, x, incx, y, incy)
end subroutine

subroutine cdotu_stackreturn(r, n, x, incx, y, incy) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx, incy
    complex(C_FLOAT_COMPLEX) r, x(*), y(*), cdotu
    external cdotu
    r = cdotu(n, x, incx, y, incy)
end subroutine

subroutine zdotc_stackreturn(r, n, x, incx, y, incy) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx, incy
    complex(C_DOUBLE_COMPLEX) r, x(*), y(*), zdotc
    external zdotc
    r = zdotc(n, x, incx, y, incy)
end subroutine

subroutine zdotu_stackreturn(r, n, x, incx, y, incy) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx, incy
    complex(C_DOUBLE_COMPLEX) r, x(*), y(*), zdotu
    external zdotu
    r = zdotu(n, x, incx, y, incy)
end subroutine
