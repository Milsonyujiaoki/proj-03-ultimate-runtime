#ifndef LIBFT_MACROS_H
# define LIBFT_MACROS_H

# include "compiler.h"
# include "types.h"

/*
** =========================================================
** Arithmetic utilities
** =========================================================
*/
# define LIBFT_MIN(a, b)          ((a) < (b) ? (a) : (b))
# define LIBFT_MAX(a, b)          ((a) > (b) ? (a) : (b))
# define LIBFT_ABS(a)             ((a) < 0 ? -(a) : (a))
# define LIBFT_CLAMP(v, lo, hi)   (LIBFT_MAX((lo), LIBFT_MIN((v), (hi))))

/*
** =========================================================
** Array and struct utilities
** =========================================================
*/

/* Number of elements in a stack-allocated array */
# define LIBFT_ARRLEN(arr)   (sizeof(arr) / sizeof((arr)[0]))

/* Byte offset of a struct member */
# define LIBFT_OFFSETOF(type, member) \
    ((t_usize)((t_byte *)&((type *)0)->member - (t_byte *)0))

/* Get pointer to enclosing struct from member pointer */
# define LIBFT_CONTAINER_OF(ptr, type, member) \
    ((type *)((t_byte *)(ptr) - LIBFT_OFFSETOF(type, member)))

/*
** =========================================================
** Alignment utilities
** =========================================================
** Require: align must be a power of two.
*/
# define LIBFT_ALIGN_UP(n, align) \
    (((t_usize)(n) + (t_usize)(align) - 1) & ~((t_usize)(align) - 1))
# define LIBFT_ALIGN_DOWN(n, align) \
    ((t_usize)(n) & ~((t_usize)(align) - 1))
# define LIBFT_IS_ALIGNED(n, align) \
    (((t_usize)(n) & ((t_usize)(align) - 1)) == 0)
# define LIBFT_IS_POW2(n) \
    ((n) != 0 && (((n) & ((n) - 1)) == 0))

/*
** =========================================================
** Bit manipulation
** =========================================================
*/
# define LIBFT_BIT(n)            (1ULL << (n))
# define LIBFT_BIT_SET(v, n)     ((v) |=  LIBFT_BIT(n))
# define LIBFT_BIT_CLEAR(v, n)   ((v) &= ~LIBFT_BIT(n))
# define LIBFT_BIT_TOGGLE(v, n)  ((v) ^=  LIBFT_BIT(n))
# define LIBFT_BIT_CHECK(v, n)   (!!((v) & LIBFT_BIT(n)))

/*
** =========================================================
** Miscellaneous
** =========================================================
*/

/* Suppress unused-variable warnings at call-sites */
# define LIBFT_UNUSED_VAR(x)  ((void)(x))

/* Compile-time assertion (C11) */
# ifdef LIBFT_HAS_C11
#  define LIBFT_STATIC_ASSERT(expr, msg)  _Static_assert(expr, msg)
# else
#  define LIBFT_STATIC_ASSERT(expr, msg)  \
    typedef char _libft_sa_##__LINE__[(expr) ? 1 : -1]
# endif

/* Token stringification */
# define LIBFT_STRINGIFY(x)  #x
# define LIBFT_TOSTRING(x)   LIBFT_STRINGIFY(x)

/* Token concatenation */
# define LIBFT_CONCAT(a, b)  a##b

/* Swap two values of the same type using a temp variable */
# define LIBFT_SWAP(T, a, b) \
    do { T _tmp = (a); (a) = (b); (b) = _tmp; } while (0)

#endif /* LIBFT_MACROS_H */
