/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_aranger.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:49:25 by aranger           #+#    #+#             */
/*   Updated: 2024/04/14 17:31:06 by aranger          ###   ########.fr       */
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
			side = 0;
		}
		else
		{
			var->side_dist_y += var->dt_y;
			var->pos_y += var->step_y;
			side = 1;
		}
		if (game->map->map2d[var->pos_y][var->pos_x] == '1')
			hit = 1;
	}
	return (side);
}

static void	draw_ver_line(t_params *game, t_var_raycasting *var, int x_position,  int side)
{
	int	color;
	int	y;

	y = 0;
	printf("start = %d || end = %d\n", var->start, var->end);
	while (y < HEIGHT)
	{
		if (y <  var->start)
			color = convert_color(game->ceiling_color);
		else if (y > var->end)
			color = convert_color(game->floor_color);
		else
		{
			color = convert_color(rgb_to_int(200,50,0));
			if (side == 1)
	  			color = color / 2;
		}
		mlx_put_pixel(game->win->img, x_position, y, color);
		y++;
	}
}

void	set_start_and_end(t_var_raycasting *var, int h_line)
{
	var->start = -h_line / 2 + HEIGHT / 2 - 150; //pourquoi 150 ????
	if (var->start < 0)
		var->start = 0;
	var->end = h_line / 2 + HEIGHT / 2;
	if (var->end >= HEIGHT)
		var->end = HEIGHT - 1;
}

t_bool  raycasting_1(t_params *game, t_window_settings *set, t_player *p)
{
	int		i;
	int 	side; //was a NS or a EW wall hit?
	int		h_line;
	t_var_raycasting var;

	i = 0;
	set_map_w_and_h(game);
	while (i < WIDTH)
	{
		set_var(&var, p, i);
		side = find_wall(game, &var);
		if (side == 0)
			var.perp_dist = (var.side_dist_x - var.dt_x);
		else
			var.perp_dist = (var.side_dist_y - var.dt_y);
		h_line = (int)(HEIGHT / var.perp_dist);
		set_start_and_end(&var, h_line);
		draw_ver_line(game, &var, i, side);//x, drawStart, drawEnd, game, set, side);
		i++;
	}
	mlx_image_to_window(set->window, set->img, 0, 0);
	return (TRUE);
}
