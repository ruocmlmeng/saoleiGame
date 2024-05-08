cmake_minimum_required(VERSION 3.28)
project(saoleiGame C)

set(CMAKE_C_STANDARD 11)

add_executable(saoleiGame test.c
        game.c
        game.h)
