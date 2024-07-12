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

static t_list	*map_tolist(int fd)
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

static int	count_map_line(t_list *lst)
{
	t_list	*curr;
	int		count;

	count = 0;
	curr = lst;
	while (curr->content)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

static void	ft_lst_freenode(t_list **lst)
{
	t_list	*curr;
	t_list	*freenode;

	curr = *lst;
	if (*lst == NULL)
		return ;
	while (curr != NULL)
	{
		freenode = curr;
		curr = curr->next;
		free(freenode);
		freenode = NULL;
	}
	*lst = NULL;
}

static	char	**lst_tomap(t_list *lst)
{
	char	**map;
	int		num_line;
	int		i;
	t_list	*curr;

	num_line = 0;
	curr = lst;
	num_line = count_map_line(lst);
	map = malloc(sizeof(char *) * (1 + num_line));
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
	ft_lst_freenode(&lst);
	return (map);
}

char	**read_map(int fd)
{
	return (lst_tomap(map_tolist(fd)));
}

/*this funtion is just for testing, 
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
}*/

/*
int	main(int ac, char **av)
{
	int	fd;
	char	**map;

	fd = open(av[1], O_RDONLY);
	map = read_map(fd);
	print_map(map);	
	free_map(map);
	return (0);
}*/
