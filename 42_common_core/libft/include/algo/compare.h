#ifndef LIBFT_ALGO_COMPARE_H
# define LIBFT_ALGO_COMPARE_H

# include "../core/types.h"

/*
** =========================================================
** Generic comparison functions
**
** All functions conform to the t_cmp_fn signature:
**   returns < 0  if  *a < *b
**   returns   0  if  *a == *b
**   returns > 0  if  *a > *b
**
** Designed to be passed directly to ft_qsort / ft_mergesort.
** =========================================================
*/

int     ft_cmp_int(const void *a, const void *b);
int     ft_cmp_uint(const void *a, const void *b);
int     ft_cmp_long(const void *a, const void *b);
int     ft_cmp_ulong(const void *a, const void *b);
int     ft_cmp_i64(const void *a, const void *b);
int     ft_cmp_u64(const void *a, const void *b);

/* Lexicographic comparison of NUL-terminated strings. */
int     ft_cmp_str(const void *a, const void *b);

/* Pointer value comparison (address order). */
int     ft_cmp_ptr(const void *a, const void *b);

/* Raw memory comparison — size bytes starting at a and b. */
int     ft_cmp_mem(const void *a, const void *b, t_usize size);

#endif /* LIBFT_ALGO_COMPARE_H */
