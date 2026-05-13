#ifndef LIBDS_DEQUE_H
#define LIBDS_DEQUE_H

#include <stddef.h>

typedef struct ds_deque ds_deque_t;

ds_deque_t *ds_deque_create(void);
void        ds_deque_destroy(ds_deque_t **self);
size_t      ds_deque_size(const ds_deque_t *d);
int         ds_deque_push_front(ds_deque_t *d, void *data);
int         ds_deque_push_back(ds_deque_t *d, void *data);
void       *ds_deque_pop_front(ds_deque_t *d);
void       *ds_deque_pop_back(ds_deque_t *d);
void       *ds_deque_peek_front(const ds_deque_t *d);
void       *ds_deque_peek_back(const ds_deque_t *d);
void        ds_deque_clear(ds_deque_t *d);

#endif /* LIBDS_DEQUE_H */
