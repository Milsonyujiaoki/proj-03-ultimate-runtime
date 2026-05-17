#ifndef LIBFT_DS_LIST_H
# define LIBFT_DS_LIST_H

# include "../core/types.h"


/*
** =========================================================
** Singly Linked List
**
** Characteristics:
**   - O(1) push_front, pop_front
**   - O(n) push_back, get, insert_at, remove_at
**   - O(1) size (tracked)
**   - O(n) extra memory from node allocations (pointer overhead)
**
** Ownership:
**   The list stores void * pointers and does NOT own them by
**   default. Use ft_list_destroy_deep() with a destructor to
**   free the pointed-to data.
** =========================================================
*/

typedef struct s_slist_node
{
    void                *data;
    struct s_slist_node *next;
}   t_slist_node;

typedef struct s_slist
{
    t_slist_node *head;
    t_usize       size;
}   t_slist;

/*
** ---- Lifecycle ------------------------------------------ */

t_slist      *ft_list_create(void);
void          ft_list_destroy(t_slist *list);
void          ft_list_destroy_deep(t_slist *list, void (*free_fn)(void *));

/*
** ---- Insertion ------------------------------------------ */

int           ft_list_push_front(t_slist *list, void *data);
int           ft_list_push_back(t_slist *list, void *data);
int           ft_list_insert_at(t_slist *list, t_usize index, void *data);

/*
** ---- Removal -------------------------------------------- */

void         *ft_list_pop_front(t_slist *list);
void         *ft_list_remove_at(t_slist *list, t_usize index);

/*
** ---- Access --------------------------------------------- */

void         *ft_list_front(const t_slist *list);
void         *ft_list_get(const t_slist *list, t_usize index);

/*
** ---- Query ---------------------------------------------- */

t_usize       ft_list_size(const t_slist *list);
t_bool        ft_list_empty(const t_slist *list);

/*
** ---- Traversal ------------------------------------------ */

void          ft_list_foreach(t_slist *list, void (*fn)(void *, void *), void *ctx);

/*
** ---- Search --------------------------------------------- */

t_slist_node *ft_list_find(const t_slist *list, int (*pred)(void *, const void *),
                const void *ctx);

/*
** ---- Mutation ------------------------------------------- */

void          ft_list_reverse(t_slist *list);

#endif /* LIBFT_DS_LIST_H */
