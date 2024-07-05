/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:47:10 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/04 19:25:15 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

typedef	struct s_mapsize
{
	int	x;
	int	y;
}	t_mapsize;

char	**read_map(int fd);
void	print_map(char **map);
int     check_map(char **map);
t_mapsize       *get_map_size(char **map);

#endif
