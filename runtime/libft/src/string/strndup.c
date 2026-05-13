#include "../../include/string.h"
#include "../../include/memory.h"
#include <stdio.h>
#include <stdlib.h>

char *ft_strndup(const char *src, size_t count){
    size_t len = ft_strlen(src);
    if (len > count) {
        len = count; // Limit the length to count
    }
    char *new_str = malloc(len + 1); // +1 for null terminator
    if (new_str == NULL) {
        return NULL; // Allocation failed
    }
    ft_memcpy(new_str, src, len);
    new_str[len] = '\0'; // Null-terminate the string
    return new_str;
}