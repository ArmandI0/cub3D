/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:55:08 by aranger           #+#    #+#             */
/*   Updated: 2024/04/09 12:28:30 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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