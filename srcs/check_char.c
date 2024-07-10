/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:02:33 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/09 17:02:34 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		i;
	char	*charset;

	charset = "10CPE";
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
int	is_allchar_valid(char **map)
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
