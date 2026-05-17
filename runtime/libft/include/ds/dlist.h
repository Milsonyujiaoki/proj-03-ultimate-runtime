#ifndef LIBFT_DS_DLIST_H
# define LIBFT_DS_DLIST_H

# include "../core/types.h"


/*
** =========================================================
** Doubly Linked List
**
** Characteristics:
**   - O(1) push_front, push_back, pop_front, pop_back
**   - O(1) insert/remove given a node pointer
**   - O(n) insert/remove by index
**   - O(1) size (tracked)
**   - Bidirectional traversal
**
** Ownership:
**   Same as t_list: does NOT own pointed-to data by default.
** =========================================================
*/

typedef struct s_dlist_node
{
    void                *data;
    struct s_dlist_node *prev;
    struct s_dlist_node *next;
}   t_dlist_node;

typedef struct s_dlist
{
    t_dlist_node *head;
    t_dlist_node *tail;
    t_usize       size;
}   t_dlist;

/*
** ---- Lifecycle ------------------------------------------ */

t_dlist     *ft_dlist_create(void);
void         ft_dlist_destroy(t_dlist *list);
void         ft_dlist_destroy_deep(t_dlist *list, void (*free_fn)(void *));

/*
** ---- Insertion ------------------------------------------ */

int          ft_dlist_push_front(t_dlist *list, void *data);
int          ft_dlist_push_back(t_dlist *list, void *data);
int          ft_dlist_insert_after(t_dlist *list,
                t_dlist_node *node, void *data);
int          ft_dlist_insert_before(t_dlist *list,
                t_dlist_node *node, void *data);

/*
** ---- Removal -------------------------------------------- */

void        *ft_dlist_pop_front(t_dlist *list);
void        *ft_dlist_pop_back(t_dlist *list);
void        *ft_dlist_remove_node(t_dlist *list, t_dlist_node *node);

/*
** ---- Access --------------------------------------------- */

void        *ft_dlist_front(const t_dlist *list);
void        *ft_dlist_back(const t_dlist *list);

/*
** ---- Query ---------------------------------------------- */

t_usize      ft_dlist_size(const t_dlist *list);
t_bool       ft_dlist_empty(const t_dlist *list);

/*
** ---- Traversal ------------------------------------------ */

void         ft_dlist_foreach(t_dlist *list, void (*fn)(void *, void *), void *ctx);
void         ft_dlist_foreach_reverse(t_dlist *list, void (*fn)(void *, void *), void *ctx);

/*
** ---- Search --------------------------------------------- */

t_dlist_node *ft_dlist_find(const t_dlist *list, int (*pred)(void *, const void *),
                const void *ctx);

#endif /* LIBFT_DS_DLIST_H */
