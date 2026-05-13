#include "../../include/string.h"

char *ft_strncat(char *dest, const char *src, size_t count) {
    char *ptr = dest;
    while (*ptr) ptr++;         // Vai até o fim do dest
    while (*src && count--) *ptr++ = *src++; // Copia até count ou fim do src
    *ptr = '\0';                 // Finaliza
    return dest;
}