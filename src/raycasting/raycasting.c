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

static void	draw_ver_line(int pos_line, drawStart, drawEnd, color)
{

}

t_bool  raycasting(t_params *game, t_window_settings *set)
{
	double posX = 20.5, posY = 11.5;
	double dirX = 0, dirY = 1;
	double planeX = 0, planeY = 0.66;

	double time = 0;
  	double oldTime = 0;
	int w = set->w;
	int h = set->h;
	w = WIDTH;
	h = HEIGHT;

	while (!done())
	{
		for (int x = 0; x < w; x++)
		{
			double cameraX = 2 * x / double(w) - 1;
			double rayDirX = dirX + planeX * cameraX;
     		double rayDirY = dirY + planeY * cameraX;
			int mapX = int(posX);
			int mapY = int(posY);

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
			double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
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
				//Check if ray has hit a wall
				if (game->map->map2d[mapX][mapY] > 0)
					hit = 1;
			} 
			//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
				if(side == 0) 
					perpWallDist = (sideDistX - deltaDistX);
				else
					perpWallDist = (sideDistY - deltaDistY);
				//Calculate height of line to draw on screen
			int lineHeight = (int)(h / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + h / 2;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if(drawEnd >= h)drawEnd = h - 1;
			//choose wall color
			int color = rgb_to_int(255,0,0);

      		//give x and y sides different brightness
     		 if (side == 1)
	  			color = color / 2;

      		//draw the pixels of the stripe as a vertical line
      		draw_ver_line(x, drawStart, drawEnd, color);
		}
	}
}
