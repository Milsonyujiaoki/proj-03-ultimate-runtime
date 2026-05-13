#ifndef LIBDS_LINKED_LIST_H
#define LIBDS_LINKED_LIST_H

#include <stddef.h>

typedef struct ds_ll_node {
    void              *data;
    struct ds_ll_node *next;
} ds_ll_node_t;

typedef struct ds_ll ds_ll_t;

ds_ll_t      *ds_ll_create(void);
void          ds_ll_destroy(ds_ll_t **self);
size_t        ds_ll_size(const ds_ll_t *l);
int           ds_ll_push_front(ds_ll_t *l, void *data);
int           ds_ll_push_back(ds_ll_t *l, void *data);
void         *ds_ll_pop_front(ds_ll_t *l);
void         *ds_ll_peek_front(const ds_ll_t *l);
int           ds_ll_remove(ds_ll_t *l, void *data,
                            int (*cmp)(const void *, const void *));
ds_ll_node_t *ds_ll_head(const ds_ll_t *l);
void          ds_ll_clear(ds_ll_t *l);

#endif /* LIBDS_LINKED_LIST_H */
