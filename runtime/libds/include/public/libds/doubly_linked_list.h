#ifndef LIBDS_DOUBLY_LINKED_LIST_H
#define LIBDS_DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef struct ds_dll_node {
    void               *data;
    struct ds_dll_node *prev;
    struct ds_dll_node *next;
} ds_dll_node_t;

typedef struct ds_dll ds_dll_t;

ds_dll_t      *ds_dll_create(void);
void           ds_dll_destroy(ds_dll_t **self);
size_t         ds_dll_size(const ds_dll_t *l);
int            ds_dll_push_front(ds_dll_t *l, void *data);
int            ds_dll_push_back(ds_dll_t *l, void *data);
void          *ds_dll_pop_front(ds_dll_t *l);
void          *ds_dll_pop_back(ds_dll_t *l);
int            ds_dll_insert_before(ds_dll_t *l, ds_dll_node_t *node, void *data);
int            ds_dll_insert_after(ds_dll_t *l, ds_dll_node_t *node, void *data);
void           ds_dll_remove_node(ds_dll_t *l, ds_dll_node_t *node);
ds_dll_node_t *ds_dll_head(const ds_dll_t *l);
ds_dll_node_t *ds_dll_tail(const ds_dll_t *l);
void           ds_dll_clear(ds_dll_t *l);

#endif /* LIBDS_DOUBLY_LINKED_LIST_H */
