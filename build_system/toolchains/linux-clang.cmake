# linux-clang.cmake — Clang toolchain for Linux

set(CMAKE_SYSTEM_NAME  Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# ── Compilers ─────────────────────────────────────────────────────────────────
find_program(CLANG_C   clang   REQUIRED)
find_program(CLANG_CXX clang++ REQUIRED)

set(CMAKE_C_COMPILER   ${CLANG_C})
set(CMAKE_CXX_COMPILER ${CLANG_CXX})

# ── LLVM tools ────────────────────────────────────────────────────────────────
find_program(LLVM_AR      llvm-ar)
find_program(LLVM_RANLIB  llvm-ranlib)
find_program(LLVM_NM      llvm-nm)
find_program(LLD_LINKER   lld)

if(LLVM_AR)
  set(CMAKE_AR      ${LLVM_AR})
  set(CMAKE_RANLIB  ${LLVM_RANLIB})
endif()

if(LLD_LINKER)
  add_link_options(-fuse-ld=lld)
endif()

# ── Flags ─────────────────────────────────────────────────────────────────────
set(CMAKE_C_FLAGS_INIT   "-fcolor-diagnostics")
set(CMAKE_CXX_FLAGS_INIT "-fcolor-diagnostics -stdlib=libc++")

# ── Find root (cross-compilation friendly) ────────────────────────────────────
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
