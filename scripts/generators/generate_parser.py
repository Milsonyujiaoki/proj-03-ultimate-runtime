#!/usr/bin/env python3
"""generate_parser.py — Scaffold a recursive-descent parser for a given grammar."""

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


def lexer_h(name: str) -> str:
    g = name.upper()
    return f"""\
#ifndef {g}_LEXER_H
#define {g}_LEXER_H

#include <stddef.h>

typedef enum {{
    {g}_TOK_EOF = 0,
    {g}_TOK_UNKNOWN,
    /* TODO: add token types */
}} {name}_token_type_t;

typedef struct {{
    {name}_token_type_t type;
    const char         *start;
    size_t              length;
    int                 line;
}} {name}_token_t;

typedef struct {{
    const char   *source;
    size_t        pos;
    int           line;
}} {name}_lexer_t;

void          {name}_lexer_init({name}_lexer_t *lex, const char *src);
{name}_token_t {name}_lexer_next({name}_lexer_t *lex);

#endif /* {g}_LEXER_H */
"""


def parser_h(name: str) -> str:
    g = name.upper()
    return f"""\
#ifndef {g}_PARSER_H
#define {g}_PARSER_H

#include "{name}/lexer.h"

typedef struct {name}_node {name}_node_t;

struct {name}_node {{
    int           kind;
    {name}_node_t *left;
    {name}_node_t *right;
}};

typedef struct {{
    {name}_lexer_t lex;
    {name}_token_t current;
    int            had_error;
}} {name}_parser_t;

void          {name}_parser_init({name}_parser_t *p, const char *src);
{name}_node_t *{name}_parse({name}_parser_t *p);
void          {name}_node_free({name}_node_t *node);

#endif /* {g}_PARSER_H */
"""


def lexer_c(name: str) -> str:
    return f"""\
#include "{name}/lexer.h"
#include <string.h>

void {name}_lexer_init({name}_lexer_t *lex, const char *src)
{{
    lex->source = src;
    lex->pos    = 0;
    lex->line   = 1;
}}

{name}_token_t {name}_lexer_next({name}_lexer_t *lex)
{{
    {name}_token_t tok;
    tok.start  = lex->source + lex->pos;
    tok.length = 0;
    tok.line   = lex->line;
    tok.type   = {name.upper()}_TOK_UNKNOWN;

    if (lex->source[lex->pos] == '\\0') {{
        tok.type = {name.upper()}_TOK_EOF;
        return tok;
    }}

    /* TODO: implement tokenization */
    lex->pos++;
    tok.length = 1;
    return tok;
}}
"""


def parser_c(name: str) -> str:
    return f"""\
#include "{name}/parser.h"
#include <stdlib.h>

void {name}_parser_init({name}_parser_t *p, const char *src)
{{
    {name}_lexer_init(&p->lex, src);
    p->current    = {name}_lexer_next(&p->lex);
    p->had_error  = 0;
}}

{name}_node_t *{name}_parse({name}_parser_t *p)
{{
    /* TODO: implement grammar rules */
    (void)p;
    return NULL;
}}

void {name}_node_free({name}_node_t *node)
{{
    if (!node)
        return;
    {name}_node_free(node->left);
    {name}_node_free(node->right);
    free(node);
}}
"""


def cmake_content(name: str) -> str:
    return f"""\
cmake_minimum_required(VERSION 3.24)
project({name}_parser VERSION 0.1.0 LANGUAGES C)

include(../../../build_system/cmake/compiler_flags.cmake)
include(../../../build_system/cmake/warnings.cmake)

add_library({name}_parser STATIC
    src/lexer.c
    src/parser.c
)
target_include_directories({name}_parser
    PUBLIC  ${{CMAKE_CURRENT_SOURCE_DIR}}/include/public
    PRIVATE ${{CMAKE_CURRENT_SOURCE_DIR}}/include/private
)
ur_set_compile_flags({name}_parser)
ur_enable_warnings({name}_parser PRIVATE)
"""


def scaffold(name: str, dest: Path, dry: bool) -> None:
    root = dest / "parsers" / name
    log(f"[parser] Creating: {root}", YELLOW)

    dirs = [
        root / "src",
        root / "tests",
        root / "include" / "public" / name,
        root / "include" / "private",
        root / "docs",
        root / "fuzz",
    ]
    for d in dirs:
        if not dry:
            d.mkdir(parents=True, exist_ok=True)
        log(f"  [dir]  {d.relative_to(dest)}", GREEN)

    pub = root / "include" / "public" / name
    files = {
        root / "CMakeLists.txt": cmake_content(name),
        pub  / "lexer.h":        lexer_h(name),
        pub  / "parser.h":       parser_h(name),
        root / "src" / "lexer.c":  lexer_c(name),
        root / "src" / "parser.c": parser_c(name),
    }
    for path, content in files.items():
        if not dry:
            path.parent.mkdir(parents=True, exist_ok=True)
            if not path.exists():
                path.write_text(content)
        log(f"  [file] {path.relative_to(dest)}", GREEN)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("name", help="Parser / grammar name (e.g. json, mini_c)")
    parser.add_argument("--dest", default=".", help="Monorepo root (default: .)")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    scaffold(args.name, Path(args.dest).resolve(), args.dry_run)
    if not args.dry_run:
        log("[OK] Parser scaffolded.", GREEN)


if __name__ == "__main__":
    main()
