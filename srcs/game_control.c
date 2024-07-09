/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:01:50 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 15:01:51 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_character(int keycode, t_vars *vars)
{
	t_mapsize	*pos;
	char	*next_pos;
	pos = find_player(vars->map);  //check pos is null
	char	*count;

	if (keycode == 100)
	{
		next_pos = &(vars->map)[pos->y][pos->x+1]; 
		vars->mov_direction = 1;
	}												//keycode == 100 d
	else if (keycode == 97)
	{
		next_pos = &(vars->map)[pos->y][pos->x-1]; 
		vars->mov_direction = 0;
	}												//keycode == 97 a
	else if (keycode == 119)
		next_pos = &(vars->map)[pos->y-1][pos->x]; //keycode == 119 w
	else if (keycode == 115)
		next_pos = &(vars->map)[pos->y+1][pos->x]; //keycode == 115 s
	else
		return (0);
	if (*next_pos != '1')
	{
		if (*next_pos == 'C')
			vars->item_left--;
		if (*next_pos == 'E' && vars->item_left <= 0)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			vars->mov_count++;
			ft_printf("Movement count is %d\n", vars->mov_count);
			ft_printf("You win\n");
			exit(0);
		}
		if (!(*next_pos == 'E' && vars->item_left > 0))
		{
			(vars->map)[pos->y][pos->x] = '0';
			*next_pos = 'P';
			vars->mov_count++;
			render_map(vars);
			count = ft_itoa(vars->mov_count); //leak
			count = ft_strjoin("Move ", count);//leak	
			mlx_string_put(vars->mlx, vars->win, 20, 20, 0xFFFFFF, count);
			ft_printf("Movement count is %d\n", vars->mov_count);
		}
	}
	return (0);
}

int	key_control(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}	
	move_character(keycode, vars);
	return (0);
}
