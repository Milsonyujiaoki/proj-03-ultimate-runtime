#ifndef LIBFT_STDIO_H
#define LIBFT_STDIO_H

/**
 * @brief Writes character @p c to file descriptor @p fd.
 * @note  UNSAFE on concurrent writes to the same fd without external lock.
 */
void ft_putchar_fd(char c, int fd);

/**
 * @brief Writes string @p s to file descriptor @p fd.
 *        Does nothing if @p s is NULL.
 */
void ft_putstr_fd(char *s, int fd);

/**
 * @brief Writes string @p s followed by a newline to file descriptor @p fd.
 */
void ft_putendl_fd(char *s, int fd);

/**
 * @brief Writes the integer @p n in decimal to file descriptor @p fd.
 */
void ft_putnbr_fd(int n, int fd);

#endif /* LIBFT_STDIO_H */
