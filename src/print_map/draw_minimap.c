/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:49:38 by aranger           #+#    #+#             */
/*   Updated: 2024/04/08 16:26:16 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void display_square(int start_x, int start_y, int size, t_window_settings *set, uint32_t color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x <= size)
	{
		while (y <= size)
		{
			put_pixel(set->img, start_x + x, start_y + y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

void print_minimap(t_map *minimap, t_window_settings *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (minimap->map2d[i] != NULL)
	{
		while (minimap->map2d[i][j] != '\0')
		{
			if (minimap->map2d[i][j] == '1')
			{
				display_square(j * 10, i * 10, 10, set, 0xFF0000FF);
			}
			else
			{
				display_square(j * 10, i * 10, 10, set, 0x0000FF00);
			}
			j++;
		}
		j=0;
		i++;
	}
}

void display_minimap(t_window_settings *set, t_map *minimap)
{
	mlx_image_t *img;

	(void) minimap;
	img = mlx_new_image(set->window, set->window->height, set->window->height);
	if (!img || (mlx_image_to_window(set->window, img, 0, 0) < 0))
		ft_error(set);
	set->img = img;
	print_minimap(minimap, set);
}