/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/04/07 22:02:46 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_err_free_exit(t_params *game, t_errors error)
{
	print_error(error);
	free_game(game);
	exit (1);	
}

static t_errors	check_if_empty_lines_in_the_map(t_params *game)
{
	t_list	*tmp;

	tmp = game->head_list_lines;
	while (tmp)
	{
		if (is_line_empty(tmp) == TRUE)
			return (ER_INVALID_MAP_EMPTY_LINES);
		tmp = tmp->next;
	}
	return (0);
}

static t_errors	check_startpoints(t_params *game)
{
	t_list	*tmp;
	int		nb_startpoint;
	int		i;

	nb_startpoint = 0;
	tmp = game->head_list_lines;
	while (tmp)
	{
		i = 0;
		while (tmp->content != NULL && tmp->content[i] != 0)
		{
			if (ft_strchr("NSEW", tmp->content[i]) != 0)
				nb_startpoint ++;
			if (nb_startpoint > 1)
				return (ER_TOO_MANY_STARTPOINT);
			i++;
		}
		tmp = tmp->next;
	}
	if (nb_startpoint == 0)
		return (ER_NO_STARTPOINT);
	else
		return (0);
}

void	map_file_parsing(t_params *game, const char *filepath)
{
	int	error;

	error = extract_file_into_list(game, filepath);
	if (error != 0)
		print_err_free_exit(game, error);
	error = extract_path_textures(game, game->head_list_lines);
	if (error != 0)
		print_err_free_exit(game, error);
	error = extract_colors(game, game->head_list_lines);
	if (error != 0)
		print_err_free_exit(game, error);
	error = extract_map(game);
	if (error != 0)
		print_err_free_exit(game, error);
	error = check_if_empty_lines_in_the_map(game);
	if (error != 0)
		print_err_free_exit(game, error);
	error = check_startpoints(game);
	if (error != 0)
		print_err_free_exit(game, error);
	if (map_to_tab(game, game->head_list_lines) == FALSE)
		print_err_free_exit(game, ER_EXTRACTION_MAP);
	error = check_walls(game);
	if (error != 0)
		print_err_free_exit(game, error);
}
