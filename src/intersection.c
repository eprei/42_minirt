/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:09:24 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/05 10:39:42 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//int	inter_sphere(const t_ray d, const t_obj  s, t_vector *p, t_vector *n)
int	inter_sphere(const t_ray d, const t_obj  s, t_vector *p, t_vector *n)
	
{
	t_inter_sp	s_inter;

	inter.a = 1;
	inter.b = 2 * op_dot(d.d, op_minus(d.o, s.orig));
	inter.c = get_norm2(op_minus(d.o, s.orig)) - s.radius * s.radius;
	inter.delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	inter.t2 = (-b + sqrt(delta)) / (2 * a);
	if (inter.t2 < 0)
		return (0);
	inter.t1 = (-b - sqrt(delta)) / (2 * a);
	if (inter.t1 > 0)
		inter.t = inter.t1;
	else
		inter.t = inter.t2;
	*p = op_plus(d.o, op_mult(t, d.d));
	*n = op_minus(*p, s.orig);
	normalize(n);
	return (1);
}
