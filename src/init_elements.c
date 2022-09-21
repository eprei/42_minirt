/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:21:48 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/21 10:25:06 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_camera(t_scene *scene)
{
	if (scene->cam.fov != -1)
		ft_error("Camera already configured", scene, 5);
	if (tablen(scene->line) != 4)
		ft_error("Camera arguments not correct", scene, 5);
	if (!check_input_pos(scene->line[1]))
		ft_error("Camera  position not correct", scene, 5);
	scene->cam.pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[2]))
		ft_error("Camera  orientation not correct", scene, 5);
	scene->cam.orient = atod_v(scene->line[2], scene, -1, 1);
	if (!check_input_p_p(scene->line[3]))
		ft_error("Camera FOV not correct", scene, 5);
	scene->cam.fov = atod(scene->line[3], scene, 0, 180) * M_PI / 180;
	scene->cam.up = init_vector(0, 1, 0);
	scene->cam.right = cross(scene->cam.orient, scene->cam.up);
	normalize(&scene->cam.right);
	normalize(&scene->cam.up);
	normalize(&scene->cam.orient);
}

void	init_light(t_scene *scene)
{
	if (scene->p_light.type != -1)
		ft_error("Light already configured", scene, 5);
	if (tablen(scene->line) != 3)
		ft_error("Light arguments not correct", scene, 5);
	scene->p_light.type = 2;
	if (!check_input_pos(scene->line[1]))
		ft_error("Light  position not correct", scene, 5);
	scene->p_light.pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	scene->res = NULL;
	if (!check_input_p_p(scene->line[2]))
		ft_error("Light  ratio not correct", scene, 5);
	scene->p_light.intensity = 1000000 * atod(scene->line[2], scene, -1, 1);
}

void	init_sphere(t_scene *scene)
{
	t_obj	*curr;

	curr = create_obj(scene);
	if (tablen(scene->line) != 4)
		ft_error("Sphere arguments not correct", scene, 5);
	curr->type = 3;
	if (!check_input_pos(scene->line[1]))
		ft_error("Sphere position not correct", scene, 5);
	curr->pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	scene->res = NULL;
	if (!check_input_p_p(scene->line[2]))
		ft_error("Sphere radius not correct", scene, 5);
	curr->diameter = atod(scene->line[2], scene, 0.01, 1E9);
	if (!check_input_col(scene->line[3]))
		ft_error("Sphere color not correct", scene, 5);
	curr->color = atod_vc(scene->line[3], scene, 0, 255);
}

void	init_plan(t_scene *scene)
{
	t_obj	*curr;

	curr = create_obj(scene);
	if (tablen(scene->line) != 4)
		ft_error("Plan arguments not correct", scene, 5);
	curr->type = 4;
	if (!check_input_pos(scene->line[1]))
		ft_error("Plan  position not correct", scene, 5);
	curr->pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[2]))
		ft_error("Plan orientation not correct", scene, 5);
	curr->orientation = atod_v(scene->line[2], scene, -1, 1);
	if (!check_input_col(scene->line[3]))
		ft_error("Plan color not correct", scene, 5);
	curr->color = atod_vc(scene->line[3], scene, 0, 255);
}

void	init_cyl(t_scene *scene)
{
	t_obj	*curr;

	curr = create_obj(scene);
	if (tablen(scene->line) != 6)
		ft_error("Cylinder arguments not correct", scene, 5);
	curr->type = 5;
	if (!check_input_pos(scene->line[1]))
		ft_error("Cylinder position not correct", scene, 5);
	curr->pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[2]))
		ft_error("Cylinder orientation not correct", scene, 5);
	curr->orientation = atod_v(scene->line[2], scene, -1, 1);
	scene->res = NULL;
	if (!check_input_p_p(scene->line[3]))
		ft_error("Cylinder diameter not correct", scene, 5);
	curr->diameter = atod(scene->line[3], scene, 0.01, 1E9);
	if (!check_input_p_p(scene->line[4]))
		ft_error("Cylinder height not correct", scene, 5);
	curr->height = atod(scene->line[4], scene, 0.01, 1E9);
	if (!check_input_col(scene->line[5]))
		ft_error("Cylinder color not correct", scene, 5);
	curr->color = atod_vc(scene->line[5], scene, 0, 255);
}
