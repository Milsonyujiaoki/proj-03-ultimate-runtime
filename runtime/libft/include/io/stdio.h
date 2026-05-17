#ifndef LIBFT_IO_STDIO_H
# define LIBFT_IO_STDIO_H

# include "../core/types.h"

/*
** =========================================================
** Standard I/O helpers
** =========================================================
*/

/*
** ──── Character I/O ────────────────────────────────────── */

int     ft_putchar(int c);
int     ft_getchar(void);

/*
** ──── String / numeric output ──────────────────────────── */

int     ft_puts(const char *str);

/* fd variants — write to an explicit file descriptor */
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(const char *str, int fd);
void    ft_putendl_fd(const char *str, int fd);
void    ft_putnbr_fd(int n, int fd);

/*
** ──── Formatted output ─────────────────────────────────── */

int     ft_printf(const char *fmt, ...);
int     ft_sprintf(char *buf, const char *fmt, ...);
int     ft_snprintf(char *buf, t_usize size, const char *fmt, ...);

#endif /* LIBFT_IO_STDIO_H */
