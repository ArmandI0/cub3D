/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:29 by nledent           #+#    #+#             */
/*   Updated: 2024/04/02 14:08:48 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_err_free_exit(t_params *game, t_errors error)
{
	print_error(error);
	free_game(game);
	exit (1);	
}
void	map_parsing(t_params *game)
{
	int	error;

	error = extract_map_into_list(game);
	if (error != 0)
		print_err_free_exit(game, error);
	error = extract_path_textures(game, game->head_list_lines);
	if (error != 0)
		print_err_free_exit(game, error);
	error = extract_colors(game, game->head_list_lines);
	if (error != 0)
		print_err_free_exit(game, error);
}
