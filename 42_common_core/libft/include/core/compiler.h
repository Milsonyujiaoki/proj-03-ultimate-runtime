#ifndef LIBFT_COMPILER_H
# define LIBFT_COMPILER_H

/*
** =========================================================
** Compiler detection
** =========================================================
*/
# if defined(__GNUC__) && !defined(__clang__)
#  define LIBFT_COMPILER_GCC     1
# elif defined(__clang__)
#  define LIBFT_COMPILER_CLANG   1
# else
#  define LIBFT_COMPILER_UNKNOWN 1
# endif

/*
** =========================================================
** Function / symbol attributes
** =========================================================
*/
# if defined(LIBFT_COMPILER_GCC) || defined(LIBFT_COMPILER_CLANG)
#  define LIBFT_NORETURN      __attribute__((noreturn))
#  define LIBFT_NOINLINE      __attribute__((noinline))
#  define LIBFT_ALWAYS_INLINE __attribute__((always_inline)) inline
#  define LIBFT_PURE          __attribute__((pure))
#  define LIBFT_CONST_FN      __attribute__((const))
#  define LIBFT_MALLOC_ATTR   __attribute__((malloc))
#  define LIBFT_UNUSED        __attribute__((unused))
#  define LIBFT_PACKED        __attribute__((packed))
#  define LIBFT_ALIGNED(n)    __attribute__((aligned(n)))
#  define LIBFT_LIKELY(x)     __builtin_expect(!!(x), 1)
#  define LIBFT_UNLIKELY(x)   __builtin_expect(!!(x), 0)
# else
#  define LIBFT_NORETURN
#  define LIBFT_NOINLINE
#  define LIBFT_ALWAYS_INLINE inline
#  define LIBFT_PURE
#  define LIBFT_CONST_FN
#  define LIBFT_MALLOC_ATTR
#  define LIBFT_UNUSED
#  define LIBFT_PACKED
#  define LIBFT_ALIGNED(n)
#  define LIBFT_LIKELY(x)     (x)
#  define LIBFT_UNLIKELY(x)   (x)
# endif

/*
** =========================================================
** Symbol visibility
** =========================================================
*/
# if defined(LIBFT_COMPILER_GCC) || defined(LIBFT_COMPILER_CLANG)
#  define LIBFT_API    __attribute__((visibility("default")))
#  define LIBFT_HIDDEN __attribute__((visibility("hidden")))
# else
#  define LIBFT_API
#  define LIBFT_HIDDEN
# endif

/*
** =========================================================
** C standard version guards
** =========================================================
*/
# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#  define LIBFT_HAS_C11 1
# endif

# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#  define LIBFT_HAS_C99 1
# endif

#endif /* LIBFT_COMPILER_H */
