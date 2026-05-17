#ifndef LIBFT_STRING_BUILDER_H
# define LIBFT_STRING_BUILDER_H

# include "../core/types.h"

# include "string_view.h"

/*
** =========================================================
** String Builder  (mutable, growable string)
**
** Design:
**   - Always NUL-terminated internally (safe to call ft_sb_cstr)
**   - Amortised O(1) append via geometric capacity growth
**   - Zero-copy view via ft_sb_view()
**   - ft_sb_take() transfers ownership to the caller;
**     the builder is left in an empty state
**
** Ownership: ft_sb_destroy() frees all memory.
** =========================================================
*/

typedef struct s_sb
{
    char    *buf;
    t_usize  len;
    t_usize  capacity;
}   t_sb;

/*
** ──── Lifecycle ────────────────────────────────────────── */

t_sb        *ft_sb_create(void);
t_sb        *ft_sb_create_cap(t_usize capacity);
void         ft_sb_destroy(t_sb *sb);

/*
** ──── Append operations ────────────────────────────────── */

t_ft_status  ft_sb_append_char(t_sb *sb, char c);
t_ft_status  ft_sb_append_str(t_sb *sb, const char *str);
t_ft_status  ft_sb_append_sv(t_sb *sb, t_sv sv);
t_ft_status  ft_sb_append_bytes(t_sb *sb, const void *data, t_usize len);
t_ft_status  ft_sb_append_i64(t_sb *sb, t_i64 value);
t_ft_status  ft_sb_append_u64(t_sb *sb, t_u64 value);

/*
** ──── Access / Output ──────────────────────────────────── */

/* Returns a NUL-terminated pointer into the internal buffer.
** Pointer is invalidated on any append operation. */
const char  *ft_sb_cstr(const t_sb *sb);

/* Returns a view into the internal buffer.  Same lifetime caveats. */
t_sv         ft_sb_view(const t_sb *sb);

/* Transfer ownership of the internal buffer to the caller.
** The builder is reset to empty; caller must ft_free() the result. */
char        *ft_sb_take(t_sb *sb);

/*
** ──── Query ────────────────────────────────────────────── */

t_usize      ft_sb_len(const t_sb *sb);
t_bool       ft_sb_is_empty(const t_sb *sb);

/*
** ──── Management ───────────────────────────────────────── */

/* Reset len to 0; NUL-terminates buf[0]; keeps backing allocation. */
void         ft_sb_clear(t_sb *sb);

/* Ensure internal buffer can hold at least min_capacity chars + NUL. */
t_ft_status  ft_sb_reserve(t_sb *sb, t_usize min_capacity);

#endif /* LIBFT_STRING_BUILDER_H */
