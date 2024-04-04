/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:55:08 by aranger           #+#    #+#             */
/*   Updated: 2024/04/04 14:05:28 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_window_settings	*set;

	set = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(set->window);
	}
}

void	resize_mlx(int32_t width, int32_t height, void *param)
{
	t_window_settings	*set;

	set = param;
	set->window->width = width;
	set->window->height = height;
	mlx_delete_image(set->window, set->img);
}

void	close_fct(void *param)
{
	t_window_settings	*set;

	set = param;
	mlx_close_window(set->window);
}