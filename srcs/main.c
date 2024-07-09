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

#include "so_long.h"

void	check_param(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Error\nNo map\n");
		exit(0);
	}
	else if (ac > 2)
	{
		ft_printf("Error\nToo much arguments\n");
		exit(0);
	}

	if (!ft_strnstr(av[1], ".ber",ft_strlen(av[1])))//check if map name is valid
	{
		ft_printf("Error\nInvalid filename\n");
		exit(0);
	}
}

t_vars *init_vars(t_vars *vars, int fd)
{
	vars->map = read_map(fd);
	if (check_map(vars->map) == 0)
	{
		return (NULL);
	}
	
	vars->mlx = mlx_init();
	vars->size = get_map_size(vars->map);
	if (vars->size == NULL)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	vars->item_left = count_char(vars->map, 'C');
	vars->mov_count = 0;
	vars->mov_direction = 0;
	vars->win = mlx_new_window(vars->mlx, (vars->size->x) * SCALE, (vars->size->y) * SCALE, "so_long");	
	return (vars);
}

int	main(int ac, char **av)
{
	int	fd;
	t_vars	vars;

	check_param(ac, av);

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile not exist\n");
		return (1);
	}
	if (init_vars(&vars, fd) == NULL)
		exit(0);
	
	close(fd);
	render_map(&vars);
	mlx_string_put(vars.mlx, vars.win, 20, 20, 0xFFFFFF, ft_strjoin("Move ", ft_itoa(vars.mov_count)));
	mlx_key_hook(vars.win, key_control, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
