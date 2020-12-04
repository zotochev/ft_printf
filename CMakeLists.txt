cmake_minimum_required(VERSION 3.17)
project(20201203_ft_printf C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-w -Wall -Wextra -Werror -I./libft -g3 -fsanitize=address -fno-omit-frame-pointer")

add_executable(20201203_ft_printf main.c ft_printf.c ft_printf.h print_numbers.c format_parser.c print_processor.c)
target_link_libraries(20201203_ft_printf ${CMAKE_SOURCE_DIR}/libft/libft.a)