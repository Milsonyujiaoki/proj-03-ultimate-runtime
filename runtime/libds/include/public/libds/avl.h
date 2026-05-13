#ifndef LIBDS_AVL_H
#define LIBDS_AVL_H

#include <stddef.h>
#include "libds/bst.h"

typedef struct ds_avl ds_avl_t;

/** AVL tree — self-balancing BST, O(log n) insert/search/delete. */
ds_avl_t *ds_avl_create(ds_cmp_fn cmp);
void      ds_avl_destroy(ds_avl_t **self);
size_t    ds_avl_size(const ds_avl_t *t);
int       ds_avl_insert(ds_avl_t *t, void *data);
void     *ds_avl_search(const ds_avl_t *t, const void *key);
int       ds_avl_delete(ds_avl_t *t, const void *key);
void      ds_avl_inorder(const ds_avl_t *t,
                          void (*fn)(void *data, void *ctx), void *ctx);
int       ds_avl_height(const ds_avl_t *t);
void      ds_avl_clear(ds_avl_t *t);

#endif /* LIBDS_AVL_H */
