/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:59:01 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 14:59:05 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mapsize	*get_map_size(char **map)
{
	int			i;
	int			j;
	t_mapsize	*size;

	i = 0;
	j = 0;
	size = malloc(sizeof(t_mapsize));
	if (size == NULL)
		return (NULL);
	while (map[i])
	{
		while (map[i][j] != '\n')
			j++;
		i++;
	}
	size->x = j;
	size->y = i;
	return (size);
}

static void	set_size(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\n')
			j++;
		i++;
	}
	*x = j;
	*y = i;
}

t_mapsize	*find_player(char **map, int i, int j)
{
	t_mapsize	*position;
	int			x;
	int			y;

	set_size(map, &x, &y);
	position = malloc(sizeof(t_mapsize));
	if (position == NULL)
		return (NULL);
	while (i < y)
	{
		j = 0;
		while (j < x)
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
	free(position);
	return (NULL);
}
