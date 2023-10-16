#ifndef CXXBLAS_LEVEL2_TPSV_HPP
#define CXXBLAS_LEVEL2_TPSV_HPP
namespace BLAS
{
    // Solution of the triangular system supplied in packed form
    template <class DataType>
        void tpsv(const char &UpperLower,
                  const char &transpose,
                  const char &diagonal,
                  const CXXBLAS_INT &n,
                  const DataType *A,
                  DataType *x, const CXXBLAS_INT &incx)
        {
            bool unit_diagonal = (diagonal == 'U' || diagonal == 'u');
            if (UpperLower == 'u' || UpperLower == 'U')
            {
                if (transpose == 'n' || transpose == 'N')
                {
                    A += n * (n + 1) / 2;
                    DataType *ix = x + n * incx;
                    for (CXXBLAS_INT i = n; i > 0; i--)
                    {
                        ix -= incx;
                        A--;
                        if (!unit_diagonal)
                        {
                            *ix /= *A;
                        }
                        DataType *jx = ix;
                        for (CXXBLAS_INT j = i - 1; j > 0; j--)
                        {
                            A--;
                            jx -= incx;
                            *jx -= *A * *ix;
                        }
                    }
                }
                else if(transpose == 't' || transpose == 'T')
                {
                    DataType *ix = x;
                    for (CXXBLAS_INT i = 0; i < n; i++)
                    {
                        const DataType *jx = x;
                        for (CXXBLAS_INT j = 0; j < i; j++)
                        {
                            *ix -= *A * *jx;
                            A++;
                            jx += incx;
                        }
                        if (!unit_diagonal)
                        {
                            *ix /= *A;
                        }
                        A++;
                        ix += incx;
                    }
                }
                else
                {
                    DataType *ix = x;
                    for (CXXBLAS_INT i = 0; i < n; i++)
                    {
                        const DataType *jx = x;
                        for (CXXBLAS_INT j = 0; j < i; j++)
                        {
                            *ix -= std::conj(*A) * *jx;
                            A++;
                            jx += incx;
                        }
                        if (!unit_diagonal)
                        {
                            *ix /= std::conj(*A);
                        }
                        A++;
                        ix += incx;
                    }
                }
            }
            else
            {
                if (transpose == 'n' || transpose == 'N')
                {
                    DataType *ix = x;
                    for (CXXBLAS_INT i = 0; i < n; i++)
                    {
                        if (!unit_diagonal)
                        {
                            *ix /= *A;
                        }
                        A++;
                        DataType *jx = ix + incx;
                        for (CXXBLAS_INT j = i + 1; j < n; j++)
                        {
                            *jx -= *A * *ix;
                            A++;
                            jx += incx;
                        }
                    }
                }
                else if(transpose == 't' || transpose == 'T')
                {
                    A += n * (n + 1) / 2;
                    DataType *ix = x + n * incx;
                    for (CXXBLAS_INT i = n; i > 0; i--)
                    {
                        ix -= incx;
                        const DataType *jx = x + n * incx;
                        for (CXXBLAS_INT j = n; j > i; j--)
                        {
                            A--;
                            jx -= incx;
                            *ix -= *A * *jx;
                        }
                        A--;
                        if (!unit_diagonal)
                        {
                            *ix /= *A;
                        }
                    }
                }
                else if(transpose == 'c' || transpose == 'C')
                {
                    A += n * (n + 1) / 2;
                    DataType *ix = x + n * incx;
                    for (CXXBLAS_INT i = n; i > 0; i--)
                    {
                        ix -= incx;
                        const DataType *jx = x + n * incx;
                        for (CXXBLAS_INT j = n; j > i; j--)
                        {
                            A--;
                            jx -= incx;
                            *ix -= std::conj(*A) * *jx;
                        }
                        A--;
                        if (!unit_diagonal)
                        {
                            *ix /= std::conj(*A);
                        }
                    }
                }
            }
        }
}

#endif
