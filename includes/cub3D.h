/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:40:47 by aranger           #+#    #+#             */
/*   Updated: 2024/04/08 15:40:18 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/src/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_window_settings
{
	int			l;
	int			h;
	mlx_image_t	*img;
	mlx_t		*window;
}				t_window_settings;

typedef struct s_map
{
	char	**map2d;
	int		p_y;
	int		p_x;
	int		w_map;
	int		h_map;
}				t_map;

void	my_keyhook(mlx_key_data_t keydata, void *param);
void	resize_mlx(int32_t width, int32_t height, void *param);
void	put_pixel(mlx_image_t *img, uint32_t x,
						uint32_t y, uint32_t color);
void	close_fct(void *param);
t_map *init_argument(void); // init the data structure
void	display_minimap(t_window_settings *set, t_map *minimap);
void	ft_error(t_window_settings *set);

#endif