#ifndef LIBFT_MEMORY_POOL_H
# define LIBFT_MEMORY_POOL_H

# include "../core/types.h"
# include "../core/defs.h"

/*
** =========================================================
** Fixed-Size Object Pool  (Free-list allocator)
**
** Design principles:
**   - Pre-allocates N blocks of fixed size upfront
**   - alloc: O(1) — pop from free list
**   - free:  O(1) — push back to free list
**   - Zero fragmentation; excellent cache locality
**   - Overflow: returns NULL (no implicit growth)
**
** Ideal for:
**   - Linked-list nodes
**   - Event/message objects
**   - Particle systems
**   - Any high-frequency fixed-size allocation pattern
**
** Safety: ft_pool_free() does NOT validate that the returned
** pointer was originally allocated from this pool.
** =========================================================
*/

/* Internal free-list node embedded in each free block. */
typedef struct s_pool_block
{
    struct s_pool_block *next;
}   t_pool_block;

typedef struct s_pool
{
    void         *memory;      /* backing allocation               */
    t_pool_block *free_list;   /* head of the intrusive free list  */
    t_usize       block_size;  /* size of each block (>= ptr size) */
    t_usize       capacity;    /* total number of blocks           */
    t_usize       used;        /* blocks currently in use          */
}   t_pool;

/*
** ──── Lifecycle ────────────────────────────────────────── */

/* Create a pool for capacity objects of block_size bytes each.
** block_size will be rounded up to at least sizeof(void *). */
t_pool  *ft_pool_create(t_usize block_size, t_usize capacity);

/* Release backing memory and struct. Does NOT call destructors. */
void     ft_pool_destroy(t_pool *pool);

/*
** ──── Allocation ───────────────────────────────────────── */

/* Allocate one block.  Returns NULL if the pool is full. */
void    *ft_pool_alloc(t_pool *pool);

/* Return a block to the pool.  ptr MUST have been obtained
** from ft_pool_alloc on the same pool. */
void     ft_pool_free(t_pool *pool, void *ptr);

/* Return all blocks to the free list without touching memory. */
void     ft_pool_reset(t_pool *pool);

/*
** ──── Query ────────────────────────────────────────────── */

t_usize  ft_pool_used(const t_pool *pool);
t_usize  ft_pool_available(const t_pool *pool);
t_bool   ft_pool_full(const t_pool *pool);

#endif /* LIBFT_MEMORY_POOL_H */
