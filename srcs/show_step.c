/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:27:46 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 16:27:49 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_step_on_screen(t_vars *vars)////////////////////////BONUS
{
	char	*count;

	count = ft_itoa(vars->mov_count); //leak protection
	count = ft_strjoin("Move ", count);//leak	
	mlx_string_put(vars->mlx, vars->win, 20, 20, 0xFFFFFF, count);
}