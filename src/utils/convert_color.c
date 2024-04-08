/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranger <aranger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:25:59 by aranger           #+#    #+#             */
/*   Updated: 2024/04/08 16:28:26 by aranger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_index(char *index, char c)
{
	int	i;

	i = 0;
	while (index[i])
	{
		if (index[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	base_value(char *index, char c)
{
	int	i;

	i = 0;
	while (index[i])
	{
		if (index[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned long int	ft_atoi_hexa(const char *nptr)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (ft_isspace(nptr[i]) == 1 && nptr[i] != '\0')
		i++;
	if (nptr[i] == '0' && nptr[i] != '\0')
		i++;
	if (nptr[i] == 'x' && nptr[i] != '\0')
		i++;
	while (is_index("0123456789abcdef", nptr[i]) == 1)
	{
		value += base_value("0123456789abcdef", nptr[i]);
		if (is_index("0123456789abcdef", nptr[i + 1]) == 0)
			return (value);
		value *= 16;
		i++;
	}
	return (0);
}