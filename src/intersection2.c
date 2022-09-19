/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:09:24 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/19 17:06:05 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	inter_caps(t_ray ray, t_obj c, t_ret_ray *ret_local, t_ret_ray *ret)
{
	t_vector	cyl_top_center;
	t_vector	cyl_bottom_center;
	t_obj		cylinder_cap;
	int			intersect_status;

	ret->t = 1E9;
	intersect_status = FALSE;
	calcule_caps(&cyl_top_center, &cyl_bottom_center, &cylinder_cap, c);
	if (inter_plane(ray, cylinder_cap, ret_local) && \
	verif_inside_cylindre_cap(*ret_local, c, cylinder_cap))
	{
		*ret = *ret_local;
		intersect_status = TRUE;
	}
	cylinder_cap.pos = cyl_bottom_center;
	if (inter_plane(ray, cylinder_cap, ret_local) && \
	verif_inside_cylindre_cap(*ret_local, c, cylinder_cap) \
	&& ret_local->t < ret->t)
	{
		*ret = *ret_local;
		intersect_status = TRUE;
	}
	return (intersect_status);
}

void	calcule_a_b_c_delta(t_ray ray, t_inter_sp *s_inter, t_obj c)
{
	t_vector	u;
	t_vector	v;

	u = cross(ray.d, c.orientation);
	v = cross(op_minus(ray.o, c.pos), c.orientation);
	s_inter->a = op_dot(u, u);
	s_inter->b = 2 * op_dot(u, v);
	s_inter->c = op_dot(v, v) - (c.diameter * c.diameter);
	s_inter->delta = s_inter->b * s_inter->b - 4 * s_inter->a * s_inter->c;
}

int	inter_cylinder(t_ray ray, t_obj c, t_ret_ray *ret)
{
	t_inter_sp	s_inter;
	t_ret_ray	ret_local;
	int			intersect_status;

	intersect_status = inter_caps(ray, c, &ret_local, ret);
	calcule_a_b_c_delta(ray, &s_inter, c);
	if (s_inter.delta < 0)
		return (intersect_status);
	s_inter.t2 = (-s_inter.b + sqrt(s_inter.delta)) / (2 * s_inter.a);
	if (s_inter.t2 < 0)
		return (intersect_status);
	s_inter.t1 = (-s_inter.b - sqrt(s_inter.delta)) / (2 * s_inter.a);
	if (s_inter.t1 > 0)
		ret_local.t = s_inter.t1;
	else
		ret_local.t = s_inter.t2;
	ret_local.p = op_plus(ray.o, op_mult(ret_local.t, ray.d));
	if (verif_inside_cylindre_body(ray, c, &ret_local) == FALSE)
		return (intersect_status);
	if (ret_local.t < ret->t)
		*ret = ret_local;
	return (TRUE);
}

int	inter_obj(t_ray s_r1, t_scene *scene, t_ret_ray *ret)
{
	t_obj		*current;
	int			res;
	t_ret_ray	loc_ret;

	res = 0;
	ret->t = 1E9;
	if (scene != NULL && scene->obj_0 != NULL)
	{
		current = scene->obj_0;
		while (current != NULL)
		{
			if (current->type == SPHERE && \
			inter_sphere(s_r1, *current, &loc_ret))
				update_ret(&res, ret, *current, loc_ret);
			if (current->type == PLAN && \
			inter_plane(s_r1, *current, &loc_ret))
				update_ret(&res, ret, *current, loc_ret);
			if (current->type == CYLINDER && \
			inter_cylinder(s_r1, *current, &loc_ret))
				update_ret(&res, ret, *current, loc_ret);
			current = current->next;
		}
	}
	return (res);
}
