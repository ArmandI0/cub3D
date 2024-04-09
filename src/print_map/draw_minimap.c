/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:49:38 by aranger           #+#    #+#             */
/*   Updated: 2024/04/09 15:41:49 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	display_border(int start_x, int start_y, int size, mlx_image_t *img, uint32_t color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x <= size)
	{
		while (y <= size)
		{
			if ((y == 0 || y == size) || (x == 0 || x == size))
				put_pixel(img, start_x + x, start_y + y, color);
			y++;
		}
		y = 0;
		x++;
	}
	
}

void	display_square(int start_x, int start_y, int size, mlx_image_t *img, uint32_t color, t_bool border)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x <= size)
	{
		while (y <= size)
		{
			put_pixel(img, start_x + x, start_y + y, color);
			y++;
		}
		y = 0;
		x++;
	}
	if (border == TRUE)
		display_border(start_x, start_y, size, img, convert_color(0x000000));
}

void print_minimap(t_map *minimap, t_window_settings *set)
{
	int i;
	int j;
	int size;
	
	i = 0;
	j = 0;
	size = 10;
	while (minimap->map2d[i] != NULL)
	{
		while (minimap->map2d[i][j] != '\0')
		{
			if (minimap->map2d[i][j] == '1')
				display_square(j * size, i * size, size, set->img, convert_color(0x00D7FF), TRUE );
			else if (minimap->map2d[i][j] == '0')
				display_square(j * size, i * size, size, set->img,convert_color(0xFFCF00), TRUE );
			else if (minimap->map2d[i][j] == 'P')
				display_square(j * size, i * size, size, set->img, convert_color(0x00D7FF), TRUE);
			else
				display_square(j * size, i * size, size, set->img, convert_color(0x000000), FALSE);
			j++;
		}
		j=0;
		i++;
	}
}

void display_minimap(t_window_settings *set, t_map *minimap)
{
	mlx_image_t *img;

	img = mlx_new_image(set->window, set->window->height, set->window->height);
	if (!img || (mlx_image_to_window(set->window, img, 0, 0) < 0))
		ft_error(set);
	set->img = img;
	mlx_set_instance_depth(img->instances, 0);
	print_minimap(minimap, set);
	print_player(set);
}