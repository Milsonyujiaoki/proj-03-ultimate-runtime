#ifndef LIBDS_STACK_H
#define LIBDS_STACK_H

#include <stddef.h>

typedef struct ds_stack ds_stack_t;

ds_stack_t *ds_stack_create(void);
void        ds_stack_destroy(ds_stack_t **self);
size_t      ds_stack_size(const ds_stack_t *s);
int         ds_stack_push(ds_stack_t *s, void *data);
void       *ds_stack_pop(ds_stack_t *s);
void       *ds_stack_peek(const ds_stack_t *s);
int         ds_stack_is_empty(const ds_stack_t *s);
void        ds_stack_clear(ds_stack_t *s);

#endif /* LIBDS_STACK_H */
