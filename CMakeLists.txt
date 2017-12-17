cmake_minimum_required(VERSION 3.9)
project(Memory_allocator C)

set(CMAKE_C_STANDARD 99)

add_executable(Memory_allocator main.c mem_debug.c mem.h mem.c)