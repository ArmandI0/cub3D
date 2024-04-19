/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/15 14:13:09 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

mlx_image_t	*set_img(t_window_settings *set)
{
	mlx_image_t *img;

	img = mlx_new_image(set->window, set->window->width, set->window->height);
	if (!img || (mlx_image_to_window(set->window, img, 0, 0) < 0))
		ft_error(set);
	else
	{
		mlx_set_instance_depth(img->instances, 0);
		return (img);
	}
	return (NULL);
}

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

static t_params	*init_game(const char **argv)
{
	t_params			*game;
	t_window_settings	*win;

	game = ft_calloc(1, sizeof(t_params));
	if (game == NULL)
		exit(1);
	map_file_parsing(game, argv[1]);
	win = ft_calloc(1, sizeof(t_window_settings));
	if (win == NULL)
		exit_fct(game);
	game->win = win;
	win->window = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!win->window)
		exit_fct(game);
	win->img = set_img(win);
	game->player = init_new_players('N', 20.5, 11.5);
	return (game);
}

int	main(int argc, const char **argv)
{
	t_params			*game;

	check_args(argc, argv);
	game = init_game(argv);
	raycasting(game, game->win, game->player);
	raycasting_1(game, game->win, game->player);
	display_minimap(game);
	init_command(game);
	mlx_loop(game->win->window);
	mlx_resize_hook(game->win->window, &resize_mlx, game->win);
	mlx_close_hook(game->win->window, &close_fct, game->win);
	free_game(game);
	return (0);
}

