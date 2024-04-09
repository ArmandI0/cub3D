/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_oct_1_5_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:25:52 by aranger           #+#    #+#             */
/*   Updated: 2023/12/26 12:13:59 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	octant1(t_map_setting *set, t_line *line)
{
	int	dx;
	int	dy;
	int	y;
	int	eps;
	int	x;

	x = line->start->x;
	y = line->start->y;
	dx = abs(line->end->x - line->start->x);
	dy = abs(line->end->y - line->start->y);
	eps = 0;
	while (x <= line->end->x)
	{
		putpixel_improved(set, x, y, line->color);
		eps += dy;
		if ((eps << 1) >= dx)
		{
			eps -= dx;
			y++;
		}
		x++;
	}
}

void	octant2(t_map_setting *set, t_line *line)
{
	int	dx;
	int	dy;
	int	y;
	int	eps;
	int	x;

	x = line->start->x;
	y = line->start->y;
	dx = abs(line->end->x - line->start->x);
	dy = abs(line->end->y - line->start->y);
	eps = 0;
	while (y <= line->end->y)
	{
		putpixel_improved(set, x, y, line->color);
		eps += dx;
		if ((eps << 1) >= dy)
		{
			eps -= dy;
			x++;
		}
		y++;
	}
}

void	octant3(t_map_setting *set, t_line *line)
{
	int	dx;
	int	dy;
	int	y;
	int	eps;
	int	x;

	x = line->start->x;
	y = line->start->y;
	dx = abs(line->end->x - line->start->x);
	dy = abs(line->end->y - line->start->y);
	eps = 0;
	while (x <= line->end->x)
	{
		putpixel_improved(set, x, y, line->color);
		eps += dy;
		if ((eps << 1) >= dx)
		{
			eps -= dx;
			y--;
		}
		x++;
	}
}

void	octant4(t_map_setting *set, t_line *line)
{
	int	dx;
	int	dy;
	int	y;
	int	eps;
	int	x;

	x = line->start->x;
	y = line->start->y;
	dx = abs(line->end->x - line->start->x);
	dy = abs(line->end->y - line->start->y);
	eps = 0;
	while (y >= line->end->y)
	{
		putpixel_improved(set, x, y, line->color);
		eps += dx;
		if ((eps << 1) >= dy)
		{
			eps -= dy;
			x++;
		}
		y--;
	}
}

void	octant5(t_map_setting *set, t_line *line)
{
	int	dx;
	int	dy;
	int	y;
	int	eps;
	int	x;

	x = line->start->x;
	y = line->start->y;
	dx = abs(line->end->x - line->start->x);
	dy = abs(line->end->y - line->start->y);
	eps = 0;
	while (y <= line->end->y)
	{
		putpixel_improved(set, x, y, line->color);
		eps += dx;
		if ((eps << 1) >= dy)
		{
			eps -= dy;
			x--;
		}
		y++;
	}
}
