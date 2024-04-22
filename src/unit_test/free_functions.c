/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/15 12:08:15 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
	if (game->win != NULL)
	{
		mlx_terminate(game->win->window);
		free(game->win);
	}
	free_lines_list(game->head_list_lines);
	free_path_textures(game);
	if (game->map != NULL)
	{
		free_split(game->map->map2d);
		free(game->map);
	}
	if (game->player != NULL)
		free(game->player);
	free(game);
}