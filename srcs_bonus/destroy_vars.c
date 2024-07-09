/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:55:50 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 16:55:55 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
/*
typedef	struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	t_mapsize *size;
	int		item_left;
	int		mov_count;
	int		mov_direction;
}	t_vars; */
/*
void	destroy_textures(t_vars *vars, t_texture *textures)
{
	mlx_destroy_image(vars->mlx, textures->image1);
	mlx_destroy_image(vars->mlx, textures->image2);
	mlx_destroy_image(vars->mlx, textures->image3);
	mlx_destroy_image(vars->mlx, textures->image4);
	mlx_destroy_image(vars->mlx, textures->image5);
	mlx_destroy_image(vars->mlx, textures->image6);
	mlx_destroy_image(vars->mlx, textures->image7);
}*/

void	destroy_vars(t_vars *vars)  //This fucntion create segV is it need to be ** ?
{
	free_map(vars->map);
	free(vars->size);
	//free(vars);
}