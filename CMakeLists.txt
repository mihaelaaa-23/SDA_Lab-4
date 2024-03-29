cmake_minimum_required(VERSION 3.27)
project(SDA C)

set(CMAKE_C_STANDARD 11)

add_executable(SDA main.c
        struct.c
        struct.h
        union.c
        union.h)
