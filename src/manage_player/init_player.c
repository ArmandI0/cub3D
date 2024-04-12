/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:43:06 by aranger           #+#    #+#             */
/*   Updated: 2024/04/12 15:35:19 by aranger          ###   ########.fr       */
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


void rotate_player(t_player *player, double angle)
{
    double new_dirX;
    double new_dirY;
    double new_planeX;
    double new_planeY;
    double rad = M_PI * angle / 180.0;

    new_dirX = player->dir_x * cos(rad) - player->dir_y * sin(rad);
    new_dirY = player->dir_x * sin(rad) + player->dir_y * cos(rad);
    player->dir_x = new_dirX;
    player->dir_y = new_dirY;
    new_planeX = player->plane_x * cos(rad) - player->plane_y * sin(rad);
    new_planeY = player->plane_x * sin(rad) + player->plane_y * cos(rad);
    player->plane_x = new_planeX;
    player->plane_y = new_planeY;
}

void translate_player_forward(t_player *player, double step)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = player->pos_x + (player->dir_x * step);
    new_pos_y = player->pos_y + (player->dir_y * step);
    player->pos_x = new_pos_x;
    player->pos_y = new_pos_y;
}

void translate_player_l_to_r(t_player *player, double step)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = player->pos_x + (player->plane_x * step);
    new_pos_y = player->pos_y + (player->plane_y * step);
    player->pos_x = new_pos_x;
    player->pos_y = new_pos_y;
}
