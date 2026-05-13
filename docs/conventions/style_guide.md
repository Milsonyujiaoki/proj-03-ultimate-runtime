# Style Guide

## Language Standards

| Language | Standard |
|----------|----------|
| C        | C17 (`-std=c17`)   |
| C++      | C++20 (`-std=c++20`) |
| Python   | 3.9+               |
| Shell    | Bash 4+            |
| CMake    | 3.24+              |

## C Style

Formatter: **clang-format** (Google base, IndentWidth=4, ColumnLimit=100).  
Run: `make fmt`

### Braces and Indentation

```c
/* One true brace style — opening brace on same line for control flow */
if (condition) {
    do_something();
} else {
    do_other();
}

/* Functions: opening brace on its own line (K&R exception for functions) */
int
ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (s[len])
        len++;
    return (int)len;
}
```

### Blank Lines

- One blank line between functions.
- No blank lines at the start or end of a function body.
- Two blank lines before a top-level section comment.

### Comments

```c
/* Single-line comments use this style */

/*
** Multi-line comments use this style
** (42 norm compatible)
*/

// C++ line comments are allowed in C++ files only
```

### Includes

Order (separated by blank lines):

1. Corresponding header (`"libft/string.h"`)
2. Project headers (`"libft/memory.h"`)
3. System headers (`<string.h>`, `<stddef.h>`)

## Python Style

- **PEP 8** with 4-space indentation.
- Line limit: 100 characters.
- Type hints on all public functions.
- f-strings over `.format()`.

## Commit Style

[Conventional Commits](https://www.conventionalcommits.org):

```
<type>(<scope>): <short description>

[optional body]

[optional footer]
```

Types: `feat`, `fix`, `refactor`, `perf`, `docs`, `test`, `chore`, `security`, `build`, `ci`.
