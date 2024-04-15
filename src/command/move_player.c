/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:16:09 by aranger           #+#    #+#             */
/*   Updated: 2024/04/13 19:22:40 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

void translate_player_forward(t_player *player, double step, char** map)
{
    double new_pos_x;
    double new_pos_y;
	double	hit_x;
	double	hit_y;

    new_pos_x = player->pos_x + (player->dir_x * step);
    new_pos_y = player->pos_y + (player->dir_y * step);
	hit_x = player->pos_x + (player->dir_x * step * 2);
	hit_y = player->pos_y + (player->dir_y * step * 2);
	if (map[(int)hit_y][(int)hit_x] == '1')
		return ;
    player->pos_x = new_pos_x;
    player->pos_y = new_pos_y;
}

void translate_player_l_to_r(t_player *player, double step,  char** map)
{
    double new_pos_x;
    double new_pos_y;
	double	hit_x;
	double	hit_y;

    new_pos_x = player->pos_x + (player->plane_x * step);
    new_pos_y = player->pos_y + (player->plane_y * step);
	hit_x = player->pos_x + (player->plane_x * step * 2);
	hit_y = player->pos_y + (player->plane_y * step * 2);
	if (map[(int)new_pos_y][(int)new_pos_x] == '1')
		return ;
    player->pos_x = new_pos_x;
    player->pos_y = new_pos_y;
}