#!/usr/bin/env python3
"""generate_networking.py — Scaffold a networking module (TCP, UDP, HTTP, WebSocket…)."""

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


PROTOCOLS = ["tcp", "udp", "http", "websocket", "tls", "dns"]


def cmake_content(name: str) -> str:
    return f"""\
cmake_minimum_required(VERSION 3.24)
project(net_{name} VERSION 0.1.0 LANGUAGES C)

include(../../../build_system/cmake/compiler_flags.cmake)
include(../../../build_system/cmake/warnings.cmake)

add_library(net_{name} STATIC src/{name}.c)
target_include_directories(net_{name}
    PUBLIC  ${{CMAKE_CURRENT_SOURCE_DIR}}/include/public
    PRIVATE ${{CMAKE_CURRENT_SOURCE_DIR}}/include/private
)
ur_set_compile_flags(net_{name})
ur_enable_warnings(net_{name} PRIVATE)

if(UNIX)
    target_link_libraries(net_{name} PRIVATE m)
endif()
"""


def header_content(name: str) -> str:
    g = f"NET_{name.upper()}_H"
    return f"""\
#ifndef {g}
#define {g}

#include <stddef.h>
#include <stdint.h>

/* networking/{name} — public API */

typedef struct net_{name}_ctx net_{name}_ctx_t;

net_{name}_ctx_t *net_{name}_create(void);
void              net_{name}_destroy(net_{name}_ctx_t *ctx);

#endif /* {g} */
"""


def source_content(name: str) -> str:
    return f"""\
#include "net/{name}.h"
#include <stdlib.h>

struct net_{name}_ctx {{
    int fd;
}};

net_{name}_ctx_t *net_{name}_create(void)
{{
    net_{name}_ctx_t *ctx = calloc(1, sizeof(*ctx));
    return ctx;
}}

void net_{name}_destroy(net_{name}_ctx_t *ctx)
{{
    free(ctx);
}}
"""


def scaffold(name: str, dest: Path, dry: bool) -> None:
    root = dest / "networking" / name
    log(f"[networking] Creating: {root}", YELLOW)

    dirs = [
        root / "src",
        root / "tests",
        root / "include" / "public" / "net",
        root / "include" / "private",
        root / "docs",
        root / "fuzz",
    ]
    for d in dirs:
        if not dry:
            d.mkdir(parents=True, exist_ok=True)
        log(f"  [dir]  {d.relative_to(dest)}", GREEN)

    pub = root / "include" / "public" / "net"
    files = {
        root / "CMakeLists.txt":   cmake_content(name),
        pub  / f"{name}.h":        header_content(name),
        root / "src" / f"{name}.c": source_content(name),
    }
    for path, content in files.items():
        if not dry:
            path.parent.mkdir(parents=True, exist_ok=True)
            if not path.exists():
                path.write_text(content)
        log(f"  [file] {path.relative_to(dest)}", GREEN)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("name", help=f"Protocol/module name. Suggested: {', '.join(PROTOCOLS)}")
    parser.add_argument("--dest", default=".", help="Monorepo root (default: .)")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    scaffold(args.name, Path(args.dest).resolve(), args.dry_run)
    if not args.dry_run:
        log("[OK] Networking module scaffolded.", GREEN)


if __name__ == "__main__":
    main()
