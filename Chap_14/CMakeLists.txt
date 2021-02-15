cmake_minimum_required(VERSION 3.16)
project(Chap_14 C)

set(CMAKE_C_STANDARD 99)

add_executable(Chap_14 array.c freearray.c nofree.c null.c vector.c)
