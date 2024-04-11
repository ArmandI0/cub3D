/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:52:01 by nledent           #+#    #+#             */
/*   Updated: 2024/04/10 19:19:23 by nledent          ###   ########.fr       */
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

static void	draw_ver_line(int pos_x_vertline, int	drawStart, int	drawEnd, t_params *game, t_window_settings *set, int side)
{
	int	color;
	int	color_wall;
	int	color_ceiling;
	int	color_floor;
	int	y;

	y = 0;
	color_wall = convert_color(rgb_to_int(200,50,0));
	color_floor = convert_color(game->floor_color);
	color_ceiling = convert_color(game->ceiling_color);
	while (y < HEIGHT)
	{
		if (y < drawStart)
			color = color_ceiling;
		else if (y > drawEnd)
			color = color_floor;
		else
		{
			color = color_wall;
			if (side == 1)
	  			color = color / 2;
		}
		mlx_put_pixel(set->img, pos_x_vertline, y, color);
		//ft_printf_fd(2, "pixel x : %d y : %d, color RGB %d,%d,%d\n", pos_x_vertline, y, color>>16, color >> 8 & 255, color & 255);
		y++;
	}
}

t_bool  raycasting(t_params *game, t_window_settings *set)
{
	double posX = 20.5, posY = 11.5;
	double dirX = 0, dirY = -1;
	double planeX = 0.66, planeY = 0;

	double time = 0;
  	double oldTime = 0;
	int w = WIDTH;
	int h = HEIGHT;
	set_map_w_and_h(game);
	
		for (int x = 0; x < w; x++)
		{
			double cameraX = 2 * x / (double)(w) - 1;
			double rayDirX = dirX + planeX * cameraX;
     		double rayDirY = dirY + planeY * cameraX;
			int mapX = (int)(posX);
			int mapY = (int)(posY);

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
			double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?
			//calculate step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}
			//perform DDA
			while (hit == 0)
			{
				//jump to next map square, either in x-direction, or in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				/* if (mapX >= game->map->w_map)
					mapX = game->map->w_map - 1;
				if (mapY >= game->map->h_map)
					mapY = game->map->h_map - 1; */
				//Check if ray has hit a wall
				if (game->map->map2d[mapY][mapX] == '1')
					hit = 1;
				//ft_printf_fd(2, "passage n°%d, mapY = %d, mapX = %d, hit : %d\n", x, mapY, mapX, hit);
			} 
			//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
				if(side == 0) 
					perpWallDist = (sideDistX - deltaDistX);
				else
					perpWallDist = (sideDistY - deltaDistY);
				//Calculate height of line to draw on screen
			int lineHeight = (int)(h / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + h / 2 - 150;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if(drawEnd >= h)drawEnd = h - 1;

      		//draw the pixels of the stripe as a vertical line
      		draw_ver_line(x, drawStart, drawEnd, game, set, side);
		}
		mlx_image_to_window(set->window, set->img, 0, 0);
		(void)time;
		(void)oldTime;
		return (TRUE);
}

