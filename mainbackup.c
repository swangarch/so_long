/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:36:31 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/05 19:34:51 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"


int	main(int ac, char **av)
{
	void	*mlx;
	void	*image1;
	void	*image2;
	void	*image3;
	void	*image4;
	void	*image5;
	void	*mlx_win;
	int	w = 60;
	int	h = 60;
	int	fd;
	t_mapsize	*size;
	int 	scale = 60;
	
	fd = open(av[1], O_RDONLY);
	char **map = read_map(fd);
	if (check_map(map) == 0)
		return (1);

	
	(void) ac;	
	mlx = mlx_init();

	size = get_map_size(map);
	if (size == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}

	mlx_win = mlx_new_window(mlx, (size->x) * scale, (size->y) * scale, "so_long");
	image1 = mlx_xpm_file_to_image(mlx, "texture/ground_small.xpm", &w, &h);// protect not fail when image not exst
	image2 = mlx_xpm_file_to_image(mlx, "texture/grass_small.xpm", &w, &h);// protect not fail when image not exst
	image3 = mlx_xpm_file_to_image(mlx, "texture/door_small.xpm", &w, &h);// protect not fail when image not exst
	image4 = mlx_xpm_file_to_image(mlx, "texture/pig_small.xpm", &w, &h);// protect not fail when image not exst
	image5 = mlx_xpm_file_to_image(mlx, "texture/tresure_small.xpm", &w, &h);// protect not fail when image not exst

	int	i = 0;
	int	j = 0;
	while (i < size->y)
	{
		j = 0;
		while (j < size->x)
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, image1, j * scale, i * scale);
			if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_win, image2, j * scale, i * scale);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, image3, j * scale, i * scale);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, image4, j * scale, i * scale);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, image5, j * scale, i * scale);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
