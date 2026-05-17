#ifndef LIBFT_H
# define LIBFT_H

/*
** =========================================================
** libft — Foundation Library  v0.3.0
** =========================================================
** Unified public API entrypoint.
**
** Client code should only ever #include "libft.h".
** Individual module headers are an implementation detail.
**
** Feature flags (define BEFORE including this header):
**   -DLIBFT_NO_DS       disable data structures module
**   -DLIBFT_NO_ALGO     disable algorithms module
**   -DLIBFT_NO_ARENA    disable arena allocator
**   -DLIBFT_NO_POOL     disable object pool allocator
**   -DLIBFT_DEBUG       enable assertions and debug output
** =========================================================
*/

/* ── Core foundation ─────────────────────────────────── */
# include "core/types.h"
# include "core/compiler.h"
# include "core/macros.h"
# include "core/config.h"
# include "core/defs.h"
# include "core/ctype.h"

/* ── Memory ──────────────────────────────────────────── */
# include "memory/memory.h"
# include "memory/alloc.h"
# ifdef LIBFT_FEATURE_ARENA
#  include "memory/arena.h"
# endif
# ifdef LIBFT_FEATURE_POOL
#  include "memory/pool.h"
# endif
# include "memory/buffer.h"

/* ── String ──────────────────────────────────────────── */
# include "string/string.h"

# include "string/string_builder.h"

/* ── Data Structures ─────────────────────────────────── */
# ifdef LIBFT_FEATURE_DS
#  include "ds/slist.h"
//#  include "ds/list.h"
#  include "ds/dlist.h"
#  include "ds/vector.h"
#  include "ds/stack.h"
#  include "ds/queue.h"
# endif

/* ── Algorithms ──────────────────────────────────────── */
# ifdef LIBFT_FEATURE_ALGO
#  include "algo/sort.h"
#  include "algo/search.h"
#  include "algo/hash.h"
#  include "algo/compare.h"
# endif

/* ── I/O ─────────────────────────────────────────────── */
# include "io/stdio.h"
# include "io/file.h"

/* ── System ──────────────────────────────────────────── */
# include "sys/errno.h"
# include "sys/unistd.h"

/* ── stdlib conversions ──────────────────────────────── */
# include "core/stdlib-ft.h"


#include "ctype.h"
#include "string.h"
#include "memory.h"


#endif /* LIBFT_H */
