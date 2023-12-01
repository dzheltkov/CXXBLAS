subroutine snrm2_stackreturn(r, n, x, incx) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx
    real(C_FLOAT) r, x(*), snrm2
    external snrm2
    r = snrm2(n, x, incx)
end subroutine

subroutine dnrm2_stackreturn(r, n, x, incx) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx
    real(C_DOUBLE) r, x(*), dnrm2
    external dnrm2
    r = dnrm2(n, x, incx)
end subroutine

subroutine scnrm2_stackreturn(r, n, x, incx) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx
    complex(C_FLOAT_COMPLEX) x(*)
    real(C_FLOAT) r, scnrm2
    external scnrm2
    r = scnrm2(n, x, incx)
end subroutine

subroutine dznrm2_stackreturn(r, n, x, incx) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx
    complex(C_DOUBLE_COMPLEX) x(*)
    real(C_DOUBLE) r, dznrm2
    external dznrm2
    r = dznrm2(n, x, incx)
end subroutine

subroutine sdot_stackreturn(r, n, x, incx, y, incy) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx, incy
    real(C_FLOAT) r, x(*), y(*), sdot
    external sdot
    r = sdot(n, x, incx, y, incy)
end subroutine

subroutine ddot_stackreturn(r, n, x, incx, y, incy) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    integer(C_INT) n, incx, incy
    real(C_DOUBLE) r, x(*), y(*), ddot
    external ddot
    r = ddot(n, x, incx, y, incy)
end subroutine

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
