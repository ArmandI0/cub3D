/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:16:09 by aranger           #+#    #+#             */
/*   Updated: 2024/04/19 12:56:55 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void rotate_player(t_player *player, double angle)
{
    double	rad;
	double	cos_r;
	double	sin_r;
	
	rad = M_PI * angle / 180.0;
	cos_r = cos(rad);
	sin_r = sin(rad);
    player->dir_x = player->dir_x * cos_r - player->dir_y * sin_r;
    player->dir_y = player->dir_x * sin_r + player->dir_y * cos_r;
    player->plane_x = player->plane_x * cos_r - player->plane_y * sin_r;
    player->plane_y = player->plane_x * sin_r + player->plane_y * cos_r;
}

void translate_player_forward(t_player *player, double step, char** map)
{
    double  new_pos_x;
    double  new_pos_y;
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
    double  new_pos_x;
    double  new_pos_y;
	/* double	hit_x;
	double	hit_y; */

    new_pos_x = player->pos_x + (player->plane_x * step);
    new_pos_y = player->pos_y + (player->plane_y * step);
/* 	hit_x = player->pos_x + (player->plane_x * step * 2);
	hit_y = player->pos_y + (player->plane_y * step * 2); */
	if (map[(int)new_pos_y][(int)new_pos_x] == '1')
		return ;
    player->pos_x = new_pos_x;
    player->pos_y = new_pos_y;
}
