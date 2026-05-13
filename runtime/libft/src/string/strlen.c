#include "../../include/string.h"

size_t ft_strlen(const char *str) {
	    const char *start = str;

	    while (*str) {
	     str++;
	     }

	     return (size_t)(str - start);
 }
