/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nledent <nledent@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:16:32 by nledent           #+#    #+#             */
/*   Updated: 2024/04/02 16:44:56 by nledent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_error(t_errors error)
{
	ft_printf_fd(2, "Error\n");
	if (error == ER_NB_ARGS)
		ft_printf_fd(2, "The game just need one argument : a *.cub map file");
	else if (error == ER_MAP_TYPE)
		ft_printf_fd(2, "The map file is not *.cub");
	else if (error == ER_FILE_N_FOUND)
		ft_printf_fd(2, "Invalid map path : file not found / bad access");
	else if (error == ER_INVALID_MAP_DOUBLE)
		ft_printf_fd(2, "Invalid map : same identifier several times");
	else if (error == ER_INVALID_MAP_NULL_PATH)
		ft_printf_fd(2, "Invalid map : no path for at least one identifier");
	else if (error == ER_EXTRACTION_MAP)
		ft_printf_fd(2, "Problem with map extraction");
	else if (error == ER_FILE_TEXTURE_N_FOUND)
		ft_printf_fd(2, "Invalid texture path : file not found / bad access");
	else if (error == ER_INVALID_MAP_FILE)
		ft_printf_fd(2, "Invalid map : bad syntax");
	ft_printf_fd(2, "\n");
}
