cmake_minimum_required(VERSION 3.24)

# ============================================================================
# Test configuration
# ============================================================================
enable_testing()

# Auto-discover test files
file(GLOB_RECURSE TEST_SOURCES "*.c")

foreach(test_file ${TEST_SOURCES})
    # Extract test name from file path
    get_filename_component(test_name ${test_file} NAME_WE)
    get_filename_component(test_dir ${test_file} DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" test_path "${test_dir}/${test_name}")
    
    # Create executable for each test
    add_executable(test_${test_name} ${test_file})
    target_link_libraries(test_${test_name} PRIVATE libft)
    target_include_directories(test_${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
    
    # Add test
    add_test(NAME ${test_path} COMMAND test_${test_name})
endforeach()
