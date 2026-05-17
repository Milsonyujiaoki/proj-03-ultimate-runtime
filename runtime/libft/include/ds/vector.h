#ifndef LIBFT_DS_VECTOR_H
# define LIBFT_DS_VECTOR_H

# include "../core/types.h"

# define LIBFT_VECTOR_INIT_CAPACITY 8
# define LIBFT_VECTOR_GROW_FACTOR   2

/*
** =========================================================
** Vector  (Dynamic Contiguous Array)
**
** Characteristics:
**   - O(1) amortised push, pop (back)
**   - O(1) random access by index
**   - O(n) insert/remove at arbitrary position
**   - Contiguous memory — cache-friendly, SIMD-friendly
**   - Doubles capacity on growth (LIBFT_VECTOR_GROW_FACTOR)
**
** Genericity:
**   Elements are stored by VALUE, not by pointer.
**   elem_size must be provided at creation time.
**   ft_vector_get() returns a void * pointer INTO the buffer;
**   callers must cast or memcpy to the concrete type.
**
** Ownership:
**   The vector owns its backing buffer.
**   It does NOT own the data stored unless elem_size is a
**   pointer type AND you use ft_vector_destroy_deep().
** =========================================================
*/

typedef struct s_vector
{
    void    *data;       /* backing heap buffer                     */
    t_usize  elem_size;  /* size of each element in bytes           */
    t_usize  size;       /* number of live elements                 */
    t_usize  capacity;   /* total slots allocated                   */
}   t_vector;

/*
** ──── Lifecycle ────────────────────────────────────────── */

t_vector    *ft_vector_create(t_usize elem_size);
t_vector    *ft_vector_create_cap(t_usize elem_size, t_usize capacity);
void         ft_vector_destroy(t_vector *vec);

/* Calls free_fn on each stored element (treats data as void **). */
void         ft_vector_destroy_deep(t_vector *vec, void (*free_fn)(void *));

/*
** ──── Insertion / Removal ──────────────────────────────── */

/* Copy elem_size bytes from elem into the back of the vector. */
int          ft_vector_push(t_vector *vec, const void *elem);

/* Copy the back element into out (if non-NULL), then remove it. */
int          ft_vector_pop(t_vector *vec, void *out);

/* Insert a copy of elem at position index, shifting right. */
int          ft_vector_insert(t_vector *vec, t_usize index,
                const void *elem);

/* Remove element at index, shifting left.  Returns 0 if out of bounds. */
int          ft_vector_remove(t_vector *vec, t_usize index);

/*
** ──── Access ───────────────────────────────────────────── */

/* Returns a pointer into the internal buffer.  Invalidated by resizes. */
void        *ft_vector_get(const t_vector *vec, t_usize index);
void        *ft_vector_front(const t_vector *vec);
void        *ft_vector_back(const t_vector *vec);

/* Overwrite element at index with a copy of elem. */
int          ft_vector_set(t_vector *vec, t_usize index, const void *elem);

/*
** ──── Query ────────────────────────────────────────────── */

t_usize      ft_vector_size(const t_vector *vec);
t_usize      ft_vector_capacity(const t_vector *vec);
t_bool       ft_vector_empty(const t_vector *vec);

/*
** ──── Capacity management ──────────────────────────────── */

/* Ensure capacity >= new_capacity.  No-op if already sufficient. */
int          ft_vector_reserve(t_vector *vec, t_usize new_capacity);

/* Reduce capacity to exactly size.  Frees unused memory. */
int          ft_vector_shrink(t_vector *vec);

/* Set size to zero.  Keeps backing allocation. */
void         ft_vector_clear(t_vector *vec);

/*
** ──── Traversal ────────────────────────────────────────── */

void         ft_vector_foreach(t_vector *vec, void (*fn)(void *, void *), void *ctx);

/*
** ──── Search ───────────────────────────────────────────── */

/* Returns index of first match, or -1 if not found. */
t_isize      ft_vector_find(const t_vector *vec, int (*pred)(void *, const void *),
                const void *ctx);

#endif /* LIBFT_DS_VECTOR_H */
