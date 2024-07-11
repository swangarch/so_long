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
		ft_putstr_fd("Error\nNo map\n", 2);
		exit(0);
	}
	else if (ac > 2)
	{
		ft_putstr_fd("Error\nToo much arguments\n", 2);
		exit(0);
	}
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		ft_putstr_fd("Error\nInvalid filename\n", 2);
		exit(0);
	}
}

t_vars	*init_vars(t_vars *vars, int fd)
{
	vars->map = read_map(fd);
	if (!vars->map || check_map(vars->map) == 0)
	{
		vars->size = NULL;
		vars->win = NULL;
		vars->mlx = NULL;
		destroy_vars(vars);
		return (NULL);
	}
	vars->mlx = mlx_init();
	vars->size = get_map_size(vars->map);
	if (vars->size == NULL)
	{
		destroy_vars(vars);
		ft_putstr_fd("Error\nFailed calculate map size\n", 2);
		return (NULL);
	}
	vars->item_left = count_char(vars->map, 'C');
	vars->mov_count = 0;
	vars->frame = 0;
	vars->mov_direction = 0;
	vars->win = mlx_new_window(vars->mlx, (vars->size->x) * SCALE, \
		(vars->size->y) * SCALE, "so_long");
	return (vars);
}

int	main(int ac, char **av)
{
	int		fd;
	t_vars	vars;

	check_param(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFile not exist\n", 2);
		return (1);
	}
	if (init_vars(&vars, fd) == NULL)
		return (1);
	close(fd);
	render_map(&vars);
	mlx_key_hook(vars.win, key_control, &vars);
	mlx_hook(vars.win, 17, 0, cross_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
