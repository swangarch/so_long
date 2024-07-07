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
	int		mov_direction;
}	t_vars;

void	render_map(t_vars *vars)
{

	void	*image1;
	void	*image2;
	void	*image3;
	void	*image4;
	void	*image5;
	void	*image6;
	void	*image7;
	int		w = 60;
	int		h = 60;	
	int 	scale = 60;

	// protect not fail when image not exist
	image1 = mlx_xpm_file_to_image(vars->mlx, "texture/1.xpm", &w, &h);
	image2 = mlx_xpm_file_to_image(vars->mlx, "texture/0.xpm", &w, &h);
	image3 = mlx_xpm_file_to_image(vars->mlx, "texture/e.xpm", &w, &h);
	image4 = mlx_xpm_file_to_image(vars->mlx, "texture/p.xpm", &w, &h);
	image5 = mlx_xpm_file_to_image(vars->mlx, "texture/c.xpm", &w, &h);
	image6 = mlx_xpm_file_to_image(vars->mlx, "texture/door_small.xpm", &w, &h);
	image7 = mlx_xpm_file_to_image(vars->mlx, "texture/pright.xpm", &w, &h);
	// protect not fail when image not exist

	int	i = 0;
	int	j = 0;
	while (i < vars->size->y)
	{
		j = 0;
		while (j < vars->size->x)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, image1, j * scale, i * scale);
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, image2, j * scale, i * scale);
			if (vars->map[i][j] == 'E' && vars->item_left <= 0)
				mlx_put_image_to_window(vars->mlx, vars->win, image3, j * scale, i * scale);
			if (vars->map[i][j] == 'P')
			{
				if (vars->mov_direction == 0)
					mlx_put_image_to_window(vars->mlx, vars->win, image4, j * scale, i * scale);
				else if (vars->mov_direction == 1)
					mlx_put_image_to_window(vars->mlx, vars->win, image7, j * scale, i * scale);
			}
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, image5, j * scale, i * scale);
			if (vars->map[i][j] == 'E' && vars->item_left > 0)
				mlx_put_image_to_window(vars->mlx, vars->win, image6, j * scale, i * scale);
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

int	move_character(int keycode, t_vars *vars)
{
	t_mapsize	*pos;
	char	*next_pos;
	pos = find_player(vars->map);  //check pos is null
	char	*count;

	if (keycode == 100)
	{
		next_pos = &(vars->map)[pos->y][pos->x+1]; 
		vars->mov_direction = 1;
	}												//keycode == 100 d
	else if (keycode == 97)
	{
		next_pos = &(vars->map)[pos->y][pos->x-1]; 
		vars->mov_direction = 0;
	}												//keycode == 97 a
	else if (keycode == 119)
		next_pos = &(vars->map)[pos->y-1][pos->x]; //keycode == 119 w
	else if (keycode == 115)
		next_pos = &(vars->map)[pos->y+1][pos->x]; //keycode == 115 s
	else
		return (0);
	if (*next_pos != '1')
	{
		if (*next_pos == 'C')
			vars->item_left--;
		if (*next_pos == 'E' && vars->item_left <= 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			vars->mov_count++;
			ft_printf("Movement count is %d\n", vars->mov_count);
			ft_printf("You win\n");
			exit(0);
		}
		if (!(*next_pos == 'E' && vars->item_left > 0))
		{
			(vars->map)[pos->y][pos->x] = '0';
			*next_pos = 'P';
			vars->mov_count++;
			render_map(vars);
			count = ft_itoa(vars->mov_count); //leak
			count = ft_strjoin("Move ", count);//leak	
			mlx_string_put(vars->mlx, vars->win, 20, 20, 0xFFFFFF, count);
			ft_printf("Movement count is %d\n", vars->mov_count);
		}
	}
	return (0);
}

int	key_control(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}	
	move_character(keycode, vars);
	return (0);
}

int	main(int ac, char **av)
{
	int	fd;
	int	scale = 60;
	t_vars	vars;
	char	*count;

	if (ac < 2)
	{
		ft_printf("Error\nNo map\n");
		return (1);
	}
	else if (ac > 2)
	{
		ft_printf("Error\nToo much arguments\n");
		return (1);
	}

	if (!ft_strnstr(av[1], ".ber",ft_strlen(av[1])))//check if map name is valid
	{
		ft_printf("Error\nInvalid filename\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile not exist\n");
		return (1);
	}
	vars.map = read_map(fd);
	if (check_map(vars.map) == 0)
		return (1);
	
	vars.mlx = mlx_init();
	vars.size = get_map_size(vars.map);
	if (vars.size == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	vars.item_left = count_char(vars.map, 'C');
	vars.mov_count = 0;
	vars.mov_direction = 0;
	vars.win = mlx_new_window(vars.mlx, (vars.size->x) * scale, (vars.size->y) * scale, "so_long");	
	render_map(&vars);
	count = ft_itoa(vars.mov_count); //leak
	count = ft_strjoin("Move ", count);//leaki
	mlx_string_put(vars.mlx, vars.win, 20, 20, 0xFFFFFF, count);
	//ft_printf("The number of collectible in this map is %d\n", count_collectible(vars.map));
	mlx_key_hook(vars.win, key_control, &vars);
	mlx_loop(vars.mlx);
}
