/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:43:06 by aranger           #+#    #+#             */
/*   Updated: 2024/04/13 19:16:29 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_player	*init_new_players(char direction, double x, double y)
{
	t_player	*new_player;

	new_player = ft_calloc(1, sizeof(t_player));
	if (new_player == NULL)
		return (NULL);
	if (direction == 'N')
	{
		new_player->dir_x = 0;
		new_player->dir_y = -1;
		new_player->plane_x = 0.66;
	}	
	else if (direction == 'S')
	{
		new_player->dir_x = 0;
		new_player->dir_y = 1;
		new_player->plane_x = -0.66;
	}	
	else if (direction == 'W')
	{
		new_player->dir_x = -1;
		new_player->dir_y = 0;
		new_player->plane_y = 0.66;
	}	
	else if (direction == 'E')
	{
		new_player->dir_x = 1;
		new_player->dir_y = 0;
		new_player->plane_y = -0.66;
	}		
	new_player->pos_x = x;
	new_player->pos_y = y;
	return (new_player);
}


