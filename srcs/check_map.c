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

static	int	char_in_str(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	is_valid_line(char *s)
{
	int	i;
	char	*charset = "10CPE";

	i = 0;
	while (s[i])
	{
		if (!char_in_str(charset, s[i]) && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*gnl can not know if the NULL is caused by malloc fail or read to the end */
static	int	is_allchar_valid(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!is_valid_line(map[i]))
			return (0);
		i++;
	}
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

static int has_c(char **map)
{
	if (count_char(map, 'C') > 0)
		return (1);
	return (0);
}

static int correct_pe(char **map)
{
	if (count_char(map, 'P') == 1 && count_char(map, 'E') == 1)
		return (1);
	return (0);
}


int	is_map_close(char **map)
{
	int	i;
	int	j;
	t_mapsize *size;

	i = 0;
	size = get_map_size(map);
	while (i < size->y)
	{
		j = 0;
		while (j < size->x)
		{
			if (i == 0 || i == size->y - 1 || j == 0 || j == size->x - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	fill_x(char **map, int	x, int y)
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

int	is_path_exist(char **map)
{
	t_mapsize *pos;
	char	**copymap;

	copymap = dup_map(map);
	if (copymap == NULL)
		return (0);
	pos = find_player(copymap);
	fill_x(copymap, pos->x, pos->y);
	if (count_char(copymap, 'C') > 0 || count_char(copymap, 'P') > 0 || count_char(copymap, 'E') > 0)
	{
		free_map(copymap);	
		return (0);// free dup
	}
	free_map(copymap);
	return (1);
}

int	check_map(char **map)
{
	if (!is_rectangle(map))
	{
		ft_printf("Error\nMap is not rectangle\n");
		return (0);
	}
	if (!is_allchar_valid(map))
	{	
		ft_printf("Error\nMap has not legal char\n");
		return (0);
	}
	
	if (!has_c(map))
	{
		ft_printf("Error\nMap has no collectible\n");
		return (0);
	}

	if (!correct_pe(map))
	{
		ft_printf("Error\nMap has no player or exit or has repetition\n");
		return (0);
	}
	if (!is_map_close(map))
	{
		ft_printf("Error\nMap has no contour\n");
		return (0);
	}
	if (!is_path_exist(map))
	{
		ft_printf("Error\nMap has no path\n");
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
