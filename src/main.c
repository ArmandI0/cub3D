/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/09 15:40:29 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	print_map(t_list *head)
{
	t_list	*next;

	ft_printf_fd(1, "PRINT MAP :\n");
	if (head != NULL)
	{
		next = head;
		while (next != NULL)
		{
			next = head->next;
			ft_printf_fd(1, "%s", head->content);
			head = next;
		}
	}
}

void	print_map_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf_fd(1, "%s\n", map[i]);
		i++;
	}
}

void	ft_error(t_window_settings *set)
{
	free(set);
	exit(EXIT_FAILURE);
}

void	test_minimap(t_window_settings *set, t_params *param)
{
	display_minimap(set, param->map);
}

int	main(int argc, const char **argv)
{
	t_params			*game;
	t_window_settings	*set;

	check_args(argc, argv);
	game = ft_calloc(1, sizeof(t_params));
	if (game == NULL)
	{
		perror("Error\n");
		return (1);
	}
	map_file_parsing(game, argv[1]);
	set = ft_calloc(1, sizeof(t_window_settings));
	if (set == NULL)
		return (0);
	set->window = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!set->window)
	{
		ft_error(set);
		return (EXIT_FAILURE);
	}
	// print_map(game->head_list_lines);
	// ft_printf_fd(1, "-----MAP TAB----\n");
	// print_map_tab(game->map->map2d);
	test_minimap(set, game);
	mlx_loop(set->window);
	mlx_key_hook(set->window, &my_keyhook, set);
	mlx_resize_hook(set->window, &resize_mlx, set);
	mlx_close_hook(set->window, &close_fct, set);
	mlx_terminate(set->window);
	free_game(game);
	free(set);
	return (0);
}

