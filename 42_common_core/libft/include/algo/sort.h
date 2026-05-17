#ifndef LIBFT_ALGO_SORT_H
# define LIBFT_ALGO_SORT_H

# include "../core/types.h"
# include "../core/defs.h"

/*
** =========================================================
** Sorting algorithms
**
** All operate on contiguous arrays via (void *, elem_size).
** All accept a t_cmp_fn comparator for element ordering.
**
** Algorithm comparison:
**
**   ft_qsort         — in-place, O(n log n) avg, O(n²) worst,
**                      NOT stable.  Best general-purpose choice.
**
**   ft_mergesort     — O(n log n) guaranteed, STABLE,
**                      requires O(n) extra memory.
**                      Best when stability matters.
**
**   ft_insertion_sort — O(n) best (sorted input), O(n²) worst,
**                       in-place, STABLE.
**                       Best for small arrays (n < ~16).
** =========================================================
*/

/* In-place quicksort.  Not stable.  Average O(n log n). */
void        ft_qsort(void *arr, t_usize count, t_usize elem_size,
                t_cmp_fn cmp);

/* Stable merge sort.  Allocates O(n) scratch memory.
** Returns FT_ENOMEM on allocation failure (array is unchanged). */
t_ft_status ft_mergesort(void *arr, t_usize count, t_usize elem_size,
                t_cmp_fn cmp);

/* In-place insertion sort.  Stable.  Fast for small / nearly-sorted arrays. */
void        ft_insertion_sort(void *arr, t_usize count, t_usize elem_size,
                t_cmp_fn cmp);

#endif /* LIBFT_ALGO_SORT_H */
