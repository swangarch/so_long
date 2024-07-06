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

typedef	struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	t_mapsize *size;
	int		item_left;
	int		mov_count;
}	t_vars;

void	render_map(char **map, void *mlx, void *mlx_win, t_mapsize *size)
{

	void	*image1;
	void	*image2;
	void	*image3;
	void	*image4;
	void	*image5;	
	int		w = 60;
	int		h = 60;	
	int 	scale = 60;

	// protect not fail when image not exist
	image1 = mlx_xpm_file_to_image(mlx, "texture/ground_small.xpm", &w, &h);
	image2 = mlx_xpm_file_to_image(mlx, "texture/grass_small.xpm", &w, &h);
	image3 = mlx_xpm_file_to_image(mlx, "texture/door_small.xpm", &w, &h);
	image4 = mlx_xpm_file_to_image(mlx, "texture/dog_small.xpm", &w, &h);
	image5 = mlx_xpm_file_to_image(mlx, "texture/tresure_small.xpm", &w, &h);
	// protect not fail when image not exist

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
	if (keycode == 100 && (vars->map)[pos->y][pos->x+1] != '1')  //D
	{
		if ((vars->map)[pos->y][pos->x+1] == 'C')
		{
			vars->item_left--;
		}

		if ((vars->map)[pos->y][pos->x+1] == 'E' && vars->item_left <= 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			ft_printf("You win\n");
			exit(0);
		}
		if (!((vars->map)[pos->y][pos->x+1] == 'E' && vars->item_left > 0))
		{
			(vars->map)[pos->y][pos->x] = '0';
			(vars->map)[pos->y][pos->x+1] = 'P';
			vars->mov_count++;
			render_map(vars->map, vars->mlx, vars->win, vars->size);
			mlx_string_put(vars->mlx, vars->win, 60, 60, 0xFFFFFF, "Hello world\n");
			ft_printf("Movement count is %d\n", vars->mov_count);
		}
	}
	if (keycode == 97 && (vars->map)[pos->y][pos->x-1] != '1')  //A
	{
		if ((vars->map)[pos->y][pos->x-1] == 'C')
		{
			vars->item_left--;
		}

		if ((vars->map)[pos->y][pos->x-1] == 'E' && vars->item_left <= 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			ft_printf("You win\n");
			exit(0);
		}
		if (!((vars->map)[pos->y][pos->x-1] == 'E' && vars->item_left > 0))
		{
			(vars->map)[pos->y][pos->x] = '0';
			(vars->map)[pos->y][pos->x-1] = 'P';
			vars->mov_count++;
			render_map(vars->map, vars->mlx, vars->win, vars->size);

			mlx_string_put(vars->mlx, vars->win, 60, 60, 0xFFFFFF, "Hello world\n");
			ft_printf("Movement count is %d\n", vars->mov_count);
		}
	}
	if (keycode == 119 && (vars->map)[pos->y-1][pos->x] != '1')  //W
	{
		if ((vars->map)[pos->y-1][pos->x] == 'C')
			vars->item_left--;

		if ((vars->map)[pos->y-1][pos->x] == 'E' && vars->item_left <= 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			ft_printf("You win\n");
			exit(0);
		}

		if (!((vars->map)[pos->y-1][pos->x] == 'E' && vars->item_left > 0))
		{
			(vars->map)[pos->y][pos->x] = '0';
			(vars->map)[pos->y-1][pos->x] = 'P';
			vars->mov_count++;
			render_map(vars->map, vars->mlx, vars->win, vars->size);
			mlx_string_put(vars->mlx, vars->win, 60, 60, 0xFFFFFF, "Hello world\n");
			ft_printf("Movement count is %d\n", vars->mov_count);
		}
	}
	if (keycode == 115 && (vars->map)[pos->y+1][pos->x] != '1')  //S
	{
		if ((vars->map)[pos->y + 1][pos->x] == 'C')
			vars->item_left--;

		if ((vars->map)[pos->y+1][pos->x] == 'E' && vars->item_left <= 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			ft_printf("You win\n");
			exit(0);
		}
		if (!((vars->map)[pos->y+1][pos->x] == 'E' && vars->item_left > 0))
		{
			(vars->map)[pos->y][pos->x] = '0';
			(vars->map)[pos->y + 1][pos->x] = 'P';
			vars->mov_count++;
			render_map(vars->map, vars->mlx, vars->win, vars->size);
			mlx_string_put(vars->mlx, vars->win, 60, 60, 0xFFFFFF, "Hello world\n");
			ft_printf("Movement count is %d\n", vars->mov_count);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	fd;
	int	scale = 60;
	t_vars	vars;
	
	if (!ft_strnstr(av[1], ".ber",ft_strlen(av[1])))//check if map name is valid
	{
		ft_printf("Error (Invalid mapname)\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	vars.map = read_map(fd);
	if (check_map(vars.map) == 0)
		return (1);
	(void) ac;
	
	vars.mlx = mlx_init();
	vars.size = get_map_size(vars.map);
	if (vars.size == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	vars.item_left = count_collectible(vars.map);
	vars.mov_count = 0;
	vars.win = mlx_new_window(vars.mlx, (vars.size->x) * scale, (vars.size->y) * scale, "so_long");	
	render_map(vars.map, vars.mlx, vars.win, vars.size);
	//ft_printf("The number of collectible in this map is %d\n", count_collectible(vars.map));
	mlx_key_hook(vars.win, key_control, &vars);
	mlx_loop(vars.mlx);
}
