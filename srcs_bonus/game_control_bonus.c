/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:01:50 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 15:01:51 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_character(int keycode, t_vars *vars)
{
	t_mapsize	*pos;
	char	*next_pos;
	pos = find_player(vars->map, 0, 0);
	if (pos == NULL)
		return (-1);
	next_pos = NULL;
	if (!check_direction(keycode, vars, &next_pos, pos))
	{
		free(pos);
		return (0);
	}
	if (*next_pos != '1')
	{
		if (win_game(vars, next_pos))
		{
			free(pos);
			exit(0);
		}
		collect_item(vars, next_pos);
		touch_enemy(vars, pos, next_pos); /*---------------BONUS-------------------*/
		move_forward(vars, pos, next_pos);
	}
	free(pos);
	return (0);
}

int	key_control(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		destroy_vars(vars);
		exit(0);
	}	
	move_character(keycode, vars);
	return (0);
}

int	cross_press(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
