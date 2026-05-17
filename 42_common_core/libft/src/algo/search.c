
#include "algo/search.h"
#include "memory/memory.h"

/*
** =========================================================
** Search algorithms — implementation
** =========================================================
*/

static void *elem_at(const void *arr, t_usize index, t_usize elem_size)
{
    return ((t_byte *)arr + index * elem_size);
}

t_isize ft_bsearch(const void *arr, t_usize count, t_usize elem_size,
            const void *key, t_cmp_fn cmp)
{
    t_usize lo;
    t_usize hi;
    t_usize mid;
    int     result;

    if (!arr || !key || !cmp || count == 0)
        return (FT_ENOTFOUND);
    lo = 0;
    hi = count - 1;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        result = cmp(key, elem_at(arr, mid, elem_size));
        if (result == 0)
            return ((t_isize)mid);
        else if (result < 0)
        {
            if (mid == 0)
                break ;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return (FT_ENOTFOUND);
}

t_isize ft_lsearch(const void *arr, t_usize count, t_usize elem_size,
            t_pred_fn pred, const void *ctx)
{
    t_usize i;

    if (!arr || !pred || count == 0)
        return (FT_ENOTFOUND);
    i = 0;
    while (i < count)
    {
        if (pred(elem_at(arr, i, elem_size), ctx))
            return ((t_isize)i);
        i++;
    }
    return (FT_ENOTFOUND);
}
