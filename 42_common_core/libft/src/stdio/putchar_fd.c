#include <libft.h>

void ft_putchar_fd(char c, int fd) {
    if (fd >= 0) {
        ft_write(fd, &c, 1);
    }
}