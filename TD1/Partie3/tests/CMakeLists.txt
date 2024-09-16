# 'Google_test' is the subproject name
project(Google_Tests_run)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest)

# Include directories for Google Test
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Include directories for your project
include_directories(${CMAKE_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test_tugabudoire.cpp' is the source file with tests
add_executable(Google_Tests_run test_tugabudoire.cpp)

# Link the test executable with Google Test libraries
target_link_libraries(Google_Tests_run gtest gtest_main)

# Add the main application sources to the test target
target_sources(Google_Tests_run PRIVATE ${CMAKE_SOURCE_DIR}/Tugabudoire.cpp)

