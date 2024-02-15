cmake_minimum_required(VERSION 3.24)
project(practice C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(practice
        trash/adjacy.c
        trash/geek4geeksOrder.c
        trash/test.c
        funcs.h
        main.c
        tree.h)
