/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:57:43 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/10 16:57:45 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_background(t_vars *vars, int i, int j, t_texture	*textures)
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			textures->image_1, j * SCALE, i * SCALE);
	if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			textures->image_0, j * SCALE, i * SCALE);
}

void	render_player(t_vars *vars, int i, int j, t_texture	*textures)
{
	if (vars->map[i][j] == 'P')
	{
		if (vars->mov_direction == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, \
				textures->image_pl, j * SCALE, i * SCALE);
		else if (vars->mov_direction == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, \
				textures->image_pr, j * SCALE, i * SCALE);
	}
}

void	render_exit(t_vars *vars, int i, int j, t_texture *textures)
{
	if (vars->map[i][j] == 'E' && vars->item_left <= 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			textures->image_e, j * SCALE, i * SCALE);
	if (vars->map[i][j] == 'E' && vars->item_left > 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			textures->image_e2, j * SCALE, i * SCALE);
}

void	render_item(t_vars *vars, int i, int j, t_texture *textures)
{
	if (vars->map[i][j] == 'C')
	{
		if (vars->frame == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, \
				textures->image_c3, j * SCALE, i * SCALE);
		else if (vars->frame == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, \
				textures->image_c2, j * SCALE, i * SCALE);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, \
				textures->image_c, j * SCALE, i * SCALE);
	}
}
/*
void	render_enemy(t_vars *vars, int i, int j, t_texture	*textures)
{
	if (vars->map[i][j] == 'M')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			textures->image_m, j * SCALE, i * SCALE);
}*/
