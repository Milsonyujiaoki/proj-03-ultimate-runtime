#ifndef LIBFT_SYS_ERRNO_H
# define LIBFT_SYS_ERRNO_H

/*
** =========================================================
** errno — system error codes
**
** Delegates to the host system's <errno.h>.
** Provides ft_strerror() as a safe, portable description lookup.
** =========================================================
*/

# include <errno.h>

/* Return a read-only description string for errnum.
** Never returns NULL (returns "Unknown error" for unknown codes). */
const char *ft_strerror(int errnum);

#endif /* LIBFT_SYS_ERRNO_H */
