/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:20:46 by aranger           #+#    #+#             */
/*   Updated: 2024/04/02 16:41:42 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include "../lib/libft/src/libft.h"
# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef enum cb_errors
{
	ER_NB_ARGS,
	ER_MAP_TYPE,
	ER_FILE_N_FOUND,
	ER_EXTRACTION_MAP,
	ER_INVALID_MAP_DOUBLE,
	ER_INVALID_MAP_FILE,
	ER_INVALID_MAP_NULL_PATH,
	ER_FILE_TEXTURE_N_FOUND,
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
	const char	*map_file;
	char		*path_texture[4];
	int			ceiling_color;
	int			floor_color;
	t_list		*head_list_lines;
}			t_params;

/* PARSING FUNCTIONS */
void	map_parsing(t_params *game);
t_bool	extract_map_into_list(t_params *game);
int		extract_path_textures(t_params *game, t_list *head);
int		extract_colors(t_params *game, t_list *head);
t_list	*get_line_with_str(t_list *head, char *str);

/* EXEC FUNCTION */

/* FREE FUNCTIONS */
void	free_game(t_params *game);
void	free_path_textures(t_params *game);

/* UTILS FONCTIONS */
void	check_args(int argc, const char **argv);
void	print_error(t_errors error);
int		rgb_to_int(unsigned char red, unsigned char green, unsigned char blue);

#endif
