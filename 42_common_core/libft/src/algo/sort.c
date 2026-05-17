#include "internal/internal.h"
#include "algo/sort.h"
#include "memory/memory.h"
#include "memory/alloc.h"

/*
** =========================================================
** Sorting algorithms — implementation
** =========================================================
*/

/* ── Shared helpers ──────────────────────────────────── */

static void elem_swap(void *a, void *b, t_usize elem_size)
{
    t_byte  tmp[256];
    t_byte  *pa;
    t_byte  *pb;
    t_usize  i;

    pa = (t_byte *)a;
    pb = (t_byte *)b;
    if (elem_size <= sizeof(tmp))
    {
        ft_memcpy(tmp, pa, elem_size);
        ft_memcpy(pa, pb, elem_size);
        ft_memcpy(pb, tmp, elem_size);
    }
    else
    {
        i = 0;
        while (i < elem_size)
        {
            tmp[0] = pa[i];
            pa[i] = pb[i];
            pb[i] = tmp[0];
            i++;
        }
    }
}

static void *elem_at(void *arr, t_usize index, t_usize elem_size)
{
    return ((t_byte *)arr + index * elem_size);
}

/* ── Insertion sort ──────────────────────────────────── */

void    ft_insertion_sort(void *arr, t_usize count, t_usize elem_size,
            t_cmp_fn cmp)
{
    t_usize i;
    t_isize j;

    if (!arr || count < 2 || !cmp)
        return ;
    i = 1;
    while (i < count)
    {
        j = (t_isize)i - 1;
        while (j >= 0
            && cmp(elem_at(arr, (t_usize)j, elem_size),
                   elem_at(arr, (t_usize)(j + 1), elem_size)) > 0)
        {
            elem_swap(elem_at(arr, (t_usize)j, elem_size),
                      elem_at(arr, (t_usize)(j + 1), elem_size),
                      elem_size);
            j--;
        }
        i++;
    }
}

/* ── Quicksort (median-of-three, Lomuto scheme) ──────── */

static t_usize  qs_partition(void *arr, t_usize lo, t_usize hi,
                    t_usize elem_size, t_cmp_fn cmp)
{
    t_usize mid;
    t_usize i;
    t_usize j;

    /* Median of three: bring median to hi position */
    mid = lo + (hi - lo) / 2;
    if (cmp(elem_at(arr, lo, elem_size), elem_at(arr, mid, elem_size)) > 0)
        elem_swap(elem_at(arr, lo, elem_size),
                  elem_at(arr, mid, elem_size), elem_size);
    if (cmp(elem_at(arr, lo, elem_size), elem_at(arr, hi, elem_size)) > 0)
        elem_swap(elem_at(arr, lo, elem_size),
                  elem_at(arr, hi, elem_size), elem_size);
    if (cmp(elem_at(arr, mid, elem_size), elem_at(arr, hi, elem_size)) > 0)
        elem_swap(elem_at(arr, mid, elem_size),
                  elem_at(arr, hi, elem_size), elem_size);
    /* Pivot is at hi */
    i = lo;
    j = lo;
    while (j < hi)
    {
        if (cmp(elem_at(arr, j, elem_size),
                elem_at(arr, hi, elem_size)) <= 0)
        {
            elem_swap(elem_at(arr, i, elem_size),
                      elem_at(arr, j, elem_size), elem_size);
            i++;
        }
        j++;
    }
    elem_swap(elem_at(arr, i, elem_size),
              elem_at(arr, hi, elem_size), elem_size);
    return (i);
}

static void qs_recurse(void *arr, t_usize lo, t_usize hi,
            t_usize elem_size, t_cmp_fn cmp)
{
    t_usize pivot;

    if (lo >= hi)
        return ;
    /* Fall back to insertion sort for small partitions */
    if (hi - lo < 16)
    {
        ft_insertion_sort(elem_at(arr, lo, elem_size),
            hi - lo + 1, elem_size, cmp);
        return ;
    }
    pivot = qs_partition(arr, lo, hi, elem_size, cmp);
    if (pivot > 0)
        qs_recurse(arr, lo, pivot - 1, elem_size, cmp);
    qs_recurse(arr, pivot + 1, hi, elem_size, cmp);
}

void    ft_qsort(void *arr, t_usize count, t_usize elem_size, t_cmp_fn cmp)
{
    if (!arr || count < 2 || !cmp)
        return ;
    qs_recurse(arr, 0, count - 1, elem_size, cmp);
}

/* ── Merge sort ──────────────────────────────────────── */

static void merge(void *arr, t_usize lo, t_usize mid, t_usize hi,
            t_usize elem_size, t_cmp_fn cmp, void *tmp)
{
    t_usize i;
    t_usize j;
    t_usize k;

    ft_memcpy(tmp, elem_at(arr, lo, elem_size), (hi - lo + 1) * elem_size);
    i = 0;
    j = mid - lo + 1;
    k = lo;
    while (i <= mid - lo && j <= hi - lo)
    {
        if (cmp(elem_at(tmp, i, elem_size),
                elem_at(tmp, j, elem_size)) <= 0)
        {
            ft_memcpy(elem_at(arr, k, elem_size),
                      elem_at(tmp, i, elem_size), elem_size);
            i++;
        }
        else
        {
            ft_memcpy(elem_at(arr, k, elem_size),
                      elem_at(tmp, j, elem_size), elem_size);
            j++;
        }
        k++;
    }
    while (i <= mid - lo)
    {
        ft_memcpy(elem_at(arr, k, elem_size),
                  elem_at(tmp, i, elem_size), elem_size);
        i++;
        k++;
    }
    while (j <= hi - lo)
    {
        ft_memcpy(elem_at(arr, k, elem_size),
                  elem_at(tmp, j, elem_size), elem_size);
        j++;
        k++;
    }
}

static void ms_recurse(void *arr, t_usize lo, t_usize hi,
            t_usize elem_size, t_cmp_fn cmp, void *tmp)
{
    t_usize mid;

    if (lo >= hi)
        return ;
    mid = lo + (hi - lo) / 2;
    ms_recurse(arr, lo, mid, elem_size, cmp, tmp);
    ms_recurse(arr, mid + 1, hi, elem_size, cmp, tmp);
    merge(arr, lo, mid, hi, elem_size, cmp, tmp);
}

t_ft_status ft_mergesort(void *arr, t_usize count, t_usize elem_size,
                t_cmp_fn cmp)
{
    void    *tmp;

    if (!arr || count < 2 || !cmp)
        return (FT_OK);
    tmp = ft_malloc(count * elem_size);
    if (!tmp)
        return (FT_ENOMEM);
    ms_recurse(arr, 0, count - 1, elem_size, cmp, tmp);
    ft_free(tmp);
    return (FT_OK);
}
