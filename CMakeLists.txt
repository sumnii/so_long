cmake_minimum_required(VERSION 3.22)
project(so_long C)

set(CMAKE_C_STANDARD 99)
set( CMAKE_CXX_FLAGS "gcc -L./mlx -lmlx -framework OpenGL -framework AppKit" )
#file(GLOB SRC ./*.c)
#file(GLOB MLX ./mlx/.c)
add_executable(so_long
        main.c gnl/get_next_line.c gnl/get_next_line_utils.c map_load.c map_check.c window.c
        mlx/mlx_png.c mlx/mlx_rgb.c mlx/mlx_string_put.c mlx/mlx_xpm.c mlx/font.c)
#add_executable(so_long ${SRC} ${MLX})