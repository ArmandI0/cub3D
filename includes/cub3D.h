/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:40:47 by aranger           #+#    #+#             */
/*   Updated: 2024/04/13 20:39:54 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/src/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define WIDTH 1080
# define HEIGHT 720

typedef int	t_bool;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	//int		w_map;
//	int		h_map;
}			t_player;

typedef struct s_window_settings
{
	int			w;
	int			h;
	mlx_image_t	*img;
	mlx_image_t	*player_img;
	mlx_image_t	*minimap_img;
	mlx_t		*window;
}				t_window_settings;

typedef	struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct s_map
{
	char	**map2d;
	t_coord	player;
	t_coord	dir_vector;
	int		w_map;
	int		h_map;
}				t_map;

typedef enum cb_errors
{
	ER_NB_ARGS,
	ER_MAP_TYPE,
	ER_FILE_N_FOUND,
	ER_EXTRACTION_MAP,
	ER_INVALID_MAP_DOUBLE,
	ER_INVALID_MAP_FILE,
	ER_INVALID_MAP_NULL_PATH,
	ER_INVALID_MAP_NULL_COLOR,
	ER_FILE_TEXTURE_N_FOUND,
	ER_INVALID_MAP_CHARACTER,
	ER_INVALID_MAP_EMPTY_LINES,
	ER_NO_STARTPOINT,
	ER_TOO_MANY_STARTPOINT,
	ER_MISSING_WALLS,
}			t_errors;

typedef enum cb_param_type
{
	PARAM_NO,
	PARAM_SO,
	PARAM_EA,
	PARAM_WE,
	PARAM_F,
	PARAM_C,
}			t_param_type;

typedef struct s_params
{
	t_map		*map;
	t_window_settings *win;
	t_player		*player;
	int			nb_map_lines;
	char		*path_texture[4];
	int			ceiling_color;
	int			floor_color;
	t_list		*head_list_lines;
}			t_params;

/* PARSING FUNCTIONS */
void		map_file_parsing(t_params *game, const char *filepath);
t_bool		extract_file_into_list(t_params *game, const char *filepath);
t_errors	extract_path_textures(t_params *game, t_list *head);
t_errors	extract_colors(t_params *game, t_list *head);
t_list		*get_line_with_str(t_list *head, char *str);
t_errors	extract_rgb_str(t_params *game, t_list *color,
			char *set, t_param_type p_type);
t_errors	extract_map(t_params *game);
t_bool		is_line_empty(t_list *last);
t_bool		map_to_tab(t_params *game, t_list *head);
t_bool		check_walls(t_params *game);

/* EXEC FUNCTIONS */

void		my_keyhook(mlx_key_data_t keydata, void *param);
void		resize_mlx(int32_t width, int32_t height, void *param);
void		put_pixel(mlx_image_t *img, uint32_t x,
						uint32_t y, int color);
void		close_fct(void *param);
t_map *		init_argument(void); // init the data structure
void 		display_minimap(t_params *p);
void		ft_error(t_window_settings *set);
uint32_t	convert_color(unsigned int color);
void		display_square(int start_x, int start_y, int size, mlx_image_t *img, uint32_t color, t_bool border);
void		print_player(t_params *p);

/* FREE FUNCTIONS */
void	free_game(t_params *game);
void	free_path_textures(t_params *game);
void	free_el_list(t_list *element);

/* RAY CASTING FUNCTIONS*/
t_bool  raycasting(t_params *game, t_window_settings *set, t_player *player);

/* UTILS FUNCTIONS */
void	check_args(int argc, const char **argv);
void	print_error(t_errors error);
int		rgb_to_int(unsigned char red, unsigned char green, unsigned char blue);
void	del_el_list(t_list *element, t_params *game);
t_player	*init_new_players(char direction, double x, double y);
void rotate_player(t_player *player, double angle);
mlx_image_t	*set_img(t_window_settings *set);
void 	translate_player_forward(t_player *player, double step, char** map);
void	translate_player_l_to_r(t_player *player, double step,  char** map);
void	cursor_fct(double xpos, double ypos, void *param);
void	init_command(t_params *game);
void	exit_fct(t_params *param);
void	rotation(t_params *p, double step);

#endif