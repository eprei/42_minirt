/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:09:24 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/17 10:59:10 by Emiliano         ###   ########.fr       */
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
	normalize(&cam.right);
	normalize(&cam.up);
	normalize(&cam.orient);
	scene->cam = cam;
}

void	init_l_amb(t_scene *scene, double intensity, t_color color)
{
	scene->l_amb.color = color;
	scene->l_amb.intensity = intensity;
}

void	init_scene(t_scene *scene)
{
	t_vector	cam_pos;
	t_vector	cam_orient;
	double		cam_fov;
	t_color		l_amb_color;
	double		l_amb_intensity;

/******************* RESOLUTION **************************/
	scene->h = 700;
	scene->w = 700;
/*********************** CAMERA **************************/
	cam_fov = 60;
	cam_pos = init_vector(-20, 20, 40);
	cam_orient = init_vector(0, 0, -1);
	init_cam(scene, cam_pos, cam_orient, cam_fov);
/*********************** LUM AMBIENT *********************/
	l_amb_intensity = 0.2;
	l_amb_color = init_vec_col(255, 255, 255);
	init_l_amb(scene, l_amb_intensity, l_amb_color);
/****************** LIGHT POINT **************************/
	scene->p_light.pos = init_vector(40, 70, 20);
	scene->p_light.intensity = 2000000;
/****************** OBJ_0 PLAN **************************/
	start_t_obj(scene);
	scene->obj_0->type = PLAN;
	scene->obj_0->pos = init_vector(0, -20, 0);
	scene->obj_0->orientation = init_vector(0.5, 1, 0);
	scene->obj_0->color = init_vec_col(150, 150, 150);
/****************** OBJ_1 SPHERE ************************/
	add_t_obj(scene);
	scene->obj_0->next->type = SPHERE;
	scene->obj_0->next->pos = init_vector(0, 0, -55);
	scene->obj_0->next->diameter = 20;
	scene->obj_0->next->color = init_vec_col(30, 240, 30);
/**************** OBJ_2 SPHERE **************************/
	add_t_obj(scene);
	scene->obj_0->next->next->type = SPHERE;
	scene->obj_0->next->next->pos = init_vector(30, -10, -60);
	scene->obj_0->next->next->diameter = 10;
	scene->obj_0->next->next->color = init_vec_col(30, 30, 200);
/**************** OBJ_2 CYLINDRE **************************/
	add_t_obj(scene);
	scene->obj_0->next->next->next->type = CYLINDER;
	scene->obj_0->next->next->next->pos = init_vector(-40, 25, -60);
	scene->obj_0->next->next->next->orientation = init_vector(0, 1, -1);
	scene->obj_0->next->next->next->diameter = 20;
	scene->obj_0->next->next->next->height = 30;
	scene->obj_0->next->next->next->color = init_vec_col(200, 70, 70);
}
