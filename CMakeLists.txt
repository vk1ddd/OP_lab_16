cmake_minimum_required(VERSION 3.26)
project(lab_16 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_16 main.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h
)
