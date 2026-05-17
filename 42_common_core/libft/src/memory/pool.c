#include "internal/internal.h"
#include "memory/pool.h"
#include "memory/memory.h"

/*
** =========================================================
** Fixed-Size Object Pool — implementation
**
** Layout of the backing allocation:
**   [block_0][block_1]...[block_{capacity-1}]
**
** Each free block's first sizeof(void *) bytes are used to
** store the next-free pointer (intrusive free list).
** =========================================================
*/

t_pool  *ft_pool_create(t_usize block_size, t_usize capacity)
{
    t_pool          *pool;
    t_pool_block    *block;
    t_usize          i;

    LIBFT_ASSERT(capacity > 0);
    /* Ensure blocks can hold the free-list pointer. */
    if (block_size < sizeof(t_pool_block))
        block_size = sizeof(t_pool_block);
    pool = ft_malloc(sizeof(t_pool));
    if (!pool)
        return (NULL);
    pool->memory = ft_malloc(block_size * capacity);
    if (!pool->memory)
    {
        ft_free(pool);
        return (NULL);
    }
    pool->block_size = block_size;
    pool->capacity = capacity;
    pool->used = 0;
    /* Build the initial free list by chaining every block. */
    pool->free_list = (t_pool_block *)pool->memory;
    i = 0;
    while (i < capacity - 1)
    {
        block = (t_pool_block *)((t_byte *)pool->memory + i * block_size);
        block->next = (t_pool_block *)((t_byte *)pool->memory
                        + (i + 1) * block_size);
        i++;
    }
    block = (t_pool_block *)((t_byte *)pool->memory
                + (capacity - 1) * block_size);
    block->next = NULL;
    return (pool);
}

void    ft_pool_destroy(t_pool *pool)
{
    if (!pool)
        return ;
    ft_free(pool->memory);
    ft_free(pool);
}

void    *ft_pool_alloc(t_pool *pool)
{
    t_pool_block    *block;

    if (!pool || !pool->free_list)
        return (NULL);
    block = pool->free_list;
    pool->free_list = block->next;
    pool->used++;
    return ((void *)block);
}

void    ft_pool_free(t_pool *pool, void *ptr)
{
    t_pool_block    *block;

    if (!pool || !ptr)
        return ;
    block = (t_pool_block *)ptr;
    block->next = pool->free_list;
    pool->free_list = block;
    pool->used--;
}

void    ft_pool_reset(t_pool *pool)
{
    t_pool_block    *block;
    t_usize          i;

    if (!pool)
        return ;
    pool->free_list = (t_pool_block *)pool->memory;
    i = 0;
    while (i < pool->capacity - 1)
    {
        block = (t_pool_block *)((t_byte *)pool->memory
                    + i * pool->block_size);
        block->next = (t_pool_block *)((t_byte *)pool->memory
                        + (i + 1) * pool->block_size);
        i++;
    }
    block = (t_pool_block *)((t_byte *)pool->memory
                + (pool->capacity - 1) * pool->block_size);
    block->next = NULL;
    pool->used = 0;
}

t_usize ft_pool_used(const t_pool *pool)
{
    if (!pool)
        return (0);
    return (pool->used);
}

t_usize ft_pool_available(const t_pool *pool)
{
    if (!pool)
        return (0);
    return (pool->capacity - pool->used);
}

t_bool  ft_pool_full(const t_pool *pool)
{
    return (!pool || pool->used == pool->capacity);
}
