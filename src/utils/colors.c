/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/03/31 21:48:57 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
