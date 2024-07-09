/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:47:10 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/04 19:25:15 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SCALE 60
# include "libft.h"
# include "mlx.h"

typedef	struct s_mapsize
{
	int	x;
	int	y;
}	t_mapsize;

typedef	struct s_texture {
	void	*image1;
	void	*image2;
	void	*image3;
	void	*image4;
	void	*image5;
	void	*image6;
	void	*image7;
} t_texture;

typedef	struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	t_mapsize *size;
	int		item_left;
	int		mov_count;
	int		mov_direction;
}	t_vars;

char	**read_map(int fd);
void	print_map(char **map);
int     check_map(char **map);
t_mapsize       *get_map_size(char **map);
int	count_char(char **map, char ch);
t_mapsize	*find_player(char **map);
void	free_map(char **map);
void	render_map(t_vars *vars);
int	key_control(int keycode, t_vars *vars);
int	move_character(int keycode, t_vars *vars);
void	show_step_on_screen(t_vars *vars);
int	is_path_exist(char **map);
int	is_allchar_valid(char **map);
void	destroy_vars(t_vars *vars);
void	destroy_textures(t_vars *vars, t_texture *textures);

#endif
