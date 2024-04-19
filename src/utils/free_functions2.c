/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/19 10:54:54 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_img_anim(t_params *game)
{
	if (game->anim_p[0] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[0]);
	if (game->anim_p[1] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[1]);
	if (game->anim_p[2] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[2]);
	if (game->anim_p[3] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[3]);
	if (game->anim_p[4] != NULL)
		mlx_delete_image(game->win->window, game->anim_p[4]);
}
