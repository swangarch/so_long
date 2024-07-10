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
		//mlx_destroy_window(vars->mlx, vars->win);
		vars->mov_count++;
		ft_printf("Move %d\n", vars->mov_count);
		ft_printf("Congratulations, you've delivered all the cakes.\n");
		destroy_vars(vars);
		return (1);
	}
	return (0);
}

int	move_forward(t_vars *vars, t_mapsize *pos, char *next_pos)
{
	if (!(*next_pos == 'E' && vars->item_left > 0)) /*move action*/
	{
		(vars->map)[pos->y][pos->x] = '0';
		*next_pos = 'P';
		vars->mov_count++; /*step ++*/
		render_map(vars); 
		show_step_on_screen(vars);//////Only for bonus
		ft_printf("Move %d\n", vars->mov_count);
	}
	return (0);
}

int	touch_enemy(t_vars *vars, t_mapsize *pos, char *next_pos)  ////////////BONUS
{
	if (*next_pos == 'M' ) /*move action BONUS*/
	{
		(vars->map)[pos->y][pos->x] = '0';
		*next_pos = 'P';
		vars->mov_count++; /*step ++*/
		render_map(vars); 
		show_step_on_screen(vars);//////Only for bonus
		ft_printf("You lose\n");
		free(pos);
		destroy_vars(vars);
		exit(0);
	}
	return (0);
}

int	move_character(int keycode, t_vars *vars)
{
	t_mapsize	*pos;
	char	*next_pos;
	pos = find_player(vars->map);  //check pos is null
	if (pos == NULL)
		return (-1);

	next_pos = NULL;
	if (!check_direction(keycode, vars, &next_pos, pos))
	{
		free(pos);
		return (0);
	}
	if (*next_pos != '1')
	{
		if (win_game(vars, next_pos))
		{
			free(pos);
			exit(0);
		}
		collect_item(vars, next_pos);
		touch_enemy(vars, pos, next_pos); /////////////////////BONUS
		move_forward(vars, pos, next_pos);
	}
	free(pos);
	return (0);
}

int	key_control(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		destroy_vars(vars);
		exit(0);
	}	
	move_character(keycode, vars);
	return (0);
}

int	cross_press(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
