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
	textures->image_1 = mlx_xpm_file_to_image \
		(vars->mlx, "texture/1.xpm", &w, &h);
	textures->image_0 = mlx_xpm_file_to_image \
		(vars->mlx, "texture/0.xpm", &w, &h);
	textures->image_e = mlx_xpm_file_to_image \
		(vars->mlx, "texture/e2.xpm", &w, &h);
	textures->image_pl = mlx_xpm_file_to_image \
		(vars->mlx, "texture/p.xpm", &w, &h);
	textures->image_c = mlx_xpm_file_to_image \
		(vars->mlx, "texture/c.xpm", &w, &h);
	textures->image_c2 = mlx_xpm_file_to_image \
		(vars->mlx, "texture/c2.xpm", &w, &h);
	textures->image_c3 = mlx_xpm_file_to_image \
		(vars->mlx, "texture/c3.xpm", &w, &h);
	textures->image_e2 = mlx_xpm_file_to_image \
		(vars->mlx, "texture/e.xpm", &w, &h);
	textures->image_pr = mlx_xpm_file_to_image \
		(vars->mlx, "texture/pright.xpm", &w, &h);
	textures->image_m = mlx_xpm_file_to_image \
		(vars->mlx, "texture/m1.xpm", &w, &h);
}

void	destroy_textures(t_vars *vars, t_texture *textures)
{
	mlx_destroy_image(vars->mlx, textures->image_1);
	mlx_destroy_image(vars->mlx, textures->image_0);
	mlx_destroy_image(vars->mlx, textures->image_e);
	mlx_destroy_image(vars->mlx, textures->image_pl);
	mlx_destroy_image(vars->mlx, textures->image_c);
	mlx_destroy_image(vars->mlx, textures->image_c2);
	mlx_destroy_image(vars->mlx, textures->image_c3);
	mlx_destroy_image(vars->mlx, textures->image_e2);
	mlx_destroy_image(vars->mlx, textures->image_pr);
	mlx_destroy_image(vars->mlx, textures->image_m);
}

void	render_map(t_vars *vars)
{
	t_texture	textures;
	int			i;
	int			j;

	load_textures(vars, &textures, SCALE, SCALE);
	i = 0;
	j = 0;
	while (i < vars->size->y)
	{
		j = 0;
		while (j < vars->size->x)
		{
			render_background(vars, i, j, &textures);
			render_exit(vars, i, j, &textures);
			render_player(vars, i, j, &textures);
			render_item(vars, i, j, &textures);
			j++;
		}
		i++;
	}
	destroy_textures(vars, &textures);
}
