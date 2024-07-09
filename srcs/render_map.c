/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:40:37 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 12:40:50 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_vars *vars, t_texture *textures, int w, int h)
{
	textures->image1 = mlx_xpm_file_to_image(vars->mlx, "texture/1.xpm", &w, &h);
	textures->image2 = mlx_xpm_file_to_image(vars->mlx, "texture/0.xpm", &w, &h);
	textures->image3 = mlx_xpm_file_to_image(vars->mlx, "texture/e.xpm", &w, &h);
	textures->image4 = mlx_xpm_file_to_image(vars->mlx, "texture/p.xpm", &w, &h);
	textures->image5 = mlx_xpm_file_to_image(vars->mlx, "texture/c.xpm", &w, &h);
	textures->image6 = mlx_xpm_file_to_image(vars->mlx, "texture/door_small.xpm", &w, &h);
	textures->image7 = mlx_xpm_file_to_image(vars->mlx, "texture/pright.xpm", &w, &h);
}

void	render_background(t_vars *vars, int i, int j, t_texture	*textures)
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, textures->image1, j * SCALE, i * SCALE);
	if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, textures->image2, j * SCALE, i * SCALE);
}

void	render_player(t_vars *vars, int i, int j, t_texture	*textures)
{
	if (vars->map[i][j] == 'P')
	{
		if (vars->mov_direction == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, textures->image4, j * SCALE, i * SCALE);
		else if (vars->mov_direction == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, textures->image7, j * SCALE, i * SCALE);
	}
}

void	render_exit(t_vars *vars, int i, int j, t_texture	*textures)
{
	if (vars->map[i][j] == 'E' && vars->item_left <= 0)
		mlx_put_image_to_window(vars->mlx, vars->win, textures->image3, j * SCALE, i * SCALE);
	if (vars->map[i][j] == 'E' && vars->item_left > 0)
		mlx_put_image_to_window(vars->mlx, vars->win, textures->image6, j * SCALE, i * SCALE);
}

void	render_map(t_vars *vars)  /////should send the textures as a input in order to free at the end
{
	t_texture	textures;

	load_textures(vars, &textures, SCALE, SCALE); ////????????????what w and h means // protect not fail when image not exist ??need?
	int	i = 0;
	int	j = 0;
	while (i < vars->size->y)
	{
		j = 0;
		while (j < vars->size->x)
		{
			render_background(vars, i, j, &textures);
			render_exit(vars, i, j, &textures);
			render_player(vars, i, j, &textures);
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, textures.image5, j * SCALE, i * SCALE);
			j++;
		}
		i++;
	}
	destroy_textures(vars, &textures);
}
