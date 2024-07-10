/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:56:28 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/10 18:56:30 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_direction(int keycode, t_vars *vars, char	**next_pos, t_mapsize *pos)
{
	if (keycode == 100)/*D*/
	{
		*next_pos = &(vars->map)[pos->y][pos->x+1]; 
		vars->mov_direction = 1;
		return (1);
	}												
	else if (keycode == 97)/*A*/
	{
		*next_pos = &(vars->map)[pos->y][pos->x-1]; 
		vars->mov_direction = 0;
		return (1);
	}
	else if (keycode == 119)/*W*/
	{
		*next_pos = &(vars->map)[pos->y-1][pos->x];
		return (1);
	}
	else if (keycode == 115)/*S*/
	{
		*next_pos = &(vars->map)[pos->y+1][pos->x];
		return (1);
	} 
	return (0);
}

void collect_item(t_vars *vars, char *next_pos)
{
	if (*next_pos == 'C')
			vars->item_left--;
}

int	win_game(t_vars *vars, char	*next_pos)
{
	if (*next_pos == 'E' && vars->item_left <= 0)
	{
		vars->mov_count++;
		ft_printf("Congratulations, you've delivered all the cakes.\n");
		destroy_vars(vars);
		return (1);
	}
	return (0);
}

int	move_forward(t_vars *vars, t_mapsize *pos, char *next_pos)
{
	if (!(*next_pos == 'E' && vars->item_left > 0)) 
	{
		(vars->map)[pos->y][pos->x] = '0';
		*next_pos = 'P';
		vars->mov_count++;
		render_map(vars); 
		show_step_on_screen(vars);/*---------------BONUS-------------------*/
	}
	return (0);
}

/*---------------BONUS-------------------*/
int	touch_enemy(t_vars *vars, t_mapsize *pos, char *next_pos)  
{
	if (*next_pos == 'M' ) 
	{
		(vars->map)[pos->y][pos->x] = '0';
		*next_pos = 'P';
		vars->mov_count++;
		render_map(vars); 
		show_step_on_screen(vars);/*---------------BONUS-------------------*/
		ft_printf("You lose\n");
		free(pos);
		destroy_vars(vars);
		exit(0);
	}
	return (0);
}
/*---------------BONUS-------------------*/
