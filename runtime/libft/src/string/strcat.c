#include "../../include/string.h"

char *ft_strcat(char *dest, const char *src) {
    char *ptr = dest;
    while (*ptr) ptr++;         // Vai até o fim do dest
    while (*src) *ptr++ = *src++; // Copia o src
    *ptr = '\0';                 // Finaliza
    return dest;
}
