/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:46:44 by aranger           #+#    #+#             */
/*   Updated: 2024/04/08 16:51:59 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

uint32_t	convert_color(unsigned int color)
{
	return((color << 8) | 0xff);
}

void	put_pixel(mlx_image_t *img, uint32_t x,
						uint32_t y, int color)
{
	if ((x > 0 && x < img->width) && (y > 0 && y < img->height))
		mlx_put_pixel(img, x, y, color);
}
