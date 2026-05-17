#ifndef LIBFT_DS_QUEUE_H
# define LIBFT_DS_QUEUE_H

# include "../core/types.h"

# include "dlist.h"

/*
** =========================================================
** Queue  (FIFO — First In, First Out)
**
** Implementation: backed by t_dlist.
**
** Trade-offs:
**   + O(1) enqueue (push_back) and dequeue (pop_front)
**   + No realloc — pointer-stable elements
**   - Per-node allocation overhead (pointer + two links)
**
** Use ft_queue_front() to inspect without dequeuing.
** =========================================================
*/

typedef struct s_queue
{
    t_dlist *list;
}   t_queue;

/*
** ──── Lifecycle ────────────────────────────────────────── */

t_queue     *ft_queue_create(void);
void         ft_queue_destroy(t_queue *queue);
void         ft_queue_destroy_deep(t_queue *queue, t_free_fn free_fn);

/*
** ──── Operations ───────────────────────────────────────── */

/* Add elem to the back of the queue. */
t_ft_status  ft_queue_enqueue(t_queue *queue, void *elem);

/* Remove and return the front element.  Returns NULL if empty. */
void        *ft_queue_dequeue(t_queue *queue);

/* Peek at the front element without removing it.  NULL if empty. */
void        *ft_queue_front(const t_queue *queue);

/*
** ──── Query ────────────────────────────────────────────── */

t_usize      ft_queue_size(const t_queue *queue);
t_bool       ft_queue_empty(const t_queue *queue);

#endif /* LIBFT_DS_QUEUE_H */
