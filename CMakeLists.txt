cmake_minimum_required(VERSION 3.20)
project(polynomial_interpolation C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(polynomial_interpolation
        funs_interp.c
        funs_interp.h main_taula.c)
add_executable(main_err
        funs_interp.c
        funs_interp.h main_errinterp.c)
