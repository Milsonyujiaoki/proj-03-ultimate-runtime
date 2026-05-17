#ifndef LIBFT_ALGO_SEARCH_H
# define LIBFT_ALGO_SEARCH_H

# include "../core/types.h"


/*
** =========================================================
** Search algorithms
**
** All operate on contiguous arrays via (void *, elem_size).
** Return values conform to t_isize:
**   >= 0         — index of the found element
**   FT_ENOTFOUND — element not found
** =========================================================
*/

/*
** Binary search on a sorted contiguous array.
**
**   arr       — pointer to the first element
**   count     — number of elements
**   elem_size — sizeof each element
**   key       — pointer to the value to find
**   cmp       — comparator (same sign convention as qsort)
**
** Complexity: O(log n)
** Precondition: array must be sorted in ascending order by cmp.
*/
t_isize ft_bsearch(const void *arr, t_usize count, t_usize elem_size,
            const void *key, t_cmp_fn cmp);

/*
** Linear search on any contiguous array.
**
** Applies pred(element, ctx) to each element in order.
** Returns the index of the first match.
**
** Complexity: O(n)
** No ordering precondition.
*/
t_isize ft_lsearch(const void *arr, t_usize count, t_usize elem_size,
            t_pred_fn pred, const void *ctx);

#endif /* LIBFT_ALGO_SEARCH_H */
