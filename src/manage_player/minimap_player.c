/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:20:30 by aranger           #+#    #+#             */
/*   Updated: 2024/04/09 12:41:51 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_player(t_window_settings *set)
{
	mlx_image_t	*img;

	img = mlx_new_image(set->window, 50, 50);
	if (!img || (mlx_image_to_window(set->window, img, 75, 75) < 0))
		ft_error(set);
	mlx_set_instance_depth(img->instances, 10);
	mlx_image_to_window(set->window, img, 75, 75);
	display_square(0, 0, 10,img, convert_color(0x00D7FF), FALSE);
	set->player_img = img;
}