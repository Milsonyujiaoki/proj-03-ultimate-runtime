#ifndef LIBDS_QUEUE_H
#define LIBDS_QUEUE_H

#include <stddef.h>

typedef struct ds_queue ds_queue_t;

ds_queue_t *ds_queue_create(void);
void        ds_queue_destroy(ds_queue_t **self);
size_t      ds_queue_size(const ds_queue_t *q);
int         ds_queue_enqueue(ds_queue_t *q, void *data);
void       *ds_queue_dequeue(ds_queue_t *q);
void       *ds_queue_peek(const ds_queue_t *q);
int         ds_queue_is_empty(const ds_queue_t *q);
void        ds_queue_clear(ds_queue_t *q);

#endif /* LIBDS_QUEUE_H */
