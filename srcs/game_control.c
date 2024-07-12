/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:01:50 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 15:01:51 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
