cmake_minimum_required(VERSION 3.29)
project(Partie2)

# Create the library from the source files
add_library(tugabudoire STATIC Tugabudoire/Tugabudoire.cpp
        main.cpp)

# Specify include directories for the library
target_include_directories(tugabudoire PUBLIC Tugabudoire)

target_compile_features(tugabudoire PUBLIC cxx_std_14)

add_executable(Partie2
        main.cpp
        Tugabudoire/Tugabudoire.cpp
        Tugabudoire/Tugabudoire.h)
