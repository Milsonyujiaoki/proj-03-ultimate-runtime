#!/usr/bin/env bash
# =============================================================================
# create_structure.sh — Ultimate Runtime Monorepo Scaffolding
# =============================================================================
# Creates the full directory tree for the ultimate-runtime monorepo.
# Idempotent: safe to re-run. Adds .gitkeep to all leaf directories.
#
# Usage:
#   bash create_structure.sh [ROOT_DIR]
#
# Arguments:
#   ROOT_DIR   Optional root path. Defaults to the directory containing
#              this script.
#
# Requirements: bash 4+, coreutils (mkdir, touch, find)
# =============================================================================

set -euo pipefail

# ── Resolve root ──────────────────────────────────────────────────────────────
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="${1:-$SCRIPT_DIR}"

# ── Colors ────────────────────────────────────────────────────────────────────
if [ -t 1 ]; then
  C_RESET="\033[0m"; C_GREEN="\033[92m"; C_CYAN="\033[96m"
  C_YELLOW="\033[93m"; C_BOLD="\033[1m"
else
  C_RESET=""; C_GREEN=""; C_CYAN=""; C_YELLOW=""; C_BOLD=""
fi

log_info()    { printf "${C_CYAN}[INFO ]${C_RESET} %s\n" "$1"; }
log_section() { printf "\n${C_BOLD}${C_CYAN}── %s %s${C_RESET}\n" "$1" "$(printf '─%.0s' {1..40})"; }
log_ok()      { printf "${C_GREEN}[OK   ]${C_RESET} %s\n" "$1"; }

# ── Helper: create dir + .gitkeep ─────────────────────────────────────────────
gk() {
  mkdir -p "$ROOT/$1"
  touch    "$ROOT/$1/.gitkeep"
}

# =============================================================================
log_info "ultimate-runtime — Monorepo Scaffolding"
log_info "Root: $ROOT"
# =============================================================================

# ── .github ───────────────────────────────────────────────────────────────────
log_section ".github"
mkdir -p "$ROOT/.github/workflows"
gk ".github/ISSUE_TEMPLATE"
touch "$ROOT/.github/PULL_REQUEST_TEMPLATE.md"

# ── docker ────────────────────────────────────────────────────────────────────
log_section "docker"
gk "docker/development"
gk "docker/testing"
gk "docker/production"
gk "docker/images"
gk "docker/compose"

# ── build_system ──────────────────────────────────────────────────────────────
log_section "build_system"
mkdir -p "$ROOT/build_system/cmake"
mkdir -p "$ROOT/build_system/toolchains"
gk "build_system/presets"
gk "build_system/scripts"

# cmake modules
for f in compiler_flags warnings sanitizers profiling testing packaging dependencies; do
  touch "$ROOT/build_system/cmake/${f}.cmake"
done

# toolchains
for f in linux-clang linux-gcc macos-clang windows-msvc wasm; do
  touch "$ROOT/build_system/toolchains/${f}.cmake"
done

# ── scripts ───────────────────────────────────────────────────────────────────
log_section "scripts"
for d in bootstrap setup formatting testing fuzzing benchmarking profiling deployment ci maintenance; do
  gk "scripts/$d"
done

mkdir -p "$ROOT/scripts/generators"
for f in generate_workspace generate_library generate_module generate_application \
         generate_parser generate_runtime generate_networking generate_42_project; do
  touch "$ROOT/scripts/generators/${f}.py"
done

# ── templates ─────────────────────────────────────────────────────────────────
log_section "templates"
for d in workspace library module runtime parser networking graphics ai database security application 42_project; do
  gk "templates/$d"
done

# ── tools ─────────────────────────────────────────────────────────────────────
log_section "tools"
gk "tools/formatter/clang-format"
gk "tools/formatter/clang-tidy"
gk "tools/static_analysis/cppcheck"
gk "tools/static_analysis/valgrind"
gk "tools/static_analysis/sanitizers"
gk "tools/static_analysis/scan-build"
gk "tools/profiling/perf"
gk "tools/profiling/flamegraph"
gk "tools/profiling/heaptrack"
gk "tools/profiling/tracy"
gk "tools/debugging/gdb"
gk "tools/debugging/lldb"
gk "tools/debugging/rr"
gk "tools/fuzzing"
gk "tools/benchmarking"
gk "tools/instrumentation"
gk "tools/codegen"
gk "tools/generators"

# ── docs ──────────────────────────────────────────────────────────────────────
log_section "docs"
for d in architecture internals api guides tutorials protocols diagrams benchmarks references papers; do
  gk "docs/$d"
done

mkdir -p "$ROOT/docs/conventions"
for f in naming structure memory ownership threading error_handling testing performance documentation style_guide; do
  touch "$ROOT/docs/conventions/${f}.md"
done

# ── specs ─────────────────────────────────────────────────────────────────────
log_section "specs"
for d in runtime vm memory threading network database api protocols formats security; do
  gk "specs/$d"
done

# ── research ──────────────────────────────────────────────────────────────────
log_section "research"
for d in papers notes experiments prototypes benchmarks reverse_engineering references studies; do
  gk "research/$d"
done

# ── sdk ───────────────────────────────────────────────────────────────────────
log_section "sdk"
for d in c cpp rust python lua wasm bindings; do
  gk "sdk/$d"
done

# ── third_party ───────────────────────────────────────────────────────────────
log_section "third_party"
for d in minilibx glfw vulkan sdl openssl zlib protobuf sqlite curl nghttp2 libuv llvm tree-sitter; do
  gk "third_party/$d"
done

# ── playground ────────────────────────────────────────────────────────────────
log_section "playground"
for d in sandbox experiments prototypes benchmarks fuzzing profiling; do
  gk "playground/$d"
done

# ── tests ─────────────────────────────────────────────────────────────────────
log_section "tests"
for d in unit integration regression performance fuzz stress compatibility security; do
  gk "tests/$d"
done

# ── assets ────────────────────────────────────────────────────────────────────
log_section "assets"
for d in textures audio fonts shaders icons datasets; do
  gk "assets/$d"
done

# ── runtime/foundation ────────────────────────────────────────────────────────
log_section "runtime/foundation"
for d in memory allocators atomics threading synchronization unicode utf8 hashing \
         strings logging tracing assertions diagnostics intrusive arena config platform error; do
  gk "runtime/foundation/$d"
done

# ── runtime/coreutils ─────────────────────────────────────────────────────────
log_section "runtime/coreutils"
for d in logging tracing panic assert allocator hashing atomic threading platform \
         unicode utf8 config intrusive arena error diagnostics; do
  gk "runtime/coreutils/$d"
done

# ── runtime/platform ──────────────────────────────────────────────────────────
log_section "runtime/platform"
for d in linux macos windows posix wasm; do
  gk "runtime/platform/$d"
done

# ── runtime/core ──────────────────────────────────────────────────────────────
log_section "runtime/core"
for d in scheduler event_loop async coroutine fiber threading object_system \
         reflection module_loader plugin profiler logger tracing; do
  gk "runtime/core/$d"
done

# ── runtime/vm ────────────────────────────────────────────────────────────────
log_section "runtime/vm"
for d in bytecode interpreter jit garbage_collector optimizer execution debugger; do
  gk "runtime/vm/$d"
done

# ── runtime/services ──────────────────────────────────────────────────────────
log_section "runtime/services"
for d in networking database serialization storage caching; do
  gk "runtime/services/$d"
done

# ── runtime/libft ─────────────────────────────────────────────────────────────
log_section "runtime/libft"
LFT="$ROOT/runtime/libft"
for f in README.md ARCHITECTURE.md API.md ROADMAP.md TODO.md CHANGELOG.md Makefile CMakeLists.txt; do
  touch "$LFT/$f"
done

mkdir -p "$LFT/include/public"
for h in libft string memory ctype stdio stdlib unistd math time errno; do
  touch "$LFT/include/public/${h}.h"
done
gk "runtime/libft/include/private"
gk "runtime/libft/include/internal"

for d in string memory ctype io conversion alloc math time internal; do
  gk "runtime/libft/src/$d"
done
for d in unit integration regression fuzz performance; do
  gk "runtime/libft/tests/$d"
done
for d in benchmarks fuzz examples docs scripts tools build bin tmp; do
  gk "runtime/libft/$d"
done

# ── runtime/libds ─────────────────────────────────────────────────────────────
log_section "runtime/libds"
LDS="$ROOT/runtime/libds"
for f in README.md ARCHITECTURE.md API.md ROADMAP.md TODO.md CHANGELOG.md Makefile CMakeLists.txt; do
  touch "$LDS/$f"
done

mkdir -p "$LDS/include/public"
for h in vector linked_list doubly_linked_list circular_list stack queue deque \
         hashmap hashset bst avl red_black_tree btree trie graph heap priority_queue \
         ring_buffer bloom_filter arena_allocator memory_pool slab_allocator rope \
         string_builder bitset skiplist lru_cache radix_tree interval_tree kd_tree union_find; do
  touch "$LDS/include/public/${h}.h"
done
gk "runtime/libds/include/private"
gk "runtime/libds/include/internal"

for d in vector linked_list doubly_linked_list circular_list stack queue deque \
         hashmap hashset tree graph allocator cache string advanced; do
  gk "runtime/libds/src/$d"
done
for d in tests benchmarks fuzz examples docs scripts build bin tmp; do
  gk "runtime/libds/$d"
done

# ── runtime/libalgo ───────────────────────────────────────────────────────────
log_section "runtime/libalgo"
for d in sorting searching graph dynamic_programming geometry optimization \
         compression cryptography scheduling pathfinding string_matching probabilistic parallel; do
  gk "runtime/libalgo/$d"
done

# ── runtime/libparser ─────────────────────────────────────────────────────────
log_section "runtime/libparser"
for d in lexer tokenizer parser ast formatter shell json yaml toml xml csv ini markdown regex bytecode; do
  gk "runtime/libparser/$d"
done

# ── runtime/lib* standalone ───────────────────────────────────────────────────
log_section "runtime/lib* standalone"
for d in libgraphics libnet libruntime libdatabase libai libsecurity; do
  gk "runtime/$d"
done

# ── 42_common_core ────────────────────────────────────────────────────────────
log_section "42_common_core"
for d in libft born2beroot ft_printf get_next_line push_swap pipex so_long fractol \
         philosophers minishell minitalk netpractice cub3d miniRT cpp_modules \
         webserv ft_irc inception transcendence exam_rank; do
  gk "42_common_core/$d"
done

# ── 42_specializations ────────────────────────────────────────────────────────
log_section "42_specializations/graphics"
for d in doom_engine renderer game_engine vulkan_renderer; do
  gk "42_specializations/graphics/$d"
done

log_section "42_specializations/cybersecurity"
for d in malware_analysis packet_sniffer reverse_engineering exploit_lab secure_server; do
  gk "42_specializations/cybersecurity/$d"
done

log_section "42_specializations/devops"
for d in kubernetes terraform ci_cd monitoring observability; do
  gk "42_specializations/devops/$d"
done

log_section "42_specializations/ai"
for d in neural_network inference_engine llm_runtime vector_database distributed_training; do
  gk "42_specializations/ai/$d"
done

log_section "42_specializations/systems"
for d in mini_kernel bootloader filesystem compiler interpreter vm container_runtime distributed_runtime; do
  gk "42_specializations/systems/$d"
done

log_section "42_specializations/networking"
for d in http_server grpc_gateway websocket_server reverse_proxy service_mesh \
         message_broker distributed_cache api_gateway; do
  gk "42_specializations/networking/$d"
done

# ── applications ──────────────────────────────────────────────────────────────
log_section "applications/cli"
for d in shell debugger terminal package_manager; do
  gk "applications/cli/$d"
done

log_section "applications/distributed"
for d in distributed_queue distributed_database service_mesh cloud_platform; do
  gk "applications/distributed/$d"
done

log_section "applications/ai"
for d in ai_assistant_runtime vector_database inference_server; do
  gk "applications/ai/$d"
done

log_section "applications/systems"
for d in mini_docker mini_kubernetes operating_system; do
  gk "applications/systems/$d"
done

log_section "applications/graphics"
for d in browser game_engine renderer; do
  gk "applications/graphics/$d"
done

log_section "applications/backend"
for d in reverse_proxy streaming_server monitoring_system observability_platform; do
  gk "applications/backend/$d"
done

# =============================================================================
log_ok "Directory tree created. Run 'find . -name .gitkeep | wc -l' to verify."
# =============================================================================
