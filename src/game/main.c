/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/07 19:14:26 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_map(t_list *head)
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

static void	print_map_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf_fd(1, "%s", map[i]);
		i++;
	}
}

int	main(int argc, const char **argv)
{
	t_params	*game;

	check_args(argc, argv);
	game = ft_calloc(1, sizeof(t_params));
	if (game == NULL)
	{
		perror("Error\n");
		return (1);
	}
	map_file_parsing(game, argv[1]);
	print_map(game->head_list_lines);
	ft_printf_fd(1, "-----MAP TAB----\n");
	print_map_tab(game->map);
	free_game(game);
	return (0);
}
