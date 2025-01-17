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

NAME_BONUS = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c srcs/check_map.c srcs/read_map.c srcs/render_map.c \
	srcs/find_player.c srcs/game_control.c srcs/check_path.c \
	srcs/destroy_vars.c srcs/check_char.c srcs/render_element.c \
	srcs/game_event.c

SRCS_BONUS = srcs_bonus/main_bonus.c srcs_bonus/check_map_bonus.c \
	srcs_bonus/read_map_bonus.c srcs_bonus/render_map_bonus.c \
	srcs_bonus/find_player_bonus.c srcs_bonus/game_control_bonus.c \
	srcs_bonus/show_step_bonus.c srcs_bonus/check_path_bonus.c \
	srcs_bonus/destroy_vars_bonus.c srcs_bonus/check_char_bonus.c \
	srcs_bonus/render_element_bonus.c srcs_bonus/game_event_bonus.c
	
LIBFT = ./libft

MINILIBX = ./mlx_linux

INCLUDE = -I./libft -I./header  -I/usr/include -Imlx_linux

LIBS = -L./libft -lft -L./mlx_linux -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(SRCS)
	make -C $(LIBFT)
	make -C $(MINILIBX)
	$(CC) $(SRCS) $(CFLAGS) $(INCLUDE) $(LIBS) -o $(NAME)
	
bonus: $(SRCS_BONUS)
	make -C $(LIBFT)
	make -C $(MINILIBX)
	$(CC) $(SRCS_BONUS) $(CFLAGS) $(INCLUDE) $(LIBS) -o $(NAME_BONUS)

clean:
	make clean -C $(LIBFT)

fclean:
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C $(LIBFT)
	make clean -C $(MINILIBX)

re:	fclean all

.PHONY: all clean fclean re
