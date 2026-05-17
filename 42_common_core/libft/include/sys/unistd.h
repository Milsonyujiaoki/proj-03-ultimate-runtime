#ifndef LIBFT_SYS_UNISTD_H
# define LIBFT_SYS_UNISTD_H

# include "../core/types.h"


/*
** =========================================================
** POSIX unistd wrappers
**
** These are thin wrappers around the underlying syscalls.
** They preserve errno on error and return FT_ERR (-1) on
** failure, matching the POSIX convention.
** =========================================================
*/

t_isize  ft_read(int fd, void *buf, t_usize count);
t_isize  ft_write(int fd, const void *buf, t_usize count);
int      ft_close(int fd);

#endif /* LIBFT_SYS_UNISTD_H */
