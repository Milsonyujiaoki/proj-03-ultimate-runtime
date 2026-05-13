#ifndef LIBDS_BST_H
#define LIBDS_BST_H

#include <stddef.h>

typedef struct ds_bst ds_bst_t;
typedef int (*ds_cmp_fn)(const void *a, const void *b);

ds_bst_t *ds_bst_create(ds_cmp_fn cmp);
void      ds_bst_destroy(ds_bst_t **self);
size_t    ds_bst_size(const ds_bst_t *t);
int       ds_bst_insert(ds_bst_t *t, void *data);
void     *ds_bst_search(const ds_bst_t *t, const void *key);
int       ds_bst_delete(ds_bst_t *t, const void *key);
void      ds_bst_inorder(const ds_bst_t *t,
                          void (*fn)(void *data, void *ctx), void *ctx);
void      ds_bst_clear(ds_bst_t *t);

#endif /* LIBDS_BST_H */
