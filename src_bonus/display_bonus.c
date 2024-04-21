/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:12 by aranger           #+#    #+#             */
/*   Updated: 2024/04/21 17:05:01 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

static void	display_welcome(t_params *game)
{

}

void	display_all(t_params *game)
{
	if (raycasting(game, game->win, game->player) == FALSE)
		exit_fct(game);
	display_minimap(game);
	display_hands(game);
	display_infos(game);
	display_welcome(game);
}
