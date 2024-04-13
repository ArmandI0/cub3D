/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:20:30 by aranger           #+#    #+#             */
/*   Updated: 2024/04/12 16:13:18 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_player(t_window_settings *set)
{
	mlx_image_t	*img;

	img = mlx_new_image(set->window, 50, 50);
	if (!img || (mlx_image_to_window(set->window, img, set->player->pos_x * 10, set->player->pos_y * 10) < 0))
		ft_error(set);
	display_square(0, 0, 10,img, convert_color(0xFF0000), FALSE);
	set->player_img = img;
}