#include <unistd.h>
#include "internal/debug.h"
#include "string/string.h"

#ifdef LIBFT_DEBUG

/*
** =========================================================
** ft_assert_fail — called when LIBFT_ASSERT(expr) fails.
**
** Writes a diagnostic to stderr (fd 2) and triggers a trap.
** This function is marked LIBFT_NORETURN — it never returns.
** =========================================================
*/
LIBFT_NORETURN void ft_assert_fail(const char *file, int line,
                                   const char *expr)
{
    const char  *prefix = "[ASSERT FAILED] ";
    char         line_buf[16];
    int          i;
    int          tmp;

    /* Write prefix */
    write(2, prefix, ft_strlen(prefix));

    /* Write file name */
    write(2, file, ft_strlen(file));
    write(2, ":", 1);

    /* Write line number (manual itoa into local buffer) */
    i = 0;
    tmp = line;
    if (tmp == 0)
    {
        line_buf[i++] = '0';
    }
    else
    {
        while (tmp > 0)
        {
            line_buf[i++] = (char)('0' + tmp % 10);
            tmp /= 10;
        }
        /* Reverse */
        {
            int lo = 0;
            int hi = i - 1;
            char c;
            while (lo < hi)
            {
                c = line_buf[lo];
                line_buf[lo++] = line_buf[hi];
                line_buf[hi--] = c;
            }
        }
    }
    write(2, line_buf, (size_t)i);
    write(2, ": ", 2);

    /* Write expression */
    write(2, expr, ft_strlen(expr));
    write(2, "\n", 1);

    __builtin_trap();
}

#endif /* LIBFT_DEBUG */
