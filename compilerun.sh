#!/bin/bash

cc main.c check_map.c read_map.c libft.a -Wall -Wextra -Werror -I/usr/include -Imlx_linux -L./mlx_linux -lmlx -lX11 -lXext -o so_long

./so_long maps/map1.ber
./so_long maps/map2.ber
./so_long maps/map8.ber
./so_long maps/map10.ber
