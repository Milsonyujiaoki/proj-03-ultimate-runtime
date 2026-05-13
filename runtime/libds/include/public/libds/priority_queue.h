#ifndef LIBDS_PRIORITY_QUEUE_H
#define LIBDS_PRIORITY_QUEUE_H

#include <stddef.h>
#include "libds/bst.h"

typedef struct ds_pq ds_pq_t;

ds_pq_t *ds_pq_create(ds_cmp_fn cmp);  /* min-priority by default */
void     ds_pq_destroy(ds_pq_t **self);
size_t   ds_pq_size(const ds_pq_t *q);
int      ds_pq_enqueue(ds_pq_t *q, void *data, double priority);
void    *ds_pq_dequeue(ds_pq_t *q);
void    *ds_pq_peek(const ds_pq_t *q);
void     ds_pq_clear(ds_pq_t *q);

#endif /* LIBDS_PRIORITY_QUEUE_H */
