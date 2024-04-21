/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:56:50 by nledent           #+#    #+#             */
/*   Updated: 2024/04/21 17:26:23 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	init_times_displays(t_params *game)
{
	game->times.spagh_eaten = 0;
	game->times.start_game = time_to_ms();
	game->times.one_min = 0;
	game->times.dead = FALSE;
	game->times.time_given = game->times.start_game + 1000 * 60 * 2;
}

static void	display_sphagetti_eaten(mlx_t *mlx, u_int64_t time)
{
	char *str;

	if (time > time_to_ms())
	{
		str = ft_strdup("+1 SPAGHETTI EATEN");
		mlx_put_string(mlx, str, WIDTH / 3, 10);
		free (str);
	}
}

static void	display_time_given(mlx_t *mlx, u_int64_t time, t_params *game)
{
	char 		*str;
	u_int64_t	remaining_time;

	remaining_time = time_to_ms() - time;
	if (remaining_time > 0)
	{
		str = ft_itoa(time );
		mlx_put_string(mlx, str, WIDTH / 3, 10);
		free (str);
	}
	else
		game->times.dead = TRUE;
}

void	display_infos(t_params *game)
{
	display_sphagetti_eaten(game->win->window, game->times.spagh_eaten);
	if (game->times.dead == FALSE)
		display_time_given(game->win->window, game->times.time_given, game);
	else
	{
		display_dead(game->win->window);
		sleep(10);
		exit_fct(game);
	}
}
