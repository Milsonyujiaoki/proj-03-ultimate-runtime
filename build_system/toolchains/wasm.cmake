# wasm.cmake — WebAssembly (Emscripten) cross-compilation toolchain

set(CMAKE_SYSTEM_NAME    Emscripten)
set(CMAKE_SYSTEM_VERSION 1)

# ── Emscripten SDK ────────────────────────────────────────────────────────────
if(DEFINED ENV{EMSDK})
  set(EMSCRIPTEN_ROOT "$ENV{EMSDK}/upstream/emscripten")
else()
  find_program(EMCC emcc)
  if(EMCC)
    get_filename_component(EMSCRIPTEN_ROOT ${EMCC} DIRECTORY)
  else()
    message(FATAL_ERROR
      "wasm.cmake: Emscripten not found.\n"
      "Install from https://emscripten.org/docs/getting_started/downloads.html\n"
      "and set EMSDK environment variable.")
  endif()
endif()

set(CMAKE_C_COMPILER   "${EMSCRIPTEN_ROOT}/emcc")
set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_ROOT}/em++")
set(CMAKE_AR           "${EMSCRIPTEN_ROOT}/emar")
set(CMAKE_RANLIB       "${EMSCRIPTEN_ROOT}/emranlib")

# ── Output settings ───────────────────────────────────────────────────────────
set(CMAKE_EXECUTABLE_SUFFIX ".js")
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".a")

# ── Emscripten flags ──────────────────────────────────────────────────────────
set(CMAKE_C_FLAGS_INIT
  "-sWASM=1 -sUSE_PTHREADS=0 -sSTACK_SIZE=1MB")
set(CMAKE_CXX_FLAGS_INIT
  "-sWASM=1 -sUSE_PTHREADS=0 -sSTACK_SIZE=1MB")
set(CMAKE_EXE_LINKER_FLAGS_INIT
  "-sEXPORT_ES6=1 -sMODULARIZE=1 -sALLOW_MEMORY_GROWTH=1")

# ── Sysroot ───────────────────────────────────────────────────────────────────
set(CMAKE_SYSROOT "${EMSCRIPTEN_ROOT}/system")
set(CMAKE_FIND_ROOT_PATH "${EMSCRIPTEN_ROOT}/system")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
