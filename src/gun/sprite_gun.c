/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:26:03 by aranger           #+#    #+#             */
/*   Updated: 2024/04/18 16:10:45 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

xpm_t	**sprite_gun(void)
{
	xpm_t	**gun;

	gun = malloc(sizeof(xpm_t) * 4);

	gun[0] = mlx_load_xpm42("/texture/gun1.xpm");
	gun[1] = mlx_load_xpm42("/texture/gun2.xpm");
	gun[2] = mlx_load_xpm42("/texture/gun3.xpm");
	gun[3] = mlx_load_xpm42("/texture/gun4.xpm");
	return(gun);
}