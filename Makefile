# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shuwang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 12:50:07 by shuwang           #+#    #+#              #
#    Updated: 2024/07/09 17:22:22 by shuwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c srcs/check_map.c srcs/read_map.c srcs/render_map.c srcs/find_player.c srcs/game_control.c srcs/show_step.c srcs/check_path.c srcs/destroy_vars.c srcs/check_char.c
	
LIBFT = ./libft

INCLUDE = -I./libft -I./header  -I/usr/include -Imlx_linux

LIBS = -L./libft -lft -L./mlx_linux -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(SRCS)
	make -C $(LIBFT)
	$(CC) $(SRCS) $(CFLAGS) $(INCLUDE) $(LIBS) -o $(NAME)

clean:
	make clean -C $(LIBFT)

fclean:
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re:	fclean all

.PHONY: all clean fclean re
