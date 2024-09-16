cmake_minimum_required(VERSION 3.10)
project(Partie3)

# Add your source files
set(SOURCE_FILES main.cpp Tugabudoire.cpp)

# Add test files
set(TEST_FILES tests/test_tugabudoire.cpp)

# Create the executable for your main application
add_executable(Partie3 ${SOURCE_FILES})

add_subdirectory(tests)

# Include the directory where the main sources are located
include_directories(${CMAKE_SOURCE_DIR})