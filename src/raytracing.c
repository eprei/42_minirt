/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:25:31 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/07 14:14:11 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
/*
int	inter_obj(t_ray s_r1, t_scene *scene, t_vector *p, t_vector *n, double *t)
{




}*/
//int	raytracing(t_scene *scene, int w, int h, t_cam cam)
int	raytracing(t_scene *scene, t_obj *obj1)
{
	(void)obj1;
	t_trace	s_t1;
	double int_pix;

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
			if (inter_sphere(s_t1.s_r1, *obj1, &s_t1.p, &s_t1.n, 0))
//			if (inter_obj(s_t1.s_r1, scene,  &s_t1.p, &s_t1.n)			
			{
				s_t1.tmp = op_minus(scene->p_light.pos, s_t1.p);
				normalize(&s_t1.tmp);
				int_pix = scene->p_light.intensity * \
				max_v(op_dot(s_t1.tmp, s_t1.n)) / \
				get_norm2(op_minus(scene->p_light.pos, s_t1.p)); 
				s_t1.intensite_pixel = op_mult(int_pix, albedo(obj1->color)); 
/*				s_t1.intensite_pixel = op_mult_c(scene->p_light.intensity * \
				max_v(op_dot(s_t1.tmp, s_t1.n)) / \
				get_norm2(op_minus(scene->p_light.pos, s_t1.p)), obj1->color); 
			if (int_pix > 0.1 && s_t1.i > 77)
				printf("%d - %d - intens %f\n", s_t1.i, s_t1.j, int_pix);
*/			}
/*			mlx_pixel_put(scene->mlx_ptr, scene->win_ptr, s_t1.j, scene->h - s_t1.i - 1, create_rgb(min_max(int_pix), min_max(int_pix), min_max(int_pix)));
*/		mlx_pixel_put(scene->mlx_ptr, scene->win_ptr, s_t1.j, scene->h - s_t1.i - 1, create_rgb(min_max(s_t1.intensite_pixel.x), min_max(s_t1.intensite_pixel.y), min_max(s_t1.intensite_pixel.z)));
			s_t1.j++;
		}
		s_t1.j = 0;
		s_t1.i++;
	}
	return (0);
}	
