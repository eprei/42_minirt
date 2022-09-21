/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:09:24 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/21 09:40:01 by Emiliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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

void	calcul_cyl_centers(t_obj *c)
{
	normalize(&c->orientation);
	c->cyl_top_center = op_mult(c->height * 0.5, c->orientation);
	c->cyl_top_center = op_plus(c->cyl_top_center, c->pos);
	c->cyl_bottom_center = op_mult(c->height * -0.5, c->orientation);
	c->cyl_bottom_center = op_plus(c->cyl_bottom_center, c->pos);
	c->cylinder_cap->pos = c->cyl_top_center;
	c->cylinder_cap->orientation = c->orientation;
}
