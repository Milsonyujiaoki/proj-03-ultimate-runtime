#ifndef LIBDS_VECTOR_H
#define LIBDS_VECTOR_H

#include <stddef.h>

typedef struct ds_vector ds_vector_t;

/** @brief Create a vector with initial @p capacity (0 = default). */
ds_vector_t *ds_vector_create(size_t capacity);
void         ds_vector_destroy(ds_vector_t **self);
size_t       ds_vector_size(const ds_vector_t *v);
size_t       ds_vector_capacity(const ds_vector_t *v);
int          ds_vector_push_back(ds_vector_t *v, void *item);
void        *ds_vector_pop_back(ds_vector_t *v);
void        *ds_vector_get(const ds_vector_t *v, size_t index);
int          ds_vector_set(ds_vector_t *v, size_t index, void *item);
int          ds_vector_reserve(ds_vector_t *v, size_t new_cap);
void         ds_vector_clear(ds_vector_t *v);

#endif /* LIBDS_VECTOR_H */
