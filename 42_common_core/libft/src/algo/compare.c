
#include "algo/compare.h"
#include "memory/memory.h"
#include "string/string.h"

/*
** =========================================================
** Generic comparators — implementation
** =========================================================
*/

int ft_cmp_int(const void *a, const void *b)
{
    int ia;
    int ib;

    ia = *(const int *)a;
    ib = *(const int *)b;
    return ((ia > ib) - (ia < ib));
}

int ft_cmp_uint(const void *a, const void *b)
{
    unsigned int ua;
    unsigned int ub;

    ua = *(const unsigned int *)a;
    ub = *(const unsigned int *)b;
    return ((ua > ub) - (ua < ub));
}

int ft_cmp_long(const void *a, const void *b)
{
    long    la;
    long    lb;

    la = *(const long *)a;
    lb = *(const long *)b;
    return ((la > lb) - (la < lb));
}

int ft_cmp_ulong(const void *a, const void *b)
{
    unsigned long   ua;
    unsigned long   ub;

    ua = *(const unsigned long *)a;
    ub = *(const unsigned long *)b;
    return ((ua > ub) - (ua < ub));
}

int ft_cmp_i64(const void *a, const void *b)
{
    t_i64   ia;
    t_i64   ib;

    ia = *(const t_i64 *)a;
    ib = *(const t_i64 *)b;
    return ((ia > ib) - (ia < ib));
}

int ft_cmp_u64(const void *a, const void *b)
{
    t_u64   ua;
    t_u64   ub;

    ua = *(const t_u64 *)a;
    ub = *(const t_u64 *)b;
    return ((ua > ub) - (ua < ub));
}

int ft_cmp_str(const void *a, const void *b)
{
    return (ft_strcmp(*(const char *const *)a, *(const char *const *)b));
}

int ft_cmp_ptr(const void *a, const void *b)
{
    t_uptr x;
    t_uptr y;

    x = (t_uptr)a;
    y = (t_uptr)b;
    return ((x > y) - (x < y));
}

int ft_cmp_mem(const void *a, const void *b, t_usize size)
{
    return (ft_memcmp(a, b, size));
}
