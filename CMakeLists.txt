cmake_minimum_required(VERSION 3.12)
project(filler C)
include_directories(./libft/includes)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
        *.h
        libft/*.c
        libft/printf_src/*.c
        src/*.c
        )

add_executable(filler ${SOURCES} visualizer/visualize.c visualizer/stdfuncs.c)