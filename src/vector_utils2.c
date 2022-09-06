/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:57:51 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/06 14:20:47 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	op_mult_v(const t_vector c1, const t_vector c2)
{
	t_vector	res;

	res.x = c1.x * c2.x;
	res.y = c1.y * c2.y;
	res.z = c1.z * c2.z;
	return (res);
}

double	get_norm2(t_vector c1)
{
	return (c1.x * c1.x + c1.y * c1.y \
			+ c1.z * c1.z);
}

t_vector	op_mult_c(double a, const t_color c1)
{
	t_vector	res;

	res.x = c1.r * a;
	res.y = c1.g * a;
	res.z = c1.b * a;
	return (res);
}

void	normalize(t_vector *c1)
{
	double	norm;

	norm = sqrt(get_norm2(*c1));
	c1->x /= norm;
	c1->y /= norm;
	c1->z /= norm;
}

t_vector	albedo(t_color col)
{
	t_vector	res;

	res.x = col.r / 255.0;
	res.y = col.g / 255.0; 
	res.z = col.b / 255.0;
	return (res);
}
