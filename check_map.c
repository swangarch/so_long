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
/*
int	is_path_exist(char **map)
{
	
}

int	is_map_close(char **map)
{

}

check also if the name of the file is valid, otherwise return error
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
	/*add test of path exist*/
	if (!check_problem)
	{
		ft_printf("Map is valid OK\n");
		return (1);
	}
	/*add check file name .ber */
	else
	{
		ft_printf("Map is not valid KO\n");
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
	if (map == NULL)
		return (1);
	print_map(map);
	check_map(map);
	close(fd);
	return (0);
}*/
