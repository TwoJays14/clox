cmake_minimum_required(VERSION 4.0)
project(clox C)

set(CMAKE_C_STANDARD 23)

add_executable(clox main.c
        libs/token/token.c
        libs/token/token.h
        scanner.c
        scanner.h
        libs/arena/arena.c
        libs/arena/arena.h
        libs/data_structures/DynamicArray.c
        libs/data_structures/DynamicArray.h
        libs/helpers/string/string.c
        libs/helpers/string/string.h
)
