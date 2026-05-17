#ifndef LIBFT_INTERNAL_DEBUG_H
# define LIBFT_INTERNAL_DEBUG_H

# include "../core/types.h"
# include "../core/compiler.h"
# include "../core/macros.h"

/*
** =========================================================
** Debug macros  (internal — NOT part of the public API)
**
** LIBFT_ASSERT — active only when LIBFT_DEBUG is defined.
**   In release builds the expression is still evaluated
**   (to avoid side-effect divergence) but the check is
**   compiled away.
**
** LIBFT_PANIC — always active.  Terminates the program
**   unconditionally (e.g. for truly unreachable branches).
**
** Usage:
**   LIBFT_ASSERT(ptr != NULL);
**   LIBFT_PANIC("unreachable branch in ft_vector_get");
** =========================================================
*/

# ifdef LIBFT_DEBUG

/*
** ft_assert_fail is implemented in src/internal/debug.c.
** It writes a diagnostic to fd 2 (stderr) and traps.
*/
LIBFT_NORETURN void ft_assert_fail(const char *file, int line,
                                   const char *expr);

#  define LIBFT_ASSERT(expr) \
    do { \
        if (LIBFT_UNLIKELY(!(expr))) \
            ft_assert_fail(__FILE__, __LINE__, #expr); \
    } while (0)

# else
#  define LIBFT_ASSERT(expr)  ((void)(expr))
# endif /* LIBFT_DEBUG */

/* Always-on: unconditional termination with source location. */
# define LIBFT_PANIC(msg) \
    do { \
        const char *_msg = "[PANIC] " __FILE__ ":" \
            LIBFT_TOSTRING(__LINE__) ": " msg "\n"; \
        (void)_msg; \
        __builtin_trap(); \
    } while (0)

#endif /* LIBFT_INTERNAL_DEBUG_H */
