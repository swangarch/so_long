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

#include "mlx.h"
#include "so_long.h"

typedef	struct s_texture {
	void	*image1;
	void	*image2;
	void	*image3;
	void	*image4;
	void	*image5;
	void	*image6;
	void	*image7;
} t_texture;

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

void	render_map(t_vars *vars)
{
	t_texture	textures;

	load_textures(vars, &textures, SCALE, SCALE); ////???????????????????????????what w and h means
	// protect not fail when image not exist
	int	i = 0;
	int	j = 0;
	while (i < vars->size->y)
	{
		j = 0;
		while (j < vars->size->x)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, textures.image1, j * SCALE, i * SCALE);
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, textures.image2, j * SCALE, i * SCALE);
			if (vars->map[i][j] == 'E' && vars->item_left <= 0)
				mlx_put_image_to_window(vars->mlx, vars->win, textures.image3, j * SCALE, i * SCALE);
			if (vars->map[i][j] == 'E' && vars->item_left > 0)
				mlx_put_image_to_window(vars->mlx, vars->win, textures.image6, j * SCALE, i * SCALE);
			if (vars->map[i][j] == 'P')
			{
				if (vars->mov_direction == 0)
					mlx_put_image_to_window(vars->mlx, vars->win, textures.image4, j * SCALE, i * SCALE);
				else if (vars->mov_direction == 1)
					mlx_put_image_to_window(vars->mlx, vars->win, textures.image7, j * SCALE, i * SCALE);
			}
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, textures.image5, j * SCALE, i * SCALE);
			j++;
		}
		i++;
	}
}
