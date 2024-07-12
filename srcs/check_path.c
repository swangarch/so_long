/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:55:29 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 16:55:31 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_x(char **map, int x, int y)
{
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'X')
	{
		map[y][x + 1] = 'X';
		fill_x(map, x + 1, y);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'X')
	{
		map[y][x - 1] = 'X';
		fill_x(map, x - 1, y);
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'X')
	{
		map[y + 1][x] = 'X';
		fill_x(map, x, y + 1);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'X')
	{
		map[y - 1][x] = 'X';
		fill_x(map, x, y - 1);
	}
}

char	**dup_map(char **map)
{
	int		i;
	char	**copymap;

	i = 0;
	while (map[i])
		i++;
	copymap = malloc(sizeof(char *) * (i + 1));
	if (copymap == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copymap[i] = ft_strdup(map[i]);
		i++;
	}
	copymap[i] = NULL;
	return (copymap);
}

int	is_path_exist(char **map)
{
	t_mapsize	*pos;
	char		**copymap;

	copymap = dup_map(map);
	if (copymap == NULL)
		return (0);
	pos = find_player(copymap, 0, 0);
	if (pos == NULL)
	{
		free_map(copymap);
		return (0);
	}
	fill_x(copymap, pos->x, pos->y);
	if (count_char(copymap, 'C') > 0 || \
		count_char(copymap, 'P') > 0 || count_char(copymap, 'E') > 0)
	{
		free(pos);
		free_map(copymap);
		return (0);
	}
	free_map(copymap);
	free(pos);
	return (1);
}

void	fill_x_skip_e(char **map, int x, int y)
{
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'X' && map[y][x + 1] != 'E')
	{
		map[y][x + 1] = 'X';
		fill_x_skip_e(map, x + 1, y);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'X' && map[y][x - 1] != 'E')
	{
		map[y][x - 1] = 'X';
		fill_x_skip_e(map, x - 1, y);
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'X' && map[y + 1][x] != 'E')
	{
		map[y + 1][x] = 'X';
		fill_x_skip_e(map, x, y + 1);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'X' && map[y - 1][x] != 'E')
	{
		map[y - 1][x] = 'X';
		fill_x_skip_e(map, x, y - 1);
	}
}

int	is_path_exist_e(char **map)
{
	t_mapsize	*pos;
	char		**copymap;

	copymap = dup_map(map);
	if (copymap == NULL)
		return (0);
	pos = find_player(copymap, 0, 0);
	if (pos == NULL)
	{
		free_map(copymap);
		return (0);
	}
	fill_x_skip_e(copymap, pos->x, pos->y);
	if (count_char(copymap, 'C') > 0 || count_char(copymap, 'P') > 0)
	{
		free(pos);
		free_map(copymap);
		return (0);
	}
	free_map(copymap);
	free(pos);
	return (1);
}
