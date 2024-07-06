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
		return (0);//sure? can the map be 1 or 2 lines?
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

static	int	is_not_repeat(char **map)
{
	int	i;
	int	j;
	int	k;
	int	curr_char_exist;
	char	*char_srch = "PE";

	i = 0;
	while (char_srch[i])
	{
		j = 0;
		curr_char_exist = 0;
		while (map[j])
		{
			k = 0;
			while (map[j][k])
			{
				if (char_srch[i] == map[j][k])
				{
					if (!curr_char_exist)
						curr_char_exist++;
					else 
						return (0);
				}
				k++;
			}
			j++;	
		}
		i++;
	}
	return (1);
}


/*the following functions can be merged into one, includding the top one*/
int	count_collectible(char **map)
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
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
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
	if (count_collectible(map) > 0)
		return (1);
	return (0);
}

static int has_ab(char **map)
{
	if (count_char(map, 'P') >= 1 && count_char(map, 'E') >= 1)
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

/*
is file exist??


int	is_path_exist(char **map)
{
	this function can use recursive to 	
}
*/

int	check_map(char **map)
{
	int	check_problem;

	check_problem = 0;
	if (!is_rectangle(map))
	{
		ft_printf("Map is not rectangle\n");
		check_problem++;
	}
	if (!is_allchar_valid(map))
	{	
		ft_printf("Map has not legal char\n");
		check_problem++;
	}
	if (!is_not_repeat(map))
	{
		ft_printf("Map has repetitions\n");
		check_problem++;
	}
	if (!has_c(map))
	{
		ft_printf("Map has no collectible\n");
		check_problem++;
	}

	if (!has_ab(map))
	{
		ft_printf("Map has no player or exit\n");
		check_problem++;
	}

	if (!is_map_close(map))
	{
		ft_printf("Map has no contour\n");
		check_problem++;
	}
	/*add test of path exist and file content exist*/
	if (!check_problem)
	{
		ft_printf("Map is valid OK\n");
		return (1);
	}
	
	else
	{
		ft_printf("Error Map is not valid KO\n");
		return (0);
	}
}
/*
int	main(int ac, char **av)
{
	int	fd;
	char **map;

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
	return (0);
}*/
