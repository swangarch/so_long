/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:28:35 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/05 16:32:36 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	is_rectangle(char **map)
{
	int	i;
	int	currl;
	int	nextl;

	i = 0;
	while (map[i])
	{
		currl = ft_strlen(map[i]);
		i++;
		if (map[i])
		{
			nextl = ft_strlen(map[i]);
			if (nextl != currl)
				return (0);
		}
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	count_char(char **map, char ch)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ch)
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

static int	correct_cpe(char **map)
{
	if (count_char(map, 'P') == 1 && \
			count_char(map, 'E') == 1 && count_char(map, 'C') > 0)
		return (1);
	return (0);
}

int	is_map_close(char **map, int i, int j)
{
	t_mapsize	*size;

	size = get_map_size(map);
	if (size == NULL)
		return (0);
	while (i < size->y)
	{
		j = 0;
		while (j < size->x)
		{
			if (i == 0 || i == size->y - 1 || j == 0 || j == size->x - 1)
			{
				if (map[i][j] != '1')
				{
					free(size);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	free(size);
	return (1);
}

int	check_map(char **map)
{
	if (!is_rectangle(map) || !is_map_close(map, 0, 0))
	{
		ft_putstr_fd("Error\nMap is not closed rectangle.\n", 2);
		return (0);
	}
	if (!is_allchar_valid(map))
	{
		ft_putstr_fd("Error\nMap has not legal char.\n", 2);
		return (0);
	}
	if (!correct_cpe(map))
	{
		ft_putstr_fd("Error\nPlayer/exit/collectible number incorrect.\n", 2);
		return (0);
	}
	if (!is_path_exist(map) || !is_path_exist_e(map))
	{
		ft_putstr_fd("Error\nMap has no path\n", 2);
		return (0);
	}
	return (1);
}
/*
int	main(int ac, char **av)
{
	int	fd;
	char **map;
	t_mapsize *pos;

	if (!ft_strnstr(av[1], ".ber",ft_strlen(av[1])))//check if map name is valid
	{
		ft_printf("Error(Invalid mapname)\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	map = read_map(fd);
	close(fd);
	if (map == NULL)
		return (1);
	print_map(map);
	check_map(map);
	pos = find_player(map);
	fill_x(map, pos->x, pos->y);
	print_map(map);
	return (0);
}*/
