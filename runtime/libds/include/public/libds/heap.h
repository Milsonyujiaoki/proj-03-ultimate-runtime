#ifndef LIBDS_HEAP_H
#define LIBDS_HEAP_H

#include <stddef.h>
#include "libds/bst.h"

typedef enum { DS_HEAP_MIN = 0, DS_HEAP_MAX = 1 } ds_heap_type_e;
typedef struct ds_heap ds_heap_t;

ds_heap_t *ds_heap_create(ds_heap_type_e type, ds_cmp_fn cmp);
void       ds_heap_destroy(ds_heap_t **self);
size_t     ds_heap_size(const ds_heap_t *h);
int        ds_heap_push(ds_heap_t *h, void *data);
void      *ds_heap_pop(ds_heap_t *h);
void      *ds_heap_peek(const ds_heap_t *h);
void       ds_heap_clear(ds_heap_t *h);

#endif /* LIBDS_HEAP_H */
