#!/bin/bash

cc srcs/main.c srcs/check_map.c srcs/read_map.c srcs/libft.a -Wall -Wextra -Werror -I/usr/include -Imlx_linux -L./mlx_linux -lmlx -lX11 -lXext -o so_long
