/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:09:24 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/12 14:25:33 by Emiliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_cam(t_scene *scene, t_vector pos, t_vector orient, double fov)
{
	t_cam	cam;
	cam.pos = pos;
	cam.orient = orient;
	cam.up = init_vector(0, 1, 0);
	cam.right = cross(orient, cam.up);
	cam.fov = fov * M_PI / 180;
	scene->cam = cam;
}

void	init_l_amb(t_scene *scene, double intensity, t_color color)
{
	scene->l_amb.color = color;
	scene->l_amb.intensity = intensity;
}
