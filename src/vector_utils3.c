/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:57:51 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/13 10:13:06 by Emiliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	cross(t_vector vect_a, t_vector vect_b)
{
	t_vector	res;

	res.x = vect_a.y * vect_b.z - vect_a.z * vect_b.y;
	res.y = vect_a.z * vect_b.x - vect_a.x * vect_b.z;
	res.z = vect_a.x * vect_b.y - vect_a.y * vect_b.x;
	return (res);
}

t_vector	init_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_color	init_vec_col(int r, int g, int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}