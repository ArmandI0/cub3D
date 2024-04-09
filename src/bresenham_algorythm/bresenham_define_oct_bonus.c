/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_define_oct_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:09:53 by aranger           #+#    #+#             */
/*   Updated: 2023/12/26 12:13:54 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	positive_oct(t_map_setting *set, t_line *line, float m);
static void	negative_oct(t_map_setting *set, t_line *line, float m);

void	define_oct(t_map_setting *set, t_line *line)
{
	float	dx;
	float	dy;
	float	m;

	dx = line->end->x - line->start->x;
	dy = line->end->y - line->start->y;
	m = dy / dx;
	if (m >= 0)
		positive_oct(set, line, m);
	else
		negative_oct(set, line, m);
}

static void	positive_oct(t_map_setting *set, t_line *line, float m)
{
	if (m >= 0 && m <= 1)
	{
		if (line->start->x < line->end->x)
			octant1(set, line);
		else
			octant7(set, line);
	}
	else
	{
		if (line->start->y < line->end->y)
			octant2(set, line);
		else
			octant8(set, line);
	}
}

static void	negative_oct(t_map_setting *set, t_line *line, float m)
{
	if (m < 0 && m >= -1)
	{
		if (line->start->x < line->end->x)
			octant3(set, line);
		else
			octant6(set, line);
	}
	else if (m < -1)
	{
		if (line->end->y < line->start->y)
			octant4(set, line);
		else
			octant5(set, line);
	}
}
