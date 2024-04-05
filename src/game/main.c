/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/02 16:11:45 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_map(t_list *head)
{
	t_list	*next;

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
	game->map_file = argv[1];
	map_parsing(game);
	print_map(game->head_list_lines);
	free_game(game);
	return (0);
}
