#ifndef LIBDS_CIRCULAR_LIST_H
#define LIBDS_CIRCULAR_LIST_H

#include <stddef.h>

typedef struct ds_cl ds_cl_t;

ds_cl_t *ds_cl_create(void);
void     ds_cl_destroy(ds_cl_t **self);
size_t   ds_cl_size(const ds_cl_t *l);
int      ds_cl_push(ds_cl_t *l, void *data);
void    *ds_cl_pop(ds_cl_t *l);
void    *ds_cl_peek(const ds_cl_t *l);
void     ds_cl_rotate(ds_cl_t *l, int steps);  /* negative = rotate backward */
void     ds_cl_clear(ds_cl_t *l);

#endif /* LIBDS_CIRCULAR_LIST_H */
