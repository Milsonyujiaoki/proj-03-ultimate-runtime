#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char src[] = "Hello, World!";
    char dest[60]; // Ensure this is large enough to hold the copied string

    ft_strncpy(dest, src, 6); // Copy only the first 6 characters

    printf("Source: %s | Endereço %p\n", src, (void *)src);
    printf("Destination: %s | Endereço %p\n", dest, (void *)dest);

    return 0;
}