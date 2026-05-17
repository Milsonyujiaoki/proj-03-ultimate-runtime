#include "internal/internal.h"
#include "string/string_builder.h"
#include "string/string.h"
#include "memory/memory.h"

/*
** =========================================================
** String Builder — implementation
** =========================================================
*/

/* ── Private ─────────────────────────────────────────── */

static t_ft_status  sb_ensure(t_sb *sb, t_usize needed)
{
    t_usize  new_cap;
    char    *new_buf;

    if (needed < sb->capacity)
        return (FT_OK);
    new_cap = sb->capacity ? sb->capacity * 2 : LIBFT_SB_INIT_CAPACITY;
    while (new_cap <= needed)
        new_cap *= 2;
    new_buf = (char *)ft_realloc(sb->buf, new_cap);
    if (!new_buf)
        return (FT_ENOMEM);
    sb->buf = new_buf;
    sb->capacity = new_cap;
    return (FT_OK);
}

/* ── Lifecycle ───────────────────────────────────────── */

t_sb    *ft_sb_create(void)
{
    return (ft_sb_create_cap(LIBFT_SB_INIT_CAPACITY));
}

t_sb    *ft_sb_create_cap(t_usize capacity)
{
    t_sb    *sb;

    if (capacity == 0)
        capacity = LIBFT_SB_INIT_CAPACITY;
    sb = ft_malloc(sizeof(t_sb));
    if (!sb)
        return (NULL);
    sb->buf = ft_malloc(capacity);
    if (!sb->buf)
    {
        ft_free(sb);
        return (NULL);
    }
    sb->buf[0] = '\0';
    sb->len = 0;
    sb->capacity = capacity;
    return (sb);
}

void    ft_sb_destroy(t_sb *sb)
{
    if (!sb)
        return ;
    ft_free(sb->buf);
    ft_free(sb);
}

/* ── Append operations ───────────────────────────────── */

t_ft_status ft_sb_append_char(t_sb *sb, char c)
{
    if (!sb)
        return (FT_EINVAL);
    if (sb_ensure(sb, sb->len + 2) != FT_OK)
        return (FT_ENOMEM);
    sb->buf[sb->len++] = c;
    sb->buf[sb->len] = '\0';
    return (FT_OK);
}

t_ft_status ft_sb_append_bytes(t_sb *sb, const void *data, t_usize len)
{
    if (!sb || !data)
        return (FT_EINVAL);
    if (sb_ensure(sb, sb->len + len + 1) != FT_OK)
        return (FT_ENOMEM);
    ft_memcpy(sb->buf + sb->len, data, len);
    sb->len += len;
    sb->buf[sb->len] = '\0';
    return (FT_OK);
}

t_ft_status ft_sb_append_str(t_sb *sb, const char *str)
{
    if (!sb || !str)
        return (FT_EINVAL);
    return (ft_sb_append_bytes(sb, str, ft_strlen(str)));
}

t_ft_status ft_sb_append_sv(t_sb *sb, t_sv sv)
{
    return (ft_sb_append_bytes(sb, sv.ptr, sv.len));
}

t_ft_status ft_sb_append_i64(t_sb *sb, t_i64 value)
{
    char    tmp[22];
    t_usize len;
    t_i64   v;
    t_bool  neg;

    if (!sb)
        return (FT_EINVAL);
    neg = (value < 0);
    v = neg ? -value : value;
    len = 0;
    if (v == 0)
    {
        tmp[len++] = '0';
    }
    else
    {
        while (v > 0)
        {
            tmp[len++] = (char)('0' + (v % 10));
            v /= 10;
        }
        if (neg)
            tmp[len++] = '-';
    }
    /* Reverse */
    {
        t_usize i;
        t_usize j;
        char    c;
        i = 0;
        j = len - 1;
        while (i < j)
        {
            c = tmp[i]; tmp[i] = tmp[j]; tmp[j] = c;
            i++; j--;
        }
    }
    return (ft_sb_append_bytes(sb, tmp, len));
}

t_ft_status ft_sb_append_u64(t_sb *sb, t_u64 value)
{
    char    tmp[21];
    t_usize len;
    t_u64   v;

    if (!sb)
        return (FT_EINVAL);
    v = value;
    len = 0;
    if (v == 0)
    {
        tmp[len++] = '0';
    }
    else
    {
        while (v > 0)
        {
            tmp[len++] = (char)('0' + (v % 10));
            v /= 10;
        }
    }
    /* Reverse */
    {
        t_usize i;
        t_usize j;
        char    c;
        i = 0;
        j = len - 1;
        while (i < j)
        {
            c = tmp[i]; tmp[i] = tmp[j]; tmp[j] = c;
            i++; j--;
        }
    }
    return (ft_sb_append_bytes(sb, tmp, len));
}

/* ── Access / Output ─────────────────────────────────── */

const char  *ft_sb_cstr(const t_sb *sb)
{
    if (!sb)
        return ("");
    return (sb->buf);
}

t_sv    ft_sb_view(const t_sb *sb)
{
    if (!sb)
        return (ft_sv_empty());
    return (ft_sv_from_parts(sb->buf, sb->len));
}

char    *ft_sb_take(t_sb *sb)
{
    char    *result;

    if (!sb)
        return (NULL);
    result = sb->buf;
    sb->buf = ft_malloc(LIBFT_SB_INIT_CAPACITY);
    if (sb->buf)
    {
        sb->buf[0] = '\0';
        sb->capacity = LIBFT_SB_INIT_CAPACITY;
    }
    else
    {
        sb->capacity = 0;
    }
    sb->len = 0;
    return (result);
}

/* ── Query ───────────────────────────────────────────── */

t_usize ft_sb_len(const t_sb *sb)
{
    if (!sb)
        return (0);
    return (sb->len);
}

t_bool  ft_sb_is_empty(const t_sb *sb)
{
    return (!sb || sb->len == 0);
}

/* ── Management ──────────────────────────────────────── */

void    ft_sb_clear(t_sb *sb)
{
    if (!sb || !sb->buf)
        return ;
    sb->len = 0;
    sb->buf[0] = '\0';
}

t_ft_status ft_sb_reserve(t_sb *sb, t_usize min_capacity)
{
    char    *new_buf;

    if (!sb)
        return (FT_EINVAL);
    if (min_capacity < sb->capacity)
        return (FT_OK);
    new_buf = ft_realloc(sb->buf, min_capacity + 1);
    if (!new_buf)
        return (FT_ENOMEM);
    sb->buf = new_buf;
    sb->capacity = min_capacity + 1;
    return (FT_OK);
}
