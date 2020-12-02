cmake_minimum_required(VERSION 3.17)
project(20201201_printf C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
add_executable(20201201_printf main.c ft_printf.c ft_printf.h ft_printf_utils.c parser_utils.c placeholder_print_utils.c)