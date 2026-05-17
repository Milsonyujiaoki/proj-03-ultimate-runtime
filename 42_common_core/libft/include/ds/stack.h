#ifndef LIBFT_DS_STACK_H
# define LIBFT_DS_STACK_H

# include "../core/types.h"
# include "../core/defs.h"
# include "vector.h"

/*
** =========================================================
** Stack  (LIFO — Last In, First Out)
**
** Implementation: backed by t_vector.
**
** Trade-offs:
**   + Contiguous memory — cache-friendly
**   + O(1) amortised push/pop
**   - No pointer stability (internal realloc may move data)
**
** Use ft_stack_peek() to inspect the top element without
** removing it.  The returned pointer is invalidated on push.
** =========================================================
*/

typedef struct s_stack
{
    t_vector *vec;
}   t_stack;

/*
** ──── Lifecycle ────────────────────────────────────────── */

t_stack     *ft_stack_create(t_usize elem_size);
void         ft_stack_destroy(t_stack *stack);
void         ft_stack_destroy_deep(t_stack *stack, t_free_fn free_fn);

/*
** ──── Operations ───────────────────────────────────────── */

t_ft_status  ft_stack_push(t_stack *stack, const void *elem);
t_ft_status  ft_stack_pop(t_stack *stack, void *out);

/* Returns a pointer to the top element without removing it.
** Returns NULL if the stack is empty. */
void        *ft_stack_peek(const t_stack *stack);

/*
** ──── Query ────────────────────────────────────────────── */

t_usize      ft_stack_size(const t_stack *stack);
t_bool       ft_stack_empty(const t_stack *stack);

#endif /* LIBFT_DS_STACK_H */
