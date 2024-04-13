/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:49:38 by aranger           #+#    #+#             */
/*   Updated: 2024/04/13 20:43:53 by aranger          ###   ########.fr       */
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
				display_square(j * size, i * size, size, set->minimap_img, convert_color(0x00D7FF), TRUE );
			else if (minimap->map2d[i][j] == '0')
				display_square(j * size, i * size, size, set->minimap_img,convert_color(0xFFCF00), TRUE );
			else if (minimap->map2d[i][j] == 'N')
				display_square(j * size, i * size, size, set->minimap_img, convert_color(0x00D7FF), TRUE);
			else
				display_square(j * size, i * size, size, set->minimap_img, convert_color(0x000000), FALSE);
			j++;
		}
		j=0;
		i++;
	}
}

void display_minimap(t_params *p)
{
	mlx_image_t	*img;
	t_window_settings	*set;
	
	set = p->win;
	img = mlx_new_image(set->window, 500, 500);
	if (!img || (mlx_image_to_window(set->window, img, 10, 10) < 0))
		ft_error(set);
	set->minimap_img = img;
	print_minimap(p->map, set);
	print_player(p);
}
