#!/usr/bin/env python3
"""generate_42_project.py — Scaffold a 42 School project workspace."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

ANSI = not (sys.platform == "win32" and not sys.stdout.isatty())
GREEN  = "\033[32m" if ANSI else ""
YELLOW = "\033[33m" if ANSI else ""
RESET  = "\033[0m"  if ANSI else ""


def log(msg: str, color: str = "") -> None:
    print(f"{color}{msg}{RESET}")


KNOWN_PROJECTS = [
    "libft", "ft_printf", "get_next_line", "born2beroot",
    "minitalk", "push_swap", "pipex", "so_long", "fdf",
    "minishell", "philosophers", "minirt", "cub3d",
    "netpractice", "cpp_modules", "inception", "ft_irc",
    "ft_transcendence",
]


def makefile_content(name: str) -> str:
    return f"""\
NAME    = {name}
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=c17
AR      = ar rcs
SRCS    = src/main.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
\t$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:
\t@echo "No bonus targets."

clean:
\trm -f $(OBJS)

fclean: clean
\trm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
"""


def main_c_content(name: str) -> str:
    return f"""\
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{{
    (void)argc;
    (void)argv;
    printf("{name}\\n");
    return EXIT_SUCCESS;
}}
"""


def readme_content(name: str) -> str:
    return f"""\
# {name}

> 42 School — {name}

## Description

TODO: describe the project.

## Usage

```sh
make
./{name}
```

## Tests

```sh
make re && ./{name}
```
"""


def scaffold(name: str, dest: Path, grade: str, dry: bool) -> None:
    root = dest / "school" / "42" / grade / name
    log(f"[42-project] Creating: {root}", YELLOW)

    dirs = [
        root / "src",
        root / "include",
        root / "tests",
        root / "docs",
        root / "bonus" / "src",
    ]
    for d in dirs:
        if not dry:
            d.mkdir(parents=True, exist_ok=True)
        log(f"  [dir]  {d.relative_to(dest)}", GREEN)

    files = {
        root / "Makefile":       makefile_content(name),
        root / "src" / "main.c": main_c_content(name),
        root / "README.md":      readme_content(name),
    }
    for path, content in files.items():
        if not dry:
            path.parent.mkdir(parents=True, exist_ok=True)
            if not path.exists():
                path.write_text(content)
        log(f"  [file] {path.relative_to(dest)}", GREEN)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("name",
        help=f"Project name. Known projects: {', '.join(KNOWN_PROJECTS)}")
    parser.add_argument("--grade", default="common_core",
        choices=["common_core", "outer_core", "piscine"],
        help="School grade tier (default: common_core)")
    parser.add_argument("--dest", default=".", help="Monorepo root (default: .)")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    scaffold(args.name, Path(args.dest).resolve(), args.grade, args.dry_run)
    if not args.dry_run:
        log("[OK] 42 project scaffolded.", GREEN)


if __name__ == "__main__":
    main()
