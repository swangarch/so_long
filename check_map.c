#include "libft.h"

int	is_rectangle(int fd)
{
	char	*line;
	int	numchar;
	int	numcharnext;
	int	numline;

	line = get_next_line(fd);
	if (line)
		numline++;
	while (line)
	{
		numchar = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
		numcharnext = ft_strlen(line);
		numline++;
		if (numchar != numcharnext)
			return (0);
	}
	if (numline <= 1)
		return (0);
	return (1);
}

int	char_in_str(char *s, char c)
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

int	is_allchar_valid(char *s)
{
	int	i;
	int	j;
	char	*charset = "10CPE";

	i = 0;
	while (s[i])
	{
		j = 0;
		if (!char_in_str(charset, s[i]))
			return (0);
		i++;
	}
	return (1);
}

/*gnl can not know if the NULL is caused by malloc fail or read to the end */
int	is_validchar_map(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!is_allchar_valid(line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}
/*
int	is_not_repeat(fd)
{

}

int	is_path_exist(fd)
{
	
}

int	is_validmap(fd)
{
}

char	**collect_map(fd)
{
	
}
*/
int	main(int ac, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	
	if (is_rectangle(fd) && is_validchar_map(fd))
		ft_printf("Map valid\n");
	else
		ft_printf("Error\n");
	close(fd);
	return (0);
}
