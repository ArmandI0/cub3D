/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/02 14:03:24 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_lines_list(t_list *head)
{
	t_list	*next;

	if (head != NULL)
	{
		next = head;
		while (next != NULL)
		{
			next = head->next;
			if (head->content != NULL)
				free (head->content);
			free (head);
			head = next;
		}
	}
}

void	free_path_textures(t_params *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->path_texture[i] != NULL)
			free(game->path_texture[i]);
		i++;
	}
}

void	free_game(t_params *game)
{
	free_lines_list(game->head_list_lines);
	free_path_textures(game);
	free(game);
}
