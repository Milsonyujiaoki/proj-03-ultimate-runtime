# linux-gcc.cmake — GCC toolchain for Linux

set(CMAKE_SYSTEM_NAME  Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# ── Compilers ─────────────────────────────────────────────────────────────────
find_program(GCC_C   gcc REQUIRED)
find_program(GCC_CXX g++ REQUIRED)

set(CMAKE_C_COMPILER   ${GCC_C})
set(CMAKE_CXX_COMPILER ${GCC_CXX})

# ── Archiver ──────────────────────────────────────────────────────────────────
find_program(GCC_AR gcc-ar)
if(GCC_AR)
  set(CMAKE_AR     ${GCC_AR})
  set(CMAKE_RANLIB gcc-ranlib)
endif()

# ── Linker ────────────────────────────────────────────────────────────────────
find_program(MOLD_LINKER mold)
find_program(GOLD_LINKER gold)
if(MOLD_LINKER)
  add_link_options(-fuse-ld=mold)
elseif(GOLD_LINKER)
  add_link_options(-fuse-ld=gold)
endif()

# ── Flags ─────────────────────────────────────────────────────────────────────
set(CMAKE_C_FLAGS_INIT   "-fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS_INIT "-fdiagnostics-color=always")

# ── Find root ─────────────────────────────────────────────────────────────────
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
