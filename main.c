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

void	render_map(char **map, void *mlx, void *mlx_win, t_mapsize *size)
{

	void	*image1;
	void	*image2;
	void	*image3;
	void	*image4;
	void	*image5;	
	int	w = 60;
	int	h = 60;	
	int 	scale = 60;
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
}

typedef	struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	t_mapsize *size;
}	t_vars;


t_mapsize	*find_player(char **map)
{
	t_mapsize *position;
	t_mapsize *size;
	int	i;
	int	j;
	
	size = get_map_size(map);
	i = 0;
	position = malloc(sizeof(t_mapsize));
	if (position == NULL)
		return (NULL);
	while (i < size->y)
	{
		j = 0;
		while (j < size->x)
		{
			if (map[i][j] == 'P')
			{
				position->x = j;
				position->y = i;
				return (position);
			} 
			j++;
		}
		i++;
	}
	return (NULL);
}

int	key_control(int keycode, t_vars *vars)
{
	t_mapsize	*pos;

	pos = find_player(vars->map);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}	
	if (keycode == 100 && (vars->map)[pos->y][pos->x+1] != '1')
	{
		(vars->map)[pos->y][pos->x] = '0';
		(vars->map)[pos->y][pos->x+1] = 'P';
		render_map(vars->map, vars->mlx, vars->win, vars->size);	
	}
	if (keycode == 97 && (vars->map)[pos->y][pos->x-1] != '1')
	{
		(vars->map)[pos->y][pos->x] = '0';
		(vars->map)[pos->y][pos->x-1] = 'P';
		render_map(vars->map, vars->mlx, vars->win, vars->size);	
	}
	if (keycode == 119 && (vars->map)[pos->y-1][pos->x] != '1')
	{
		(vars->map)[pos->y][pos->x] = '0';
		(vars->map)[pos->y-1][pos->x] = 'P';
		render_map(vars->map, vars->mlx, vars->win, vars->size);	
	}
	if (keycode == 115 && (vars->map)[pos->y+1][pos->x] != '1')
	{
		(vars->map)[pos->y][pos->x] = '0';
		(vars->map)[pos->y + 1][pos->x] = 'P';
		render_map(vars->map, vars->mlx, vars->win, vars->size);	
	}
	return (0);
}
int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	int	fd;
	int	scale = 60;
	t_vars	vars;
	t_mapsize	*size;
	
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
	render_map(map, mlx, mlx_win, size);
	vars.mlx = mlx;
	vars.win = mlx_win;
	vars.map = map;
	vars.size = size;
	mlx_key_hook(vars.win, key_control, &vars);
	mlx_loop(mlx);
}
