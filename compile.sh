#!/bin/bash

cc main.c check_map.c read_map.c libft.a -Wall -Wextra -Werror -I/usr/include -Imlx_linux -L./mlx_linux -lmlx -lX11 -lXext -o so_long
