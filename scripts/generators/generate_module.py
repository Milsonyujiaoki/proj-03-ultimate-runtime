#!/usr/bin/env python3
"""generate_module.py — Add a named module (subdirectory) to an existing library."""

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


def cmake_content(module: str, library: str) -> str:
    return f"""\
# {module} — module within {library}

target_sources({library} PRIVATE
    ${{CMAKE_CURRENT_SOURCE_DIR}}/{module}.c
)
"""


def header_content(module: str, library: str) -> str:
    guard = f"{library.upper()}_{module.upper()}_H"
    return f"""\
#ifndef {guard}
#define {guard}

/* {library}/{module} public API */

#endif /* {guard} */
"""


def source_content(module: str, library: str) -> str:
    return f"""\
#include "{library}/{module}.h"

/* {library}/{module} — implementation */
"""


def scaffold(module: str, library: str, dest: Path, dry: bool) -> None:
    lib_root = dest / "runtime" / library
    if not dry and not lib_root.exists():
        print(f"Error: library '{library}' not found at {lib_root}", file=sys.stderr)
        sys.exit(1)

    log(f"[module] {library}/{module}", YELLOW)

    src_dir = lib_root / "src" / module
    pub_dir = lib_root / "include" / "public" / library

    for d in [src_dir, pub_dir]:
        if not dry:
            d.mkdir(parents=True, exist_ok=True)
        log(f"  [dir]  {d.relative_to(dest)}", GREEN)

    files = {
        src_dir / f"{module}.c":              source_content(module, library),
        src_dir / "CMakeLists.txt":           cmake_content(module, library),
        pub_dir / f"{module}.h":              header_content(module, library),
    }
    for path, content in files.items():
        if not dry:
            if not path.exists():
                path.write_text(content)
        log(f"  [file] {path.relative_to(dest)}", GREEN)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("library", help="Target library (e.g. libft)")
    parser.add_argument("module",  help="New module name (e.g. string)")
    parser.add_argument("--dest", default=".", help="Monorepo root (default: .)")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    scaffold(args.module, args.library, Path(args.dest).resolve(), args.dry_run)
    if not args.dry_run:
        log("[OK] Module created.", GREEN)


if __name__ == "__main__":
    main()
