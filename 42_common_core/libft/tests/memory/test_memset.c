#include <string.h>
#include <stdio.h>

int main(void) {
    //criando um buffer e preenchendo metade dele com 'A' usando ft_memset
    char buffer[20];
    size_t metade = sizeof(buffer)/2;
    ft_memset(buffer, 'A', metade);
    printf("Buffer after memset: %s\n", buffer);

    // preenchendo a outra metade do buffer com 'B' usando ft_memset
    ft_memset(buffer + metade, 'B', metade);
    printf("Buffer after second memset: %s\n", buffer);

   // substituindo o conteúdo do buffer por 'C' usando ft_memset
    ft_memset(buffer, 'C', sizeof(buffer));
    printf("Buffer after third memset: %s\n", buffer);
    return 0;
}