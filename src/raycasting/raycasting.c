/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:49:25 by aranger           #+#    #+#             */
/*   Updated: 2024/04/18 17:08:57 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	set_map_w_and_h(t_params *game)
{
	int	i;

	i = 0;
	game->map->w_map = ft_strlen(game->map->map2d[0]);
	while (game->map->map2d[i] != NULL)
	{
		i++;
	}
	game->map->h_map = i;
}

double	find_next_side(double ray)
{
	double	delta;

	if (ray == 0)
		delta = 1e30;
	else
		delta = fabs(1 / ray);
	return (delta);
}
void	set_var(t_var_raycasting *v, t_player *p, int i)
{
	v->ray_dir_x = p->dir_x + p->plane_x * (2 * i / (double)(WIDTH) - 1);
	v->ray_dir_y = p->dir_y + p->plane_y * (2 * i / (double)(WIDTH) - 1);
	v->dt_x = find_next_side(v->ray_dir_x);
	v->dt_y = find_next_side(v->ray_dir_y);
	v->pos_x = (int)p->pos_x;
	v->pos_y = (int)p->pos_y;
	if (v->ray_dir_x < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (p->pos_x - v->pos_x) * v->dt_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (v->pos_x + 1 - p->pos_x) * v->dt_x;
	}
	if (v->ray_dir_y < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (p->pos_y - v->pos_y) * v->dt_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (v->pos_y + 1 - p->pos_y) * v->dt_y;
	}
}

int	find_wall(t_params *game, t_var_raycasting *var)
{
	int	side;
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (var->side_dist_x < var->side_dist_y)
		{
			var->side_dist_x += var->dt_x;
			var->pos_x += var->step_x;
			side = EAST_WEST;
		}
		else
		{
			var->side_dist_y += var->dt_y;
			var->pos_y += var->step_y;
			side = NORTH_SOUTH;
		}
		if (game->map->map2d[var->pos_y][var->pos_x] == '1')
			hit = 1;
	}
	return (side);
}

static t_param_type	choose_texture(t_player *player,
	t_var_raycasting *var, int side)
{
	if (player->pos_x > var->pos_x && side == EAST_WEST)
		return(PARAM_EA);
	else if (player->pos_x < var->pos_x && side == EAST_WEST)
		return(PARAM_WE);
	else if (player->pos_y > var->pos_y && side == NORTH_SOUTH)
		return(PARAM_SO);
	else if (player->pos_y < var->pos_y && side == NORTH_SOUTH)
		return(PARAM_NO);
	else
		return(PARAM_NO);
}

static int	get_x_on_texture(t_var_raycasting *var, uint32_t width, int side, t_player *p)
{
 	double	wall_x;
	int		x_txt;

	(void)p;
	if (side == EAST_WEST)
		wall_x = (double)p->pos_y + var->perp_dist * var->ray_dir_y;
	else
		wall_x = (double)p->pos_x + var->perp_dist * var->ray_dir_x;
	wall_x -= floor((wall_x));
	x_txt = (int)(wall_x * (double)width);
	if((side == EAST_WEST && var->ray_dir_x > 0)
		|| (side == NORTH_SOUTH && var->ray_dir_y < 0))
		x_txt = width - x_txt - 1; 
	return (x_txt);
}

static void	draw_ver_line(t_params *game, t_var_raycasting *var, int x_position,  int side)
{
	int				color;
	int				y;
	t_param_type	dir_txt;
	double			ratio;
	int				x_txt;

	dir_txt = choose_texture(game->player, var, side);
	x_txt = get_x_on_texture(var, game->texture[dir_txt]->width, side, game->player);
	ratio = (double)(var->end - var->start) / game->texture[dir_txt]->height;
	y = 0;
	while (y < HEIGHT)
	{
		if (y <  var->start)
			color = game->ceiling_color;
		else if (y >= var->end)
			color = game->floor_color;
		else
			color = get_color_px_txt(x_txt, ((double)(y - var->start) / ratio), game->texture[dir_txt]);
		mlx_put_pixel(game->win->img, x_position, y, color);
		y++;
	}
}

void	set_start_and_end(t_var_raycasting *var, int h_line)
{
	var->start = -h_line / 2 + HEIGHT / 2 ;//- 150; //pourquoi 150 ???? pour les faire plus hauts
	if (var->start < 0)
		var->start = 0;
	var->end = h_line / 2 + HEIGHT / 2;
	if (var->end >= HEIGHT)
		var->end = HEIGHT - 1;
}

t_bool  raycasting(t_params *game, t_window_settings *set, t_player *p)
{
	int		i;
	int 	side;
	int		h_line;
	t_var_raycasting var;

	i = 0;
	set_map_w_and_h(game);
	while (i < WIDTH)
	{
		set_var(&var, p, i);
		side = find_wall(game, &var);
		if (side == EAST_WEST)
			var.perp_dist = (var.side_dist_x - var.dt_x);
		else
			var.perp_dist = (var.side_dist_y - var.dt_y);
		h_line = (int)(HEIGHT / var.perp_dist);
		set_start_and_end(&var, h_line);
		draw_ver_line(game, &var, i, side);
		i++;
	}
	mlx_image_to_window(set->window, set->img, 0, 0);
	return (TRUE);
}
