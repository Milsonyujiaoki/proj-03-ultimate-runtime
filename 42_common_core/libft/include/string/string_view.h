#ifndef LIBFT_STRING_VIEW_H
# define LIBFT_STRING_VIEW_H

# include "../core/types.h"
# include "../core/defs.h"

/*
** =========================================================
** String View  (non-owning, immutable string slice)
**
** A t_sv is a fat pointer: { ptr, len }.
** It does NOT NUL-terminate, does NOT own memory.
**
** Use cases:
**   - Zero-copy substring operations
**   - Parsing without allocation
**   - Function parameters that accept both C strings and
**     substrings without requiring NUL termination
**
** Ownership: NONE.  The caller must ensure the backing
** buffer outlives every t_sv derived from it.
** =========================================================
*/

typedef struct s_sv
{
    const char  *ptr;
    t_usize      len;
}   t_sv;

/*
** ──── Construction ─────────────────────────────────────── */

/* Build from a NUL-terminated C string (len = ft_strlen). */
t_sv    ft_sv_from_cstr(const char *str);

/* Build from an explicit pointer + length pair. */
t_sv    ft_sv_from_parts(const char *ptr, t_usize len);

/* An empty (zero-length) view. */
t_sv    ft_sv_empty(void);

/*
** ──── Slicing ──────────────────────────────────────────── */

/* Substring starting at start, of length len (clamped to bounds). */
t_sv    ft_sv_substr(t_sv sv, t_usize start, t_usize len);

/* Strip leading whitespace. */
t_sv    ft_sv_trim_left(t_sv sv);

/* Strip trailing whitespace. */
t_sv    ft_sv_trim_right(t_sv sv);

/* Strip both sides. */
t_sv    ft_sv_trim(t_sv sv);

/* Consume sv up to (but not including) the first occurrence of delim.
** sv is advanced past the delimiter; the consumed portion is returned.
** If delim is not found, sv becomes empty and the whole original is returned. */
t_sv    ft_sv_chop_by_delim(t_sv *sv, char delim);

/*
** ──── Comparison ───────────────────────────────────────── */

t_bool  ft_sv_eq(t_sv a, t_sv b);
t_bool  ft_sv_eq_cstr(t_sv sv, const char *str);
int     ft_sv_cmp(t_sv a, t_sv b);

/*
** ──── Search ───────────────────────────────────────────── */

t_bool  ft_sv_starts_with(t_sv sv, t_sv prefix);
t_bool  ft_sv_ends_with(t_sv sv, t_sv suffix);
t_bool  ft_sv_contains(t_sv sv, t_sv needle);

/* Returns byte-index of first ch, or FT_ENOTFOUND. */
t_isize ft_sv_find_char(t_sv sv, char ch);

/* Returns byte-index of first occurrence of needle, or FT_ENOTFOUND. */
t_isize ft_sv_find(t_sv sv, t_sv needle);

/*
** ──── Query ────────────────────────────────────────────── */

t_bool  ft_sv_is_empty(t_sv sv);

#endif /* LIBFT_STRING_VIEW_H */
