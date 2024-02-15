cmake_minimum_required(VERSION 3.27)
project(2_lab C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(2_lab
        file_space.h
        header.h
        space.c)
