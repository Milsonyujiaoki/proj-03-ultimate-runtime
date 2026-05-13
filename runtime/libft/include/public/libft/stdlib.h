#ifndef LIBFT_STDLIB_H
#define LIBFT_STDLIB_H

/**
 * @brief Converts the initial portion of @p nptr to an int.
 *        Skips leading whitespace. Handles optional leading '+'/'-'.
 * @return Converted integer; 0 on empty / non-numeric input.
 * @note  MT-SAFE
 */
int   ft_atoi(const char *nptr);

/**
 * @brief Converts integer @p n to its decimal string representation.
 * @return Heap-allocated string — caller must free(). NULL on allocation failure.
 * @note  Handles INT_MIN correctly.
 */
char *ft_itoa(int n);

#endif /* LIBFT_STDLIB_H */
