/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:25:31 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/13 10:20:33 by Emiliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>

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
			if (current->type == SPHERE)
			{
				if (inter_sphere(s_r1, *current, &loc_ret))
				{
					res = 1;
					if (loc_ret.t < ret->t)
					{
						ret->p = loc_ret.p;
						ret->n = loc_ret.n;
						ret->t = loc_ret.t;
						ret->col = current->color;
					}
				}
			}
			if (current->type == PLAN)
			{
				if (inter_plane(s_r1, *current, &loc_ret))
				{
					res = 1;
					if (loc_ret.t < ret->t)
					{
						ret->p = loc_ret.p;
						ret->n = loc_ret.n;
						ret->t = loc_ret.t;
						ret->col = current->color;
					}
				}
			}
			current = current->next;
		}
	}
	return (res);
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

int	raytracing(t_scene *scene)
{
	t_trace		s_t1;
	double		int_pix;
	t_ret_ray	ret;
	t_ret_ray	ret_shadow;
	int			is_shadow;

	s_t1.i = 0;
	s_t1.j = 0;
	s_t1.s_r1.o = scene->cam.pos;
	s_t1.s_rli.o = init_vector(0, 0, 0);
	while (s_t1.i < scene->h)
	{
		while (s_t1.j < scene->w)
		{
			int_pix = 0.0;
			s_t1.intensite_pixel = init_vector(0, 0, 0);
			calcule_canvas(&s_t1, *scene);
			if (inter_obj(s_t1.s_r1, scene, &ret))
			{
				s_t1.s_rli.o = op_plus(ret.p, op_mult(0.01, ret.n)); // pour ombre
				s_t1.tmp = op_minus(scene->p_light.pos, ret.p);
				normalize(&s_t1.tmp);
				s_t1.s_rli.d = s_t1.tmp;
				double d_light_2 = get_norm2(op_minus(scene->p_light.pos, ret.p));
				is_shadow = inter_obj(s_t1.s_rli, scene, &ret_shadow);
				if (is_shadow && (ret_shadow.t * ret_shadow.t < d_light_2))
						s_t1.intensite_pixel = init_vector(0, 0, 0);
				else
				{
					int_pix = scene->p_light.intensity * \
					max_v(op_dot(s_t1.tmp, ret.n)) / \
					get_norm2(op_minus(scene->p_light.pos, ret.p)); //cette ligne remplacable par d_light_2 !!
					s_t1.intensite_pixel = op_mult(int_pix, albedo(ret.col));
/*					if (int_pix > 0.1)// && s_t1.i > 77)
						printf("%d - %d - intens %f\n", s_t1.i, s_t1.j, int_pix);
*/				}
				add_ambience_light(&s_t1, ret, *scene);
			}
		mlx_pixel_put(scene->mlx_ptr, scene->win_ptr, s_t1.j, scene->h - s_t1.i - 1, create_rgb(min_max(s_t1.intensite_pixel.x), min_max(s_t1.intensite_pixel.y), min_max(s_t1.intensite_pixel.z)));
			s_t1.j++;
		}
		s_t1.j = 0;
		s_t1.i++;
	}
	return (0);
}
