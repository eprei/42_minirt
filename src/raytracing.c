/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:25:31 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/19 13:50:35 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	update_ret(int *res, t_ret_ray *ret, t_obj current, t_ret_ray loc_ret)
{
	*res = 1;
	if (loc_ret.t < ret->t)
	{
		ret->p = loc_ret.p;
		ret->n = loc_ret.n;
		ret->t = loc_ret.t;
		ret->col = current.color;
	}
}

void	calcule_canvas(t_trace *s_t1, t_scene scene)
{
	t_vector	new_x;
	t_vector	new_y;
	t_vector	new_z;
	t_vector	temp1;
	t_vector	temp2;

	s_t1->s_r1.d.x = s_t1->j - scene.w / 2;
	s_t1->s_r1.d.y = s_t1->i - scene.h / 2;
	s_t1->s_r1.d.z = scene.w / (2 * tan(scene.cam.fov / 2));
	new_x = op_mult(s_t1->s_r1.d.x, scene.cam.right);
	new_y = op_mult(s_t1->s_r1.d.y, scene.cam.up);
	new_z = op_mult(s_t1->s_r1.d.z, scene.cam.orient);
	temp1 = op_plus(new_x, new_y);
	temp2 = op_plus(temp1, new_z);
	s_t1->s_r1.d = temp2;
	normalize(&s_t1->s_r1.d);
}

void	add_ambience_light(t_trace *s_t1, t_ret_ray ret, t_scene scene)
{
	float	k;

	k = (float) 100 / (float) 255 / (float) 100;
	s_t1->intensite_pixel.x += (ret.col.r * scene.l_amb.color.r \
	* scene.l_amb.intensity * k);
	s_t1->intensite_pixel.y += (ret.col.g * scene.l_amb.color.g \
	* scene.l_amb.intensity * k);
	s_t1->intensite_pixel.z += (ret.col.b * scene.l_amb.color.b \
	* scene.l_amb.intensity * k);
}

void	calcul_shadow(t_trace *s_t1, t_ret_ray *ret, t_scene *scene)
{
	t_ret_ray	ret_shadow;
	int			is_shadow;
	double		d_light_2;

	s_t1->s_rli.o = op_plus(ret->p, op_mult(0.01, ret->n));
	s_t1->tmp = op_minus(scene->p_light.pos, ret->p);
	normalize(&s_t1->tmp);
	s_t1->s_rli.d = s_t1->tmp;
	d_light_2 = get_norm2(op_minus(scene->p_light.pos, ret->p));
	is_shadow = inter_obj(s_t1->s_rli, scene, &ret_shadow);
	if (is_shadow && (ret_shadow.t * ret_shadow.t < d_light_2))
			s_t1->intensite_pixel = init_vector(0, 0, 0);
	else
		s_t1->intensite_pixel = op_mult((scene->p_light.intensity \
		* max_v(op_dot(s_t1->tmp, ret->n)) / d_light_2), \
		albedo(ret->col));
	add_ambience_light(s_t1, *ret, *scene);
}

int	raytracing(t_scene *scene)
{
	t_trace		s_t1;
	t_ret_ray	ret;

	s_t1.i = 0;
	s_t1.s_r1.o = scene->cam.pos;
	s_t1.s_rli.o = init_vector(0, 0, 0);
	while (s_t1.i < scene->h)
	{
		s_t1.j = 0;
		while (s_t1.j < scene->w)
		{
			s_t1.intensite_pixel = init_vector(0, 0, 0);
			calcule_canvas(&s_t1, *scene);
			if (inter_obj(s_t1.s_r1, scene, &ret))
				calcul_shadow(&s_t1, &ret, scene);
			mlx_pixel_put(scene->mlx_ptr, scene->win_ptr, s_t1.j, \
			scene->h - s_t1.i - 1, create_rgb(min_max(s_t1.intensite_pixel.x), \
			min_max(s_t1.intensite_pixel.y), \
			min_max(s_t1.intensite_pixel.z)));
			s_t1.j++;
		}
		s_t1.i++;
	}
	return (0);
}
