#!/bin/bash

cc main.c -Wall -Wextra -Werror -I/usr/include -Imlx_linux -L./mlx_linux -lmlx -lX11 -lXext -o so_long
