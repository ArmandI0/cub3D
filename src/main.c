/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/08 16:13:08 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_error(t_window_settings *set)
{
	free(set);
	exit(EXIT_FAILURE);
}

void	test_minimap(t_window_settings *set)
{
	t_map *map;

	map = init_argument();
	display_minimap(set, map);
}

int32_t	main(int argc, char *argv[])
{
	t_window_settings	*set;

	(void) argv;
	set = ft_calloc(1, sizeof(t_window_settings));
	if (argc != 1)
		return (0);
	set->window = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!set->window)
	{
		ft_error(set);
		return (EXIT_FAILURE);
	}
	test_minimap(set);
	mlx_loop(set->window);
	mlx_key_hook(set->window, &my_keyhook, set);
	mlx_resize_hook(set->window, &resize_mlx, set);
	mlx_close_hook(set->window, &close_fct, set);
	mlx_terminate(set->window);
	free(set);
	return (EXIT_SUCCESS);
}

