/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:11:45 by aranger           #+#    #+#             */
/*   Updated: 2024/04/21 18:07:01 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	open_door(t_params* game)
{
	t_player	*p;

	p = game->player;
	printf("door = %c\n", game->map->map2d[(int)p->pos_y][(int)p->pos_x - 1]);
	if (p->dir_x < -0.90 && (p->dir_y < 0.45 && p->dir_y > -0.45))
	{
		if (game->map->map2d[(int)p->pos_y][(int)p->pos_x - 1] == 'C')
		{
			game->map->map2d[(int)p->pos_y][(int)p->pos_x - 1] = 'O';
		}
		else if (game->map->map2d[(int)p->pos_y][(int)p->pos_x - 1] == 'O')
		{
			game->map->map2d[(int)p->pos_y][(int)p->pos_x - 1] = 'C';
		}
	}
}