/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:06:04 by aranger           #+#    #+#             */
/*   Updated: 2024/04/13 18:30:17 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_command(t_params *game)
{
	mlx_key_hook(game->set->window, &my_keyhook, game);
	mlx_set_cursor_mode(game->set->window, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(game->set->window, &cursor_fct, game);
}