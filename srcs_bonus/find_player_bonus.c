/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:59:01 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 14:59:05 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_mapsize	*get_map_size(char **map)
{
	int		i;
	int		j;
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

t_mapsize	*find_player(char **map, int i, int j)
{
	t_mapsize *position;
	t_mapsize *size;
	
	size = get_map_size(map);
	if (size == NULL)
		return (NULL);
	position = malloc(sizeof(t_mapsize));
	if (position == NULL)
	{
		free(size);
		return (NULL);
	}
	while (i < size->y)
	{
		j = 0;
		while (j < size->x)
		{
			if (map[i][j] == 'P')
			{
				position->x = j;
				position->y = i;
				free(size);
				return (position);
			} 
			j++;
		}
		i++;
	}
	free(size);
	free(position);
	return (NULL);
}