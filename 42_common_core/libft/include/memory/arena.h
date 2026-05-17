#ifndef LIBFT_MEMORY_ARENA_H
# define LIBFT_MEMORY_ARENA_H

# include "../core/types.h"
# include "../core/defs.h"
# include "../core/config.h"

/*
** =========================================================
** Arena Allocator  (Linear / Bump-pointer allocator)
**
** Design principles:
**   - Allocation: O(1) — bump pointer forward
**   - Free-all:   O(1) — reset offset to zero
**   - Individual free: NOT supported (use marks/restore)
**   - No fragmentation within the arena
**
** Ideal for:
**   - Request-scoped allocations (parsers, compilers)
**   - Temporary scratch buffers
**   - Frame allocators in game loops
**   - AST node pools
**
** Ownership:
**   If owns_buf == true, ft_arena_destroy() frees buf.
**   If owns_buf == false, the caller owns buf (stack/extern).
** =========================================================
*/
typedef struct s_arena
{
    t_byte  *buf;
    t_usize  capacity;
    t_usize  offset;
    t_bool   owns_buf;
}   t_arena;

/*
** Snapshot type: an offset saved for later restore.
** Use to implement temporary allocation regions:
**   t_arena_mark m = ft_arena_mark_save(&a);
**   ... allocate temp things ...
**   ft_arena_mark_restore(&a, m);  // free everything since mark
*/
typedef t_usize t_arena_mark;

/*
** ──── Lifecycle ────────────────────────────────────────── */

/* Heap-allocate an arena of the given capacity. */
t_arena     *ft_arena_create(t_usize capacity);

/* Initialize an arena using caller-provided backing buffer.
** The arena does NOT own the buffer (owns_buf = false). */
void         ft_arena_init(t_arena *arena, void *buf, t_usize capacity);

/* Destroy arena and (if owns_buf) free the backing buffer. */
void         ft_arena_destroy(t_arena *arena);

/*
** ──── Allocation ───────────────────────────────────────── */

/* Allocate size bytes, aligned to LIBFT_ARENA_DEFAULT_ALIGN.
** Returns NULL if the arena has insufficient space. */
void        *ft_arena_alloc(t_arena *arena, t_usize size);

/* Allocate size bytes with explicit alignment (must be power of 2). */
void        *ft_arena_alloc_aligned(t_arena *arena, t_usize size,
                t_usize align);

/* Zero-initialised allocation: count * size bytes. */
void        *ft_arena_calloc(t_arena *arena, t_usize count, t_usize size);

/*
** ──── Management ───────────────────────────────────────── */

/* Reset offset to zero — effectively frees all allocations. */
void         ft_arena_reset(t_arena *arena);

/* Bytes currently in use. */
t_usize      ft_arena_used(const t_arena *arena);

/* Bytes remaining before the arena is full. */
t_usize      ft_arena_remaining(const t_arena *arena);

/*
** ──── Marks (sub-region restore) ──────────────────────── */

t_arena_mark ft_arena_mark_save(const t_arena *arena);
void         ft_arena_mark_restore(t_arena *arena, t_arena_mark mark);

#endif /* LIBFT_MEMORY_ARENA_H */
