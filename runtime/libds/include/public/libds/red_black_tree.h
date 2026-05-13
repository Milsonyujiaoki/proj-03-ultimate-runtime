#ifndef LIBDS_RED_BLACK_TREE_H
#define LIBDS_RED_BLACK_TREE_H

#include <stddef.h>
#include "libds/bst.h"

typedef struct ds_rbt ds_rbt_t;

/** Red-black tree — O(log n) worst-case for insert/search/delete. */
ds_rbt_t *ds_rbt_create(ds_cmp_fn cmp);
void      ds_rbt_destroy(ds_rbt_t **self);
size_t    ds_rbt_size(const ds_rbt_t *t);
int       ds_rbt_insert(ds_rbt_t *t, void *data);
void     *ds_rbt_search(const ds_rbt_t *t, const void *key);
int       ds_rbt_delete(ds_rbt_t *t, const void *key);
void      ds_rbt_inorder(const ds_rbt_t *t,
                          void (*fn)(void *data, void *ctx), void *ctx);
void      ds_rbt_clear(ds_rbt_t *t);

#endif /* LIBDS_RED_BLACK_TREE_H */
