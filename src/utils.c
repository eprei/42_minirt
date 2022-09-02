/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:03:58 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/02 16:54:18 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	get_norm2(t_vector c1)
{
	return (c1.x * c1.x + c1.y * c1.y \
			+ c1.z * c1.z);
}

void	normalize(t_vector *c1)
{
	double	norm;

	norm = sqrt(get_norm2(*c1));
	c1->x /= norm;
	c1->y /= norm;
	c1->z /= norm;
}

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
