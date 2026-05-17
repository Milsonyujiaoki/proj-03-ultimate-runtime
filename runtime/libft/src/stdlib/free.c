#include <stdlib.h>
#include "memory/alloc.h"

/*
** ft_free — wraps the system free.
*/
void    ft_free(void *ptr)
{
    free(ptr);
}
