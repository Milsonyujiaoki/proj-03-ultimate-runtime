#ifndef LIBFT_CTYPE_H
#define LIBFT_CTYPE_H

/** @brief Non-zero if @p c is an alphabetic character. @note MT-SAFE/re */
int ft_isalpha(int c);

/** @brief Non-zero if @p c is a decimal digit. @note MT-SAFE/re */
int ft_isdigit(int c);

/** @brief Non-zero if @p c is alphanumeric. @note MT-SAFE/re */
int ft_isalnum(int c);

/** @brief Non-zero if @p c is in the range 0–127. @note MT-SAFE/re */
int ft_isascii(int c);

/** @brief Non-zero if @p c is a printable character (0x20–0x7e). @note MT-SAFE/re */
int ft_isprint(int c);

/** @brief Returns the uppercase equivalent of @p c, or @p c if not a lowercase letter. */
int ft_toupper(int c);

/** @brief Returns the lowercase equivalent of @p c, or @p c if not an uppercase letter. */
int ft_tolower(int c);

#endif /* LIBFT_CTYPE_H */
