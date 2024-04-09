/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/09 14:23:35 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		rgb_to_int(unsigned char red, unsigned char green, unsigned char blue)
{
	int	color;

	color = 0;
	color += (int)red;
	color = color << 8;
	color += (int)green;
	color = color << 8;
	color += (int)blue;
	return (color);
}
