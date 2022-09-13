/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:09:24 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/13 17:07:24 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//int	inter_sphere(const t_ray d, const t_obj  s, t_vector *p, t_vector *n)
int	inter_sphere(const t_ray d, const t_obj s, t_ret_ray *ret)
{
	t_inter_sp	s_inter;

	s_inter.a = 1;
	s_inter.b = 2 * op_dot(d.d, op_minus(d.o, s.pos));
	s_inter.c = get_norm2(op_minus(d.o, s.pos)) - s.diameter * s.diameter;
	s_inter.delta = s_inter.b * s_inter.b - 4 * s_inter.a * s_inter.c;
	if (s_inter.delta < 0)
		return (0);
	s_inter.t2 = (-s_inter.b + sqrt(s_inter.delta)) / (2 * s_inter.a);
	if (s_inter.t2 < 0)
		return (0);
	s_inter.t1 = (-s_inter.b - sqrt(s_inter.delta)) / (2 * s_inter.a);
	if (s_inter.t1 > 0)
		ret->t = s_inter.t1;
	else
		ret->t = s_inter.t2;
	ret->p = op_plus(d.o, op_mult(ret->t, d.d));
	ret->n = op_minus(ret->p, s.pos);
	normalize(&ret->n);
	return (1);
}

int	inter_plane(const t_ray d, const t_obj plane, t_ret_ray *ret)
{
	double		a;
	double		t;
	t_vector	oc;
	t_vector	plane_ori_norm;
	t_vector	plane_pos_norm;

	plane_pos_norm = plane.pos;
	normalize(&plane_pos_norm);
	plane_ori_norm = plane.orientation;
	normalize(&plane_ori_norm);
	a = op_dot(d.d, plane_ori_norm);
	if (a != 0.0)
	{
		oc = op_minus(plane.pos, d.o);
		t = op_dot(oc, plane_ori_norm) / a;
		if (t > 0.0)
		{
			ret->t = t;
			ret->p = op_plus(d.o, op_mult(ret->t, d.d));
			ret->n = plane.orientation;
			return (1);
		}
	}
	return (0);
}

int	inter_cylinder(const t_ray ray, const t_obj c, t_ret_ray *ret)
{
	t_inter_sp	s_inter;

	t_vector	u;
	t_vector	v;

	u = cross(ray.d, c.orientation);
	v = cross(op_minus(ray.o, c.pos), c.orientation);
	s_inter.a = op_dot(u, u);
	s_inter.b = 2 * op_dot(u, v);
	s_inter.c = op_dot(v, v) - (c.diameter * c.diameter);
	s_inter.delta = s_inter.b * s_inter.b - 4 * s_inter.a * s_inter.c;
	if (s_inter.delta < 0)
		return (0);
	s_inter.t2 = (-s_inter.b + sqrt(s_inter.delta)) / (2 * s_inter.a);
	if (s_inter.t2 < 0)
		return (0);
	s_inter.t1 = (-s_inter.b - sqrt(s_inter.delta)) / (2 * s_inter.a);
	if (s_inter.t1 > 0)
		ret->t = s_inter.t1;
	else
		ret->t = s_inter.t2;
	ret->p = op_plus(ray.o, op_mult(ret->t, ray.d));

	t_vector	a = ret->p;
	t_vector	be = c.orientation;
	t_vector	ce = cross(a, be);
	t_vector	n = cross(ce, be);

	ret->n = n;

	// ret->n = op_minus(ret->p, c.pos);
	normalize(&ret->n);
	return (1);
}
