/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:47:15 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/04 18:54:10 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	t_list	*map_tolist(int	fd)
{
	t_list	*lst;
	t_list	*head;

	lst = ft_lstnew((void *)get_next_line(fd));
	head = lst;
	while (lst)
	{
		lst->next = ft_lstnew((void *)get_next_line(fd));
		if (lst->next->content)
			lst = lst->next;
		else
			break ;
	}
	return (head);
}

int	count_map_line(t_list *lst)
{
	t_list	*curr;
	int	count;

	count = 0;
	curr = lst;
	while (curr->content)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

static	char	**lst_tomap(t_list *lst) /*normally this fonction will not have leak risk when fail*/
{
	char	**map;
	int	num_line;
	int	i;
	t_list	*curr;

	curr = lst;	
	num_line = count_map_line(lst);
	map = malloc((sizeof(char *) + 1) * num_line);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (curr->content)
	{
		map[i] = (char *)(curr->content);
		curr = curr->next;
	       	i++;
	}	
	map[i] = NULL;
	///////ft_lstfree(lst);   here use a function to clear the list but keep content
	return (map);
}


/*this funtion is just for testing, after need to convert it into malloc, so no more need for this*/
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}

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

char	**read_map(int fd)
{
	return (lst_tomap(map_tolist(fd)));
}
/*
int	main(int ac, char **av)
{
	int	fd;
	char	**map;

	fd = open(av[1], O_RDONLY);
	map = read_map(fd);
	print_map(map);	
	return (0);
}*/
