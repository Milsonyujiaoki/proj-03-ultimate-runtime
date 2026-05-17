#include "internal/internal.h"
#include "memory/arena.h"
#include "memory/memory.h"

/*
** =========================================================
** Arena Allocator — implementation
** =========================================================
*/

/* ── Lifecycle ───────────────────────────────────────── */

t_arena *ft_arena_create(t_usize capacity)
{
    t_arena *arena;

    LIBFT_ASSERT(capacity > 0);
    arena = ft_malloc(sizeof(t_arena));
    if (!arena)
        return (NULL);
    arena->buf = ft_malloc(capacity);
    if (!arena->buf)
    {
        ft_free(arena);
        return (NULL);
    }
    arena->capacity = capacity;
    arena->offset = 0;
    arena->owns_buf = true;
    return (arena);
}

void    ft_arena_init(t_arena *arena, void *buf, t_usize capacity)
{
    LIBFT_ASSERT(arena != NULL);
    LIBFT_ASSERT(buf != NULL);
    LIBFT_ASSERT(capacity > 0);
    arena->buf = (t_byte *)buf;
    arena->capacity = capacity;
    arena->offset = 0;
    arena->owns_buf = false;
}

void    ft_arena_destroy(t_arena *arena)
{
    if (!arena)
        return ;
    if (arena->owns_buf)
        ft_free(arena->buf);
    ft_free(arena);
}

/* ── Allocation ──────────────────────────────────────── */

void    *ft_arena_alloc_aligned(t_arena *arena, t_usize size, t_usize align)
{
    t_usize aligned_offset;
    void    *ptr;

    if (!arena || size == 0)
        return (NULL);
    LIBFT_ASSERT(LIBFT_IS_POW2(align));
    aligned_offset = LIBFT_ALIGN_UP(arena->offset, align);
    if (aligned_offset + size > arena->capacity)
        return (NULL);
    ptr = arena->buf + aligned_offset;
    arena->offset = aligned_offset + size;
    return (ptr);
}

void    *ft_arena_alloc(t_arena *arena, t_usize size)
{
    return (ft_arena_alloc_aligned(arena, size, LIBFT_ARENA_DEFAULT_ALIGN));
}

void    *ft_arena_calloc(t_arena *arena, t_usize count, t_usize size)
{
    t_usize total;
    void    *ptr;

    /* Overflow check */
    if (size != 0 && count > ((t_usize)-1) / size)
        return (NULL);
    total = count * size;
    ptr = ft_arena_alloc(arena, total);
    if (ptr)
        ft_memset(ptr, 0, total);
    return (ptr);
}

/* ── Management ──────────────────────────────────────── */

void    ft_arena_reset(t_arena *arena)
{
    if (arena)
        arena->offset = 0;
}

t_usize ft_arena_used(const t_arena *arena)
{
    if (!arena)
        return (0);
    return (arena->offset);
}

t_usize ft_arena_remaining(const t_arena *arena)
{
    if (!arena)
        return (0);
    return (arena->capacity - arena->offset);
}

/* ── Marks ───────────────────────────────────────────── */

t_arena_mark    ft_arena_mark_save(const t_arena *arena)
{
    LIBFT_ASSERT(arena != NULL);
    return (arena->offset);
}

void    ft_arena_mark_restore(t_arena *arena, t_arena_mark mark)
{
    LIBFT_ASSERT(arena != NULL);
    LIBFT_ASSERT(mark <= arena->offset);
    arena->offset = mark;
}
