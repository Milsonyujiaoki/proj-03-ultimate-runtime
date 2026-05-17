#ifndef LIBFT_MEMORY_BUFFER_H
# define LIBFT_MEMORY_BUFFER_H

# include "../core/types.h"


/*
** =========================================================
** Byte Buffer  (growable byte sequence)
**
** A contiguous, heap-backed buffer that grows on demand.
** Suitable for:
**   - Building binary packets
**   - Serialization / encoding output
**   - I/O buffering before a single write()
**   - Accumulating chunks from a stream
**
** Ownership: ft_buffer_destroy() frees all backing memory.
** =========================================================
*/
typedef struct s_buffer
{
    t_byte  *data;
    t_usize  size;
    t_usize  capacity;
}   t_buffer;

/*
** ──── Lifecycle ────────────────────────────────────────── */

t_buffer    *ft_buffer_create(t_usize initial_capacity);
void         ft_buffer_destroy(t_buffer *buf);

/*
** ──── Write operations ─────────────────────────────────── */

t_ft_status  ft_buffer_write(t_buffer *buf, const void *data, t_usize size);
t_ft_status  ft_buffer_write_byte(t_buffer *buf, t_byte b);
t_ft_status  ft_buffer_write_u16(t_buffer *buf, t_u16 value);
t_ft_status  ft_buffer_write_u32(t_buffer *buf, t_u32 value);
t_ft_status  ft_buffer_write_u64(t_buffer *buf, t_u64 value);
t_ft_status  ft_buffer_write_str(t_buffer *buf, const char *str);

/*
** ──── Read / access ────────────────────────────────────── */

const t_byte *ft_buffer_data(const t_buffer *buf);
t_usize       ft_buffer_size(const t_buffer *buf);
t_bool        ft_buffer_empty(const t_buffer *buf);

/*
** ──── Management ───────────────────────────────────────── */

/* Reset size to zero (keeps backing allocation). */
void         ft_buffer_clear(t_buffer *buf);

/* Ensure at least min_capacity bytes are available. */
t_ft_status  ft_buffer_reserve(t_buffer *buf, t_usize min_capacity);

#endif /* LIBFT_MEMORY_BUFFER_H */
