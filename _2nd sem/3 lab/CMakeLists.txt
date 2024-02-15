cmake_minimum_required(VERSION 3.24)
project(3_lab C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(clear)

add_executable(3_lab
        clear/3lab.c
        clear/funcs.h
        clear/struct.h)
