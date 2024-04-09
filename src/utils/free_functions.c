/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/07 18:51:19 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_el_list(t_list *element)
{
	if (element != NULL)
	{
		if (element->content != NULL)
			free(element->content);
		free(element);
		element = NULL;
	}
}

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
	free_split(game->map);
	free(game);
}
