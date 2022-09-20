/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:03:58 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/20 11:56:49 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	create_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

double	max_v(double a)
{
	if (a < 0)
		return (0);
	return (a);
}

double	min_max(double a)
{
	if (a > 255)
		return (255);
	if (a < 0)
		return (0);
	return (a);
}

void	tab_free(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
}

int	tablen(char **t)
{
	int	i;

	i = 0;
	while (t && t[i])
		i++;
	return (i);
}
