cmake_minimum_required(VERSION 3.29)
project(Partie2)

set(CMAKE_CXX_STANDARD 14)

# Create the library from the source files
set(SOURCES main.cpp)

add_executable(Partie2 ${SOURCES})


# Specify include directories for the library
target_include_directories(Partie2 PUBLIC lib)

find_library(MY_LIBRARY Partie2_Lib PATHS lib)

target_compile_features(Partie2 PUBLIC cxx_std_14)

target_link_libraries(Partie2 ${MY_LIBRARY})
