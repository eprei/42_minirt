/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:09:24 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/19 11:33:18 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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
			return (TRUE);
		}
	}
	return (FALSE);
}

int	verif_inside_cylindre_body(const t_obj c, t_ret_ray *ret)
{
	float		hit_point_to_cyl_center;
	float		cyl_center_to_high_of_hit_point;
	t_vector	aux;

	hit_point_to_cyl_center = distance_between_two_vectors(c.pos, ret->p);
	cyl_center_to_high_of_hit_point = hit_point_to_cyl_center * \
	hit_point_to_cyl_center - c.diameter * c.diameter;
	if (cyl_center_to_high_of_hit_point <= (c.height / 2) * (c.height / 2))
	{
		aux = op_minus(c.pos, ret->p);
		ret->n = cross(aux, c.orientation);
		ret->n = cross(ret->n, c.orientation);
		normalize(&ret->n);
		return (TRUE);
	}
	else
		return (FALSE);
}

int	verif_inside_cylindre_cap(t_ret_ray ret_local, t_obj c, t_obj cylinder_cap)
{
	float	distance_to_cap_center;

	distance_to_cap_center = distance_between_two_vectors(ret_local.p, \
	cylinder_cap.pos);
	if (distance_to_cap_center <= c.diameter)
		return (TRUE);
	else
		return (FALSE);
}

void	calcule_caps(t_vector *cyl_top_center, t_vector *cyl_bottom_center, \
t_obj *cylinder_cap, t_obj c)
{
	normalize(&c.orientation);
	*cyl_top_center = op_mult(c.height * 0.5, c.orientation);
	*cyl_top_center = op_plus(*cyl_top_center, c.pos);
	*cyl_bottom_center = op_mult(c.height * -0.5, c.orientation);
	*cyl_bottom_center = op_plus(*cyl_bottom_center, c.pos);
	cylinder_cap->pos = *cyl_top_center;
	cylinder_cap->orientation = c.orientation;
}
