#include "internal/internal.h"
#include "string/string_view.h"
#include "string/string.h"
#include "memory/memory.h"

/*
** =========================================================
** String View — implementation
** =========================================================
*/

t_sv    ft_sv_from_cstr(const char *str)
{
    t_sv    sv;

    if (!str)
        return (ft_sv_empty());
    sv.ptr = str;
    sv.len = ft_strlen(str);
    return (sv);
}

t_sv    ft_sv_from_parts(const char *ptr, t_usize len)
{
    t_sv    sv;

    sv.ptr = ptr;
    sv.len = ptr ? len : 0;
    return (sv);
}

t_sv    ft_sv_empty(void)
{
    t_sv    sv;

    sv.ptr = "";
    sv.len = 0;
    return (sv);
}

/* ── Slicing ─────────────────────────────────────────── */

t_sv    ft_sv_substr(t_sv sv, t_usize start, t_usize len)
{
    if (start >= sv.len)
        return (ft_sv_empty());
    if (start + len > sv.len)
        len = sv.len - start;
    return (ft_sv_from_parts(sv.ptr + start, len));
}

t_sv    ft_sv_trim_left(t_sv sv)
{
    while (sv.len > 0 && (sv.ptr[0] == ' ' || sv.ptr[0] == '\t'
            || sv.ptr[0] == '\n' || sv.ptr[0] == '\r'))
    {
        sv.ptr++;
        sv.len--;
    }
    return (sv);
}

t_sv    ft_sv_trim_right(t_sv sv)
{
    while (sv.len > 0)
    {
        char c;
        c = sv.ptr[sv.len - 1];
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
            break ;
        sv.len--;
    }
    return (sv);
}

t_sv    ft_sv_trim(t_sv sv)
{
    return (ft_sv_trim_right(ft_sv_trim_left(sv)));
}

t_sv    ft_sv_chop_by_delim(t_sv *sv, char delim)
{
    t_sv    result;
    t_usize i;

    i = 0;
    while (i < sv->len && sv->ptr[i] != delim)
        i++;
    result = ft_sv_from_parts(sv->ptr, i);
    if (i < sv->len)
    {
        sv->ptr += i + 1;
        sv->len -= i + 1;
    }
    else
    {
        sv->ptr += i;
        sv->len = 0;
    }
    return (result);
}

/* ── Comparison ──────────────────────────────────────── */

t_bool  ft_sv_eq(t_sv a, t_sv b)
{
    if (a.len != b.len)
        return (false);
    return (ft_memcmp(a.ptr, b.ptr, a.len) == 0);
}

t_bool  ft_sv_eq_cstr(t_sv sv, const char *str)
{
    return (ft_sv_eq(sv, ft_sv_from_cstr(str)));
}

int     ft_sv_cmp(t_sv a, t_sv b)
{
    t_usize min_len;
    int     result;

    min_len = LIBFT_MIN(a.len, b.len);
    result = ft_memcmp(a.ptr, b.ptr, min_len);
    if (result != 0)
        return (result);
    return ((a.len > b.len) - (a.len < b.len));
}

/* ── Search ──────────────────────────────────────────── */

t_bool  ft_sv_starts_with(t_sv sv, t_sv prefix)
{
    if (prefix.len > sv.len)
        return (false);
    return (ft_memcmp(sv.ptr, prefix.ptr, prefix.len) == 0);
}

t_bool  ft_sv_ends_with(t_sv sv, t_sv suffix)
{
    if (suffix.len > sv.len)
        return (false);
    return (ft_memcmp(sv.ptr + sv.len - suffix.len,
                      suffix.ptr, suffix.len) == 0);
}

t_bool  ft_sv_contains(t_sv sv, t_sv needle)
{
    return (ft_sv_find(sv, needle) != FT_ENOTFOUND);
}

t_isize ft_sv_find_char(t_sv sv, char ch)
{
    t_usize i;

    i = 0;
    while (i < sv.len)
    {
        if (sv.ptr[i] == ch)
            return ((t_isize)i);
        i++;
    }
    return (FT_ENOTFOUND);
}

t_isize ft_sv_find(t_sv sv, t_sv needle)
{
    t_usize i;

    if (needle.len == 0)
        return (0);
    if (needle.len > sv.len)
        return (FT_ENOTFOUND);
    i = 0;
    while (i <= sv.len - needle.len)
    {
        if (ft_memcmp(sv.ptr + i, needle.ptr, needle.len) == 0)
            return ((t_isize)i);
        i++;
    }
    return (FT_ENOTFOUND);
}

/* ── Query ───────────────────────────────────────────── */

t_bool  ft_sv_is_empty(t_sv sv)
{
    return (sv.len == 0);
}
