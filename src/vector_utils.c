/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:18:14 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/02 15:53:20 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector	op_plus(const t_vector c1, const t_vector c2)
{
	t_vector	res;

	res.x = c1.x + c2.x;
	res.y = c1.y + c2.y;
	res.z = c1.z + c2.z;
	return (res);
}	

t_vector	op_minus(const t_vector c1, const t_vector c2)
{
	t_vector	res;

	res.x = c1.x - c2.x;
	res.y = c1.y - c2.y;
	res.z = c1.z - c2.z;
	return (res);
}	

t_vector	op_mult(double a, const t_vector c1)
{
	t_vector	res;

	res.x = c1.x * a;
	res.y = c1.y * a;
	res.z = c1.z * a;
	return (res);
}	

t_vector	op_div(const t_vector c1, double a)
{
	t_vector	res;

	res.x = c1.x / a;
	res.y = c1.y / a;
	res.z = c1.z / a;
	return (res);
}	

double	op_dot(const t_vector c1, const t_vector c2)
{
	return (c1.x * c2.x + c1.y * c2.y \
			+ c1.z * c2.z);
}	
