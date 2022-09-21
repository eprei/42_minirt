/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:09:24 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/21 09:46:22 by Emiliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	update_ret_cyl(t_ret_ray *ret, int *intersect_status, \
t_ret_ray ret_local)
{
	*ret = ret_local;
	*intersect_status = TRUE;
}

int	inter_caps(t_ray ray, t_ret_ray *ret_local, t_ret_ray *ret, t_obj *c)
{
	int	intersect_status;

	intersect_status = FALSE;
	if (inter_plane(ray, *c->cylinder_cap, ret_local) && \
	verif_inside_cylindre_cap(*ret_local, *c, *c->cylinder_cap))
		update_ret_cyl(ret, &intersect_status,*ret_local);
	c->cylinder_cap->pos = c->cyl_bottom_center;
	if (inter_plane(ray, *c->cylinder_cap, ret_local) && \
	verif_inside_cylindre_cap(*ret_local, *c, *c->cylinder_cap) \
	&& ret_local->t < ret->t)
		update_ret_cyl(ret, &intersect_status, *ret_local);
	return (intersect_status);
}

void	update_t_value(t_inter_sp s_inter, t_ret_ray *ret_local)
{
	if (s_inter.t1 > 0)
		ret_local->t = s_inter.t1;
	else
		ret_local->t = s_inter.t2;
}

int	inter_cylinder(t_ray ray, t_obj c, t_ret_ray *ret)
{
	t_inter_sp	s_inter;
	t_ret_ray	ret_local;
	int			intersect_status;
	t_obj		cylinder_cap;

	c.cylinder_cap = &cylinder_cap;
	ret->t = 1E9;
	calcul_cyl_centers(&c);
	intersect_status = inter_caps(ray, &ret_local, ret, &c);
	calcule_a_b_c_delta(ray, &s_inter, c);
	if (s_inter.delta < 0)
		return (intersect_status);
	s_inter.t2 = (-s_inter.b + sqrt(s_inter.delta)) / (2 * s_inter.a);
	if (s_inter.t2 < 0)
		return (intersect_status);
	s_inter.t1 = (-s_inter.b - sqrt(s_inter.delta)) / (2 * s_inter.a);
	update_t_value(s_inter, &ret_local);
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
