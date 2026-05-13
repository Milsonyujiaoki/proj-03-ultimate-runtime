#ifndef LIBFT_UNISTD_H
#define LIBFT_UNISTD_H

#include <stddef.h>

/**
 * @brief Thin wrapper around the POSIX write(2) syscall.
 * @return Number of bytes written, or -1 on error (errno is set).
 */
long ft_write(int fd, const void *buf, size_t count);

/**
 * @brief Thin wrapper around the POSIX read(2) syscall.
 * @return Number of bytes read, 0 on EOF, or -1 on error (errno is set).
 */
long ft_read(int fd, void *buf, size_t count);

#endif /* LIBFT_UNISTD_H */
