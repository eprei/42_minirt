/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:25:31 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/05 10:39:05 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//int	raytracing(t_scene *scene, int w, int h, t_cam cam)
int	raytracing(t_scene *scene, t_obj *obj1)
{
	(void)obj1;
	t_trace	s_t1;

	s_t1.i = 0;
	s_t1.j = 0;
	s_t1.s_r1.o.x = 0;s_t1.s_r1.o.y = 0;s_t1.s_r1.o.z = 0;
	s_t1.intensite_pixel = 0;
	while (s_t1.i < scene->h)
	{
		while (s_t1.j < scene->w)
		{
			s_t1.s_r1.d.x = s_t1.j - scene->w /2;
		    s_t1.s_r1.d.y = s_t1.i - scene->h / 2;
		   	s_t1.s_r1.d.z = - scene->w / (2 * tan(scene->cam.fov/2));
			normalize(&s_t1.s_r1.d);
//			if (inter_sphere(&s_t1, obj1))
			if (1 > 0)			
			{
				s_t1.tmp = op_minus(scene->p_light.pos, s_t1.p);
				normalize(&s_t1.tmp);
				s_t1.intensite_pixel = scene->p_light.intensity * \
				max_v(op_dot(s_t1.tmp, s_t1.n)) / \
				get_norm2(op_minus(scene->p_light.pos, s_t1.p));
			}
			s_t1.intensite_pixel = min_max(s_t1.intensite_pixel);
			mlx_pixel_put(scene->mlx_ptr, scene->win_ptr, s_t1.j, scene->h - s_t1.i - 1, create_rgb(s_t1.intensite_pixel, s_t1.intensite_pixel, s_t1.intensite_pixel));
			s_t1.j++;
		}
		s_t1.i++;
	}
	return (0);
}	

/*
ok	for (int i = 0; i < H; i++)
ok		{
ok			for (int j  = 0; j < W; j++)
ok			{
ok
ok				t_vector	dir;
ok				t_vector	p;
ok				t_vector	n;
ok				t_vector	tmp;
ok				dir.coord[0] = j - W /2; dir.coord[1] = i - H / 2; dir.coord[2] = - W / (2 * tan(fov/2));
ok				normalize(&dir);
ok				t_ray r1;
ok				r1.o.coord[0] = 0;r1.o.coord[1] = 0;r1.o.coord[2] = 0;
ok				r1.d = dir;
ok				double intensite_pixel = 0;
				if (inter_sphere(r1, s1, &p, &n))
				{
					tmp = op_minus(pos_l, p);
					normalize(&tmp);
					intensite_pixel = intens_lum * max_v(op_dot(tmp, n)) / get_norm2(op_minus(pos_l, p));
					//mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x0000FF00); //vert
				}
				mlx_pixel_put(mlx_ptr, win_ptr, j, H - i - 1, createRGB(min_max(intensite_pixel), min_max(intensite_pixel), min_max(intensite_pixel)));
	return (0);
}
*/
