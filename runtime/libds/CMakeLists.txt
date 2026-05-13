cmake_minimum_required(VERSION 3.24)
project(libds VERSION 0.1.0 LANGUAGES C)

include(../../build_system/cmake/compiler_flags.cmake)
include(../../build_system/cmake/warnings.cmake)

# Sources are added incrementally as modules are implemented.
# Each src/<group>/*.c file is added here when its implementation exists.
file(GLOB_RECURSE LIBDS_SOURCES CONFIGURE_DEPENDS "src/*.c")

add_library(libds STATIC ${LIBDS_SOURCES})

# If no sources exist yet, CMake needs at least one — add a placeholder.
if(NOT LIBDS_SOURCES)
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/_empty.c" "/* placeholder */\n")
    target_sources(libds PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/_empty.c")
endif()

set_target_properties(libds PROPERTIES
    OUTPUT_NAME ds
    C_STANDARD  17
    C_EXTENSIONS OFF
)

target_include_directories(libds
    PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/public>
            $<INSTALL_INTERFACE:include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/private
)

target_link_libraries(libds PUBLIC libft)

ur_set_compile_flags(libds)
ur_enable_warnings(libds PRIVATE)

# ── Install ───────────────────────────────────────────────────────────────────
include(GNUInstallDirs)
install(TARGETS libds ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/public/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# ── Tests ─────────────────────────────────────────────────────────────────────
if(UR_BUILD_TESTS)
    include(../../build_system/cmake/testing.cmake)
    ur_setup_testing()
    add_subdirectory(tests)
endif()

if(UR_BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()
