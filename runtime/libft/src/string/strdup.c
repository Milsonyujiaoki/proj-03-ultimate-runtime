#include "../../include/string.h"
#include "../../include/memory.h"
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *src)
{
    size_t len = ft_strlen(src) + 1;
    char *new_str = malloc(len);
    if (new_str == NULL) {
        return NULL; // Allocation failed
    }
    ft_memcpy(new_str, src, len);
    return new_str;
}