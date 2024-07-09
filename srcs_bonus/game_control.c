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

int	check_direction(int keycode, t_vars *vars, char	**next_pos, t_mapsize *pos)
{
	if (keycode == 100)
	{
		*next_pos = &(vars->map)[pos->y][pos->x+1]; 
		vars->mov_direction = 1;
		return (1);
	}												//keycode == 100 d
	else if (keycode == 97)
	{
		*next_pos = &(vars->map)[pos->y][pos->x-1]; 
		vars->mov_direction = 0;
		return (1);
	}												//keycode == 97 a
	else if (keycode == 119)
	{
		*next_pos = &(vars->map)[pos->y-1][pos->x];
		return (1);
	} //keycode == 119 w
	else if (keycode == 115)
	{
		*next_pos = &(vars->map)[pos->y+1][pos->x];
		return (1);
	} //keycode == 115 s
	return (0);
}

void collect_item(t_vars *vars, char	*next_pos)
{
	if (*next_pos == 'C')
			vars->item_left--;
}

int	win_game(t_vars *vars, char	*next_pos)
{
	if (*next_pos == 'E' && vars->item_left <= 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->mov_count++;
		ft_printf("Move %d\n", vars->mov_count);
		ft_printf("Congratulations, you've delivered all the cakes.\n");
		destroy_vars(vars);
		return (1);
	}
	return (0);
}

int	move_character(int keycode, t_vars *vars)
{
	t_mapsize	*pos;
	char	*next_pos;
	pos = find_player(vars->map);  //check pos is null

	next_pos = NULL;
	if (!check_direction(keycode, vars, &next_pos, pos))
		return (0);
	if (*next_pos != '1')
	{
		collect_item(vars, next_pos);
		if (win_game(vars, next_pos))
		{
			//free(pos);
			//destroy_vars(vars);
			exit(0);
		}
		if (*next_pos == 'M' ) /*move action BONUS*/
		{
			(vars->map)[pos->y][pos->x] = '0';
			*next_pos = 'P';
			vars->mov_count++; /*step ++*/
			render_map(vars); 
			show_step_on_screen(vars);//////Only for bonus
			ft_printf("You lose\n");
			exit(0);
		}
		if (!(*next_pos == 'E' && vars->item_left > 0)) /*move action*/
		{
			(vars->map)[pos->y][pos->x] = '0';
			*next_pos = 'P';
			vars->mov_count++; /*step ++*/
			render_map(vars); 
			show_step_on_screen(vars);//////Only for bonus
			ft_printf("Move %d\n", vars->mov_count);
		}
	}
	//free(pos);
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
