/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:52:00 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/10 19:13:53 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_direction(int keycode, t_vars *vars, char	**next_pos, t_mapsize *pos)
{
	if (keycode == 100)
	{
		*next_pos = &(vars->map)[pos->y][pos->x + 1];
		vars->mov_direction = 1;
		return (1);
	}
	else if (keycode == 97)
	{
		*next_pos = &(vars->map)[pos->y][pos->x - 1];
		vars->mov_direction = 0;
		return (1);
	}
	else if (keycode == 119)
	{
		*next_pos = &(vars->map)[pos->y - 1][pos->x];
		return (1);
	}
	else if (keycode == 115)
	{
		*next_pos = &(vars->map)[pos->y + 1][pos->x];
		return (1);
	}
	return (0);
}

void	collect_item(t_vars *vars, char *next_pos)
{
	if (*next_pos == 'C')
		vars->item_left--;
}

int	win_game(t_vars *vars, char	*next_pos)
{
	if (*next_pos == 'E' && vars->item_left <= 0)
	{
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
	if (!(*next_pos == 'E' && vars->item_left > 0))
	{
		(vars->map)[pos->y][pos->x] = '0';
		*next_pos = 'P';
		vars->mov_count++;
		render_map(vars);
		ft_printf("Move %d\n", vars->mov_count);
	}
	return (0);
}

int	move_character(int keycode, t_vars *vars)
{
	t_mapsize	*pos;
	char		*next_pos;

	pos = find_player(vars->map, 0, 0);
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
		move_forward(vars, pos, next_pos);
	}
	free(pos);
	return (0);
}
