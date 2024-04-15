/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:17:03 by aranger           #+#    #+#             */
/*   Updated: 2024/04/13 20:46:14 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	cursor_fct(double xpos, double ypos, void *param)
{
	t_params		*p;
	
	p = param;
	(void) ypos;
	if (xpos > 540)
		rotation(p, 1);
	else if (xpos < 540)
		rotation(p, -1);
	mlx_set_mouse_pos(p->win->window, 540, 360);
}
