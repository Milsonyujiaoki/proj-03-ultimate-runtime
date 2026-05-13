#!/usr/bin/env python3
"""
create_structure.py — Ultimate Runtime Monorepo Scaffolding Script

Cria toda a estrutura de diretórios do monorepo ultimate-runtime.
Diretórios folha sem arquivos rastreados recebem .gitkeep automaticamente.

Usage:
    python3 create_structure.py [--dry-run] [--verbose] [--root PATH] [--validate]

Options:
    --dry-run    Lista todas as operações sem criar nada no disco
    --verbose    Log colorido por operação (implícito no --dry-run)
    --root PATH  Diretório raiz (padrão: diretório atual do script)
    --validate   Conta dirs/files criados após o scaffold

Requirements: Python 3.9+, zero dependências externas
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

# ─── ANSI color helpers ────────────────────────────────────────────────────────

_USE_COLOR = sys.stdout.isatty() and sys.platform != "win32" or (
    sys.platform == "win32" and "ANSICON" in __import__("os").environ
)

def _c(code: str, text: str) -> str:
    return f"\033[{code}m{text}\033[0m" if _USE_COLOR else text

def _green(t: str) -> str: return _c("92", t)
def _blue(t: str) -> str:  return _c("94", t)
def _yellow(t: str) -> str: return _c("93", t)
def _red(t: str) -> str:   return _c("91", t)
def _cyan(t: str) -> str:  return _c("96", t)
def _bold(t: str) -> str:  return _c("1",  t)


# ─── Logger ────────────────────────────────────────────────────────────────────

class Logger:
    def __init__(self, verbose: bool, dry: bool) -> None:
        self.verbose = verbose
        self.dry = dry
        self._dry_tag = _cyan("[DRY] ") if dry else ""

    def dir(self, p: Path) -> None:
        if self.verbose:
            print(f"{self._dry_tag}{_green('[DIR  ]')} {p}")

    def gitkeep(self, p: Path) -> None:
        if self.verbose:
            print(f"{self._dry_tag}{_yellow('[KEEP ]')} {p}")

    def file(self, p: Path) -> None:
        if self.verbose:
            print(f"{self._dry_tag}{_blue('[FILE ]')} {p}")

    def info(self, msg: str) -> None:
        print(f"{_cyan('[INFO ]')} {msg}")

    def ok(self, msg: str) -> None:
        print(f"{_green('[OK   ]')} {msg}")

    def err(self, msg: str) -> None:
        print(f"{_red('[ERR  ]')} {msg}", file=sys.stderr)

    def warn(self, msg: str) -> None:
        print(f"{_yellow('[WARN ]')} {msg}")

    def section(self, title: str) -> None:
        if self.verbose:
            print(f"\n{_bold(_cyan('── ' + title + ' ' + '─' * max(0, 48 - len(title))))}")


# ─── Filesystem operations ─────────────────────────────────────────────────────

def _make_dir(p: Path, dry: bool, log: Logger) -> bool:
    log.dir(p)
    if not dry:
        try:
            p.mkdir(parents=True, exist_ok=True)
        except Exception as exc:
            log.err(f"mkdir {p}: {exc}")
            return False
    return True


def _make_gitkeep(p: Path, dry: bool, log: Logger) -> bool:
    gk = p / ".gitkeep"
    log.gitkeep(gk)
    if not dry:
        try:
            p.mkdir(parents=True, exist_ok=True)
            if not gk.exists():
                gk.touch()
        except Exception as exc:
            log.err(f"gitkeep {gk}: {exc}")
            return False
    return True


# ─── Directory manifest ────────────────────────────────────────────────────────

def _gitkeep_dirs(R: Path) -> list[Path]:
    """Return all leaf directories that should receive a .gitkeep file."""
    return [
        # ── .github ─────────────────────────────────────────────────────────
        R / ".github/ISSUE_TEMPLATE",

        # ── docker ──────────────────────────────────────────────────────────
        R / "docker/development",
        R / "docker/testing",
        R / "docker/production",
        R / "docker/images",
        R / "docker/compose",

        # ── build_system ────────────────────────────────────────────────────
        R / "build_system/presets",
        R / "build_system/scripts",

        # ── scripts ─────────────────────────────────────────────────────────
        R / "scripts/bootstrap",
        R / "scripts/setup",
        R / "scripts/formatting",
        R / "scripts/testing",
        R / "scripts/fuzzing",
        R / "scripts/benchmarking",
        R / "scripts/profiling",
        R / "scripts/deployment",
        R / "scripts/ci",
        R / "scripts/maintenance",

        # ── templates ───────────────────────────────────────────────────────
        R / "templates/workspace",
        R / "templates/library",
        R / "templates/module",
        R / "templates/runtime",
        R / "templates/parser",
        R / "templates/networking",
        R / "templates/graphics",
        R / "templates/ai",
        R / "templates/database",
        R / "templates/security",
        R / "templates/application",
        R / "templates/42_project",

        # ── tools/formatter ─────────────────────────────────────────────────
        R / "tools/formatter/clang-format",
        R / "tools/formatter/clang-tidy",

        # ── tools/static_analysis ───────────────────────────────────────────
        R / "tools/static_analysis/cppcheck",
        R / "tools/static_analysis/valgrind",
        R / "tools/static_analysis/sanitizers",
        R / "tools/static_analysis/scan-build",

        # ── tools/profiling ─────────────────────────────────────────────────
        R / "tools/profiling/perf",
        R / "tools/profiling/flamegraph",
        R / "tools/profiling/heaptrack",
        R / "tools/profiling/tracy",

        # ── tools/debugging ─────────────────────────────────────────────────
        R / "tools/debugging/gdb",
        R / "tools/debugging/lldb",
        R / "tools/debugging/rr",

        # ── tools/misc ──────────────────────────────────────────────────────
        R / "tools/fuzzing",
        R / "tools/benchmarking",
        R / "tools/instrumentation",
        R / "tools/codegen",
        R / "tools/generators",

        # ── docs ────────────────────────────────────────────────────────────
        R / "docs/architecture",
        R / "docs/internals",
        R / "docs/api",
        R / "docs/guides",
        R / "docs/tutorials",
        R / "docs/protocols",
        R / "docs/diagrams",
        R / "docs/benchmarks",
        R / "docs/references",
        R / "docs/papers",

        # ── specs ───────────────────────────────────────────────────────────
        R / "specs/runtime",
        R / "specs/vm",
        R / "specs/memory",
        R / "specs/threading",
        R / "specs/network",
        R / "specs/database",
        R / "specs/api",
        R / "specs/protocols",
        R / "specs/formats",
        R / "specs/security",

        # ── research ────────────────────────────────────────────────────────
        R / "research/papers",
        R / "research/notes",
        R / "research/experiments",
        R / "research/prototypes",
        R / "research/benchmarks",
        R / "research/reverse_engineering",
        R / "research/references",
        R / "research/studies",

        # ── sdk ─────────────────────────────────────────────────────────────
        R / "sdk/c",
        R / "sdk/cpp",
        R / "sdk/rust",
        R / "sdk/python",
        R / "sdk/lua",
        R / "sdk/wasm",
        R / "sdk/bindings",

        # ── third_party ─────────────────────────────────────────────────────
        R / "third_party/minilibx",
        R / "third_party/glfw",
        R / "third_party/vulkan",
        R / "third_party/sdl",
        R / "third_party/openssl",
        R / "third_party/zlib",
        R / "third_party/protobuf",
        R / "third_party/sqlite",
        R / "third_party/curl",
        R / "third_party/nghttp2",
        R / "third_party/libuv",
        R / "third_party/llvm",
        R / "third_party/tree-sitter",

        # ── playground ──────────────────────────────────────────────────────
        R / "playground/sandbox",
        R / "playground/experiments",
        R / "playground/prototypes",
        R / "playground/benchmarks",
        R / "playground/fuzzing",
        R / "playground/profiling",

        # ── tests ───────────────────────────────────────────────────────────
        R / "tests/unit",
        R / "tests/integration",
        R / "tests/regression",
        R / "tests/performance",
        R / "tests/fuzz",
        R / "tests/stress",
        R / "tests/compatibility",
        R / "tests/security",

        # ── assets ──────────────────────────────────────────────────────────
        R / "assets/textures",
        R / "assets/audio",
        R / "assets/fonts",
        R / "assets/shaders",
        R / "assets/icons",
        R / "assets/datasets",

        # ── runtime/foundation ──────────────────────────────────────────────
        R / "runtime/foundation/memory",
        R / "runtime/foundation/allocators",
        R / "runtime/foundation/atomics",
        R / "runtime/foundation/threading",
        R / "runtime/foundation/synchronization",
        R / "runtime/foundation/unicode",
        R / "runtime/foundation/utf8",
        R / "runtime/foundation/hashing",
        R / "runtime/foundation/strings",
        R / "runtime/foundation/logging",
        R / "runtime/foundation/tracing",
        R / "runtime/foundation/assertions",
        R / "runtime/foundation/diagnostics",
        R / "runtime/foundation/intrusive",
        R / "runtime/foundation/arena",
        R / "runtime/foundation/config",
        R / "runtime/foundation/platform",
        R / "runtime/foundation/error",

        # ── runtime/coreutils ───────────────────────────────────────────────
        R / "runtime/coreutils/logging",
        R / "runtime/coreutils/tracing",
        R / "runtime/coreutils/panic",
        R / "runtime/coreutils/assert",
        R / "runtime/coreutils/allocator",
        R / "runtime/coreutils/hashing",
        R / "runtime/coreutils/atomic",
        R / "runtime/coreutils/threading",
        R / "runtime/coreutils/platform",
        R / "runtime/coreutils/unicode",
        R / "runtime/coreutils/utf8",
        R / "runtime/coreutils/config",
        R / "runtime/coreutils/intrusive",
        R / "runtime/coreutils/arena",
        R / "runtime/coreutils/error",
        R / "runtime/coreutils/diagnostics",

        # ── runtime/platform ────────────────────────────────────────────────
        R / "runtime/platform/linux",
        R / "runtime/platform/macos",
        R / "runtime/platform/windows",
        R / "runtime/platform/posix",
        R / "runtime/platform/wasm",

        # ── runtime/core ────────────────────────────────────────────────────
        R / "runtime/core/scheduler",
        R / "runtime/core/event_loop",
        R / "runtime/core/async",
        R / "runtime/core/coroutine",
        R / "runtime/core/fiber",
        R / "runtime/core/threading",
        R / "runtime/core/object_system",
        R / "runtime/core/reflection",
        R / "runtime/core/module_loader",
        R / "runtime/core/plugin",
        R / "runtime/core/profiler",
        R / "runtime/core/logger",
        R / "runtime/core/tracing",

        # ── runtime/vm ──────────────────────────────────────────────────────
        R / "runtime/vm/bytecode",
        R / "runtime/vm/interpreter",
        R / "runtime/vm/jit",
        R / "runtime/vm/garbage_collector",
        R / "runtime/vm/optimizer",
        R / "runtime/vm/execution",
        R / "runtime/vm/debugger",

        # ── runtime/services ────────────────────────────────────────────────
        R / "runtime/services/networking",
        R / "runtime/services/database",
        R / "runtime/services/serialization",
        R / "runtime/services/storage",
        R / "runtime/services/caching",

        # ── runtime/libft (empty subdirs) ───────────────────────────────────
        R / "runtime/libft/include/private",
        R / "runtime/libft/include/internal",
        R / "runtime/libft/src/string",
        R / "runtime/libft/src/memory",
        R / "runtime/libft/src/ctype",
        R / "runtime/libft/src/io",
        R / "runtime/libft/src/conversion",
        R / "runtime/libft/src/alloc",
        R / "runtime/libft/src/math",
        R / "runtime/libft/src/time",
        R / "runtime/libft/src/internal",
        R / "runtime/libft/tests/unit",
        R / "runtime/libft/tests/integration",
        R / "runtime/libft/tests/regression",
        R / "runtime/libft/tests/fuzz",
        R / "runtime/libft/tests/performance",
        R / "runtime/libft/benchmarks",
        R / "runtime/libft/fuzz",
        R / "runtime/libft/examples",
        R / "runtime/libft/docs",
        R / "runtime/libft/scripts",
        R / "runtime/libft/tools",
        R / "runtime/libft/build",
        R / "runtime/libft/bin",
        R / "runtime/libft/tmp",

        # ── runtime/libds (empty subdirs) ───────────────────────────────────
        R / "runtime/libds/include/private",
        R / "runtime/libds/include/internal",
        R / "runtime/libds/src/vector",
        R / "runtime/libds/src/linked_list",
        R / "runtime/libds/src/doubly_linked_list",
        R / "runtime/libds/src/circular_list",
        R / "runtime/libds/src/stack",
        R / "runtime/libds/src/queue",
        R / "runtime/libds/src/deque",
        R / "runtime/libds/src/hashmap",
        R / "runtime/libds/src/hashset",
        R / "runtime/libds/src/tree",
        R / "runtime/libds/src/graph",
        R / "runtime/libds/src/allocator",
        R / "runtime/libds/src/cache",
        R / "runtime/libds/src/string",
        R / "runtime/libds/src/advanced",
        R / "runtime/libds/tests",
        R / "runtime/libds/benchmarks",
        R / "runtime/libds/fuzz",
        R / "runtime/libds/examples",
        R / "runtime/libds/docs",
        R / "runtime/libds/scripts",
        R / "runtime/libds/build",
        R / "runtime/libds/bin",
        R / "runtime/libds/tmp",

        # ── runtime/libalgo ─────────────────────────────────────────────────
        R / "runtime/libalgo/sorting",
        R / "runtime/libalgo/searching",
        R / "runtime/libalgo/graph",
        R / "runtime/libalgo/dynamic_programming",
        R / "runtime/libalgo/geometry",
        R / "runtime/libalgo/optimization",
        R / "runtime/libalgo/compression",
        R / "runtime/libalgo/cryptography",
        R / "runtime/libalgo/scheduling",
        R / "runtime/libalgo/pathfinding",
        R / "runtime/libalgo/string_matching",
        R / "runtime/libalgo/probabilistic",
        R / "runtime/libalgo/parallel",

        # ── runtime/libparser ───────────────────────────────────────────────
        R / "runtime/libparser/lexer",
        R / "runtime/libparser/tokenizer",
        R / "runtime/libparser/parser",
        R / "runtime/libparser/ast",
        R / "runtime/libparser/formatter",
        R / "runtime/libparser/shell",
        R / "runtime/libparser/json",
        R / "runtime/libparser/yaml",
        R / "runtime/libparser/toml",
        R / "runtime/libparser/xml",
        R / "runtime/libparser/csv",
        R / "runtime/libparser/ini",
        R / "runtime/libparser/markdown",
        R / "runtime/libparser/regex",
        R / "runtime/libparser/bytecode",

        # ── runtime/lib* standalone ─────────────────────────────────────────
        R / "runtime/libgraphics",
        R / "runtime/libnet",
        R / "runtime/libruntime",
        R / "runtime/libdatabase",
        R / "runtime/libai",
        R / "runtime/libsecurity",

        # ── 42_common_core ──────────────────────────────────────────────────
        R / "42_common_core/libft",
        R / "42_common_core/born2beroot",
        R / "42_common_core/ft_printf",
        R / "42_common_core/get_next_line",
        R / "42_common_core/push_swap",
        R / "42_common_core/pipex",
        R / "42_common_core/so_long",
        R / "42_common_core/fractol",
        R / "42_common_core/philosophers",
        R / "42_common_core/minishell",
        R / "42_common_core/minitalk",
        R / "42_common_core/netpractice",
        R / "42_common_core/cub3d",
        R / "42_common_core/miniRT",
        R / "42_common_core/cpp_modules",
        R / "42_common_core/webserv",
        R / "42_common_core/ft_irc",
        R / "42_common_core/inception",
        R / "42_common_core/transcendence",
        R / "42_common_core/exam_rank",

        # ── 42_specializations/graphics ─────────────────────────────────────
        R / "42_specializations/graphics/doom_engine",
        R / "42_specializations/graphics/renderer",
        R / "42_specializations/graphics/game_engine",
        R / "42_specializations/graphics/vulkan_renderer",

        # ── 42_specializations/cybersecurity ────────────────────────────────
        R / "42_specializations/cybersecurity/malware_analysis",
        R / "42_specializations/cybersecurity/packet_sniffer",
        R / "42_specializations/cybersecurity/reverse_engineering",
        R / "42_specializations/cybersecurity/exploit_lab",
        R / "42_specializations/cybersecurity/secure_server",

        # ── 42_specializations/devops ────────────────────────────────────────
        R / "42_specializations/devops/kubernetes",
        R / "42_specializations/devops/terraform",
        R / "42_specializations/devops/ci_cd",
        R / "42_specializations/devops/monitoring",
        R / "42_specializations/devops/observability",

        # ── 42_specializations/ai ────────────────────────────────────────────
        R / "42_specializations/ai/neural_network",
        R / "42_specializations/ai/inference_engine",
        R / "42_specializations/ai/llm_runtime",
        R / "42_specializations/ai/vector_database",
        R / "42_specializations/ai/distributed_training",

        # ── 42_specializations/systems ───────────────────────────────────────
        R / "42_specializations/systems/mini_kernel",
        R / "42_specializations/systems/bootloader",
        R / "42_specializations/systems/filesystem",
        R / "42_specializations/systems/compiler",
        R / "42_specializations/systems/interpreter",
        R / "42_specializations/systems/vm",
        R / "42_specializations/systems/container_runtime",
        R / "42_specializations/systems/distributed_runtime",

        # ── 42_specializations/networking ────────────────────────────────────
        R / "42_specializations/networking/http_server",
        R / "42_specializations/networking/grpc_gateway",
        R / "42_specializations/networking/websocket_server",
        R / "42_specializations/networking/reverse_proxy",
        R / "42_specializations/networking/service_mesh",
        R / "42_specializations/networking/message_broker",
        R / "42_specializations/networking/distributed_cache",
        R / "42_specializations/networking/api_gateway",

        # ── applications/cli ─────────────────────────────────────────────────
        R / "applications/cli/shell",
        R / "applications/cli/debugger",
        R / "applications/cli/terminal",
        R / "applications/cli/package_manager",

        # ── applications/distributed ─────────────────────────────────────────
        R / "applications/distributed/distributed_queue",
        R / "applications/distributed/distributed_database",
        R / "applications/distributed/service_mesh",
        R / "applications/distributed/cloud_platform",

        # ── applications/ai ──────────────────────────────────────────────────
        R / "applications/ai/ai_assistant_runtime",
        R / "applications/ai/vector_database",
        R / "applications/ai/inference_server",

        # ── applications/systems ─────────────────────────────────────────────
        R / "applications/systems/mini_docker",
        R / "applications/systems/mini_kubernetes",
        R / "applications/systems/operating_system",

        # ── applications/graphics ────────────────────────────────────────────
        R / "applications/graphics/browser",
        R / "applications/graphics/game_engine",
        R / "applications/graphics/renderer",

        # ── applications/backend ─────────────────────────────────────────────
        R / "applications/backend/reverse_proxy",
        R / "applications/backend/streaming_server",
        R / "applications/backend/monitoring_system",
        R / "applications/backend/observability_platform",
    ]


# ─── Scaffold orchestrator ─────────────────────────────────────────────────────

def scaffold(root: Path, dry: bool, verbose: bool) -> tuple[int, int, int]:
    """
    Create the full monorepo directory structure.
    Returns (dirs_ok, errors, total).
    """
    log = Logger(verbose=verbose, dry=dry)
    dirs = _gitkeep_dirs(root)
    total = len(dirs)
    ok = 0
    errors = 0

    log.info(_bold(f"ultimate-runtime — Monorepo Scaffolding"))
    log.info(f"Root     : {root.resolve()}")
    log.info(f"Mode     : {'DRY-RUN (nothing written)' if dry else 'LIVE'}")
    log.info(f"Dirs     : {total} leaf directories to create")
    print()

    log.section("Creating directory tree")
    for d in dirs:
        if _make_gitkeep(d, dry, log):
            ok += 1
        else:
            errors += 1

    print()
    log.info("─" * 52)
    log.info(f"Directories created : {ok}/{total}")
    if errors:
        log.warn(f"Errors              : {errors}  ← check stderr")
    else:
        log.ok("No errors. Directory tree created successfully.")

    return ok, errors, total


def validate_structure(root: Path, log: Logger) -> None:
    """Walk the tree and report counts."""
    all_dirs  = sum(1 for p in root.rglob("*") if p.is_dir())
    all_files = sum(1 for p in root.rglob("*") if p.is_file())
    gitkeeps  = sum(1 for p in root.rglob(".gitkeep"))

    log.info("─" * 52)
    log.info("Validation (filesystem scan):")
    log.info(f"  Total directories : {all_dirs}")
    log.info(f"  Total files       : {all_files}")
    log.info(f"  .gitkeep markers  : {gitkeeps}")


# ─── Entry point ───────────────────────────────────────────────────────────────

def _build_parser() -> argparse.ArgumentParser:
    p = argparse.ArgumentParser(
        prog="create_structure.py",
        description="Ultimate Runtime — Monorepo Scaffolding Script",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__,
    )
    p.add_argument("--dry-run",  action="store_true",
                   help="List operations without writing anything")
    p.add_argument("--verbose", "-v", action="store_true",
                   help="Print every dir/file operation")
    p.add_argument("--root", default=None,
                   help="Root directory (default: directory containing this script)")
    p.add_argument("--validate", action="store_true",
                   help="Run a filesystem scan after scaffolding")
    return p


def main() -> None:
    args = _build_parser().parse_args()

    root = Path(args.root).resolve() if args.root else Path(__file__).parent.resolve()
    dry  = args.dry_run
    verbose = args.verbose or dry

    _, errors, _ = scaffold(root, dry=dry, verbose=verbose)

    if args.validate and not dry:
        log = Logger(verbose=True, dry=False)
        validate_structure(root, log)

    sys.exit(1 if errors else 0)


if __name__ == "__main__":
    main()
