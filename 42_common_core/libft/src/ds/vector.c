
#include "ds/vector.h"
#include "memory/memory.h"

/*
** =========================================================
** Vector (Dynamic Contiguous Array) — implementation
**
** Growth strategy:
**   new_capacity = old_capacity * LIBFT_VECTOR_GROW_FACTOR
**   This guarantees amortised O(1) push.
** =========================================================
*/

/* ── Private ─────────────────────────────────────────── */

/* Return a pointer to the element at index (no bounds check). */
static void *elem_ptr(const t_vector *vec, t_usize index)
{
    return ((t_byte *)vec->data + index * vec->elem_size);
}

static t_ft_status  grow(t_vector *vec)
{
    t_usize new_cap;
    void    *new_data;

    if (vec->capacity == 0)
        new_cap = LIBFT_VECTOR_INIT_CAPACITY;
    else
        new_cap = vec->capacity * LIBFT_VECTOR_GROW_FACTOR;
    new_data = ft_realloc(vec->data, new_cap * vec->elem_size);
    if (!new_data)
        return (FT_ENOMEM);
    vec->data = new_data;
    vec->capacity = new_cap;
    return (FT_OK);
}

/* ── Lifecycle ───────────────────────────────────────── */

t_vector    *ft_vector_create(t_usize elem_size)
{
    return (ft_vector_create_cap(elem_size, LIBFT_VECTOR_INIT_CAPACITY));
}

t_vector    *ft_vector_create_cap(t_usize elem_size, t_usize capacity)
{
    t_vector    *vec;

    LIBFT_ASSERT(elem_size > 0);
    vec = ft_malloc(sizeof(t_vector));
    if (!vec)
        return (NULL);
    vec->elem_size = elem_size;
    vec->size = 0;
    vec->capacity = 0;
    vec->data = NULL;
    if (capacity > 0)
    {
        vec->data = ft_malloc(capacity * elem_size);
        if (!vec->data)
        {
            ft_free(vec);
            return (NULL);
        }
        vec->capacity = capacity;
    }
    return (vec);
}

void    ft_vector_destroy(t_vector *vec)
{
    if (!vec)
        return ;
    ft_free(vec->data);
    ft_free(vec);
}

void    ft_vector_destroy_deep(t_vector *vec, t_free_fn free_fn)
{
    t_usize i;

    if (!vec)
        return ;
    if (free_fn)
    {
        i = 0;
        while (i < vec->size)
        {
            free_fn(*(void **)elem_ptr(vec, i));
            i++;
        }
    }
    ft_free(vec->data);
    ft_free(vec);
}

/* ── Insertion / Removal ─────────────────────────────── */

t_ft_status ft_vector_push(t_vector *vec, const void *elem)
{
    if (!vec || !elem)
        return (FT_EINVAL);
    if (vec->size == vec->capacity)
    {
        if (grow(vec) != FT_OK)
            return (FT_ENOMEM);
    }
    ft_memcpy(elem_ptr(vec, vec->size), elem, vec->elem_size);
    vec->size++;
    return (FT_OK);
}

t_ft_status ft_vector_pop(t_vector *vec, void *out)
{
    if (!vec || vec->size == 0)
        return (FT_EEMPTY);
    vec->size--;
    if (out)
        ft_memcpy(out, elem_ptr(vec, vec->size), vec->elem_size);
    return (FT_OK);
}

t_ft_status ft_vector_insert(t_vector *vec, t_usize index, const void *elem)
{
    t_usize bytes_to_move;

    if (!vec || !elem || index > vec->size)
        return (FT_EINVAL);
    if (vec->size == vec->capacity)
    {
        if (grow(vec) != FT_OK)
            return (FT_ENOMEM);
    }
    bytes_to_move = (vec->size - index) * vec->elem_size;
    if (bytes_to_move > 0)
        ft_memmove(elem_ptr(vec, index + 1), elem_ptr(vec, index),
            bytes_to_move);
    ft_memcpy(elem_ptr(vec, index), elem, vec->elem_size);
    vec->size++;
    return (FT_OK);
}

t_ft_status ft_vector_remove(t_vector *vec, t_usize index)
{
    t_usize bytes_to_move;

    if (!vec || index >= vec->size)
        return (FT_ERANGE);
    bytes_to_move = (vec->size - index - 1) * vec->elem_size;
    if (bytes_to_move > 0)
        ft_memmove(elem_ptr(vec, index), elem_ptr(vec, index + 1),
            bytes_to_move);
    vec->size--;
    return (FT_OK);
}

/* ── Access ──────────────────────────────────────────── */

void    *ft_vector_get(const t_vector *vec, t_usize index)
{
    if (!vec || index >= vec->size)
        return (NULL);
    return (elem_ptr(vec, index));
}

void    *ft_vector_front(const t_vector *vec)
{
    if (!vec || vec->size == 0)
        return (NULL);
    return (elem_ptr(vec, 0));
}

void    *ft_vector_back(const t_vector *vec)
{
    if (!vec || vec->size == 0)
        return (NULL);
    return (elem_ptr(vec, vec->size - 1));
}

t_ft_status ft_vector_set(t_vector *vec, t_usize index, const void *elem)
{
    if (!vec || !elem || index >= vec->size)
        return (FT_EINVAL);
    ft_memcpy(elem_ptr(vec, index), elem, vec->elem_size);
    return (FT_OK);
}

/* ── Query ───────────────────────────────────────────── */

t_usize ft_vector_size(const t_vector *vec)
{
    if (!vec)
        return (0);
    return (vec->size);
}

t_usize ft_vector_capacity(const t_vector *vec)
{
    if (!vec)
        return (0);
    return (vec->capacity);
}

t_bool  ft_vector_empty(const t_vector *vec)
{
    return (!vec || vec->size == 0);
}

/* ── Capacity management ─────────────────────────────── */

t_ft_status ft_vector_reserve(t_vector *vec, t_usize new_cap)
{
    void    *new_data;

    if (!vec)
        return (FT_EINVAL);
    if (new_cap <= vec->capacity)
        return (FT_OK);
    new_data = ft_realloc(vec->data, new_cap * vec->elem_size);
    if (!new_data)
        return (FT_ENOMEM);
    vec->data = new_data;
    vec->capacity = new_cap;
    return (FT_OK);
}

t_ft_status ft_vector_shrink(t_vector *vec)
{
    void    *new_data;

    if (!vec || vec->size == vec->capacity)
        return (FT_OK);
    if (vec->size == 0)
    {
        ft_free(vec->data);
        vec->data = NULL;
        vec->capacity = 0;
        return (FT_OK);
    }
    new_data = ft_realloc(vec->data, vec->size * vec->elem_size);
    if (!new_data)
        return (FT_ENOMEM);
    vec->data = new_data;
    vec->capacity = vec->size;
    return (FT_OK);
}

void    ft_vector_clear(t_vector *vec)
{
    if (vec)
        vec->size = 0;
}

/* ── Traversal ───────────────────────────────────────── */

void    ft_vector_foreach(t_vector *vec, t_visit_fn fn, void *ctx)
{
    t_usize i;

    if (!vec || !fn)
        return ;
    i = 0;
    while (i < vec->size)
    {
        fn(elem_ptr(vec, i), ctx);
        i++;
    }
}

/* ── Search ──────────────────────────────────────────── */

t_isize ft_vector_find(const t_vector *vec, t_pred_fn pred, const void *ctx)
{
    t_usize i;

    if (!vec || !pred)
        return (FT_ENOTFOUND);
    i = 0;
    while (i < vec->size)
    {
        if (pred(elem_ptr(vec, i), ctx))
            return ((t_isize)i);
        i++;
    }
    return (FT_ENOTFOUND);
}
