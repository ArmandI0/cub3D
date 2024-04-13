/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:17:03 by aranger           #+#    #+#             */
/*   Updated: 2024/04/13 18:06:26 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	cursor_fct(double xpos, double ypos, void *param)
{
	static double	old_xpos = -1;
	t_params		*p;
	
	p = param;
	printf("xpos = %f // ypos = %f \n", xpos, ypos);
	if (xpos > 540)
	{
		rotate_player(p->player, +1);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
		mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10);
		print_player(p->set);
	}
	else if (xpos < 540)
	{
		rotate_player(p->player, -1);
		mlx_delete_image(p->set->window, p->set->img);
		p->set->img = set_img(p->set);
		raycasting(p, p->set, p->player);
		mlx_image_to_window(p->set->window, p->set->minimap_img, 10, 10);
		print_player(p->set);
	}
	mlx_set_mouse_pos(p->set->window, 540, 360);
	old_xpos = xpos;
}

// void	mouse_settings(t_params *param)
// {
	
	
// }
