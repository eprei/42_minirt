/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:25:31 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/08 15:02:02 by olmartin         ###   ########.fr       */
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
			current = current->next;
		}
	}
	return (res);
}

int	raytracing(t_scene *scene, t_obj *obj1)
{
	(void)obj1;
	t_trace	s_t1;
	double int_pix;
	t_ret_ray	ret;

	s_t1.i = 0;
	s_t1.j = 0;
	s_t1.s_r1.o = init_vector(0, 0, 0);
	while (s_t1.i < scene->h)
	{
		while (s_t1.j < scene->w)
		{
			int_pix = 0.0;
			s_t1.intensite_pixel = init_vector(0, 0, 0);
			s_t1.s_r1.d.x = s_t1.j - scene->w /2;
		    s_t1.s_r1.d.y = s_t1.i - scene->h / 2;
		   	s_t1.s_r1.d.z = - scene->w / (2 * tan(scene->cam.fov/2));
			normalize(&s_t1.s_r1.d);
//			if (inter_sphere(s_t1.s_r1, *obj1, &ret))
			if (inter_obj(s_t1.s_r1, scene, &ret))			
			{
				s_t1.tmp = op_minus(scene->p_light.pos, ret.p);
				normalize(&s_t1.tmp);
				int_pix = scene->p_light.intensity * \
				max_v(op_dot(s_t1.tmp, ret.n)) / \
				get_norm2(op_minus(scene->p_light.pos, ret.p)); 
				s_t1.intensite_pixel = op_mult(int_pix, albedo(obj1->color)); 
/*				s_t1.intensite_pixel = op_mult_c(scene->p_light.intensity * \
				max_v(op_dot(s_t1.tmp, s_t1.n)) / \
				get_norm2(op_minus(scene->p_light.pos, s_t1.p)), obj1->color); 
			if (int_pix > 0.1)// && s_t1.i > 77)
				printf("%d - %d - intens %f\n", s_t1.i, s_t1.j, int_pix);
*/			}
		mlx_pixel_put(scene->mlx_ptr, scene->win_ptr, s_t1.j, scene->h - s_t1.i - 1, create_rgb(min_max(s_t1.intensite_pixel.x), min_max(s_t1.intensite_pixel.y), min_max(s_t1.intensite_pixel.z)));
			s_t1.j++;
		}
		s_t1.j = 0;
		s_t1.i++;
	}
	return (0);
}	
