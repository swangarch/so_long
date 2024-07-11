/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:47:10 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/04 19:25:15 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define SCALE 60
# include "libft.h"
# include "mlx.h"
# include <time.h>

typedef struct s_texture {
	void	*image_1;
	void	*image_0;
	void	*image_e;
	void	*image_pl;
	void	*image_c;
	void	*image_c2;
	void	*image_c3;
	void	*image_e2;
	void	*image_pr;
	void	*image_m;
	void	*image_m2;
	void	*image_m3;
}	t_texture;

typedef struct s_mapsize
{
	int	x;
	int	y;
}	t_mapsize;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**map;
	t_mapsize	*size;
	int			item_left;
	int			mov_count;
	int			mov_direction;
	int			frame;
}	t_vars;

char		**read_map(int fd);
void		print_map(char **map);
int			check_map(char **map);
t_mapsize	*get_map_size(char **map);
int			count_char(char **map, char ch);
t_mapsize	*find_player(char **map, int i, int j);
void		free_map(char **map);
void		render_map(t_vars *vars);
int			key_control(int keycode, t_vars *vars);
int			move_character(int keycode, t_vars *vars);
void		show_step_on_screen(t_vars *vars);
int			is_path_exist(char **map);
int			is_allchar_valid(char **map);
void		destroy_vars(t_vars *vars);
void		destroy_textures(t_vars *vars, t_texture *textures);
void		load_textures(t_vars *vars, t_texture *textures, int w, int h);
int			cross_press(t_vars *vars);

void		render_background(t_vars *vars, int i, int j, t_texture	*textures);
void		render_player(t_vars *vars, int i, int j, t_texture	*textures);
void		render_exit(t_vars *vars, int i, int j, t_texture *textures);
void		render_item(t_vars *vars, int i, int j, t_texture *textures);
void		render_enemy(t_vars *vars, int i, int j, t_texture	*textures);

int			check_direction(int keycode, t_vars *vars, char	**next_pos, \
				t_mapsize *pos);
void		collect_item(t_vars *vars, char *next_pos);
int			win_game(t_vars *vars, char	*next_pos);
int			move_forward(t_vars *vars, t_mapsize *pos, char *next_pos);
int			move_character(int keycode, t_vars *vars);
int			touch_enemy(t_vars *vars, t_mapsize *pos, char *next_pos);

#endif
