/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:21:48 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/20 10:10:54 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_camera(t_scene *scene)
{
	if (scene->cam.fov != -1)
		ft_close("Camera already configured", scene, 5);
	if (tablen(scene->line) != 4)
		ft_close("Camera arguments not correct", scene, 5);
	if (!check_input_pos(scene->line[1]))
		ft_close("Camera  position not correct", scene, 5);
	scene->cam.pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[2]))
		ft_close("Camera  orientation not correct", scene, 5);
	scene->cam.orient = atod_v(scene->line[2], scene, -1, 1);
	if (scene->cam.orient.x == 0 && scene->cam.orient.y == 0 && \
		scene->cam.orient.z == 0)
		ft_close("Camera  orientation not correct", scene, 5);
	if (!check_input_p_p(scene->line[3]))
		ft_close("Camera FOV not correct", scene, 5);
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
		ft_close("Light already configured", scene, 5);
	if (tablen(scene->line) != 3)
		ft_close("Light arguments not correct", scene, 5);
	scene->p_light.type = 2;
	if (!check_input_pos(scene->line[1]))
		ft_close("Light  position not correct", scene, 5);
	scene->p_light.pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[2]))
		ft_close("Light  ratio not correct", scene, 5);
	scene->p_light.intensity = 1000000 * atod(scene->line[2], scene, -1, 1);
}

void	init_sphere(t_scene *scene)
{
	t_obj	*curr;

	curr = create_obj(scene);
	if (tablen(scene->line) != 4)
		ft_close("Sphere arguments not correct", scene, 5);
	curr->type = 3;
	if (!check_input_pos(scene->line[1]))
		ft_close("Sphere  position not correct", scene, 5);
	curr->pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[2]))
		ft_close("Sphere  ratio not correct", scene, 5);
	curr->diameter = atod(scene->line[2], scene, -1E9, 1E9);
	if (!check_input_col(scene->line[3]))
		ft_close("Sphere color not correct", scene, 5);
	curr->color = atod_vc(scene->line[3], scene, 0, 255);
}

void	init_plan(t_scene *scene)
{
	t_obj	*curr;

	curr = create_obj(scene);
	if (tablen(scene->line) != 4)
		ft_close("Plan arguments not correct", scene, 5);
	curr->type = 4;
	if (!check_input_pos(scene->line[1]))
		ft_close("Plan  position not correct", scene, 5);
	curr->pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[2]))
		ft_close("Plan  ratio not correct", scene, 5);
	curr->orientation = atod_v(scene->line[2], scene, -1E9, 1E9);
	if (!check_input_col(scene->line[3]))
		ft_close("Plan color not correct", scene, 5);
	curr->color = atod_vc(scene->line[3], scene, 0, 255);
}

void	init_cyl(t_scene *scene)
{
	t_obj	*curr;

	curr = create_obj(scene);
	if (tablen(scene->line) != 6)
		ft_close("Cylinder arguments not correct", scene, 5);
	curr->type = 5;
	if (!check_input_pos(scene->line[1]))
		ft_close("Cylinder  position not correct", scene, 5);
	curr->pos = atod_v(scene->line[1], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[2]))
		ft_close("Cylinder  ratio not correct", scene, 5);
	curr->orientation = atod_v(scene->line[2], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[3]))
		ft_close("Cylinder  ratio not correct", scene, 5);
	curr->diameter = atod(scene->line[3], scene, -1E9, 1E9);
	if (!check_input_pos(scene->line[4]))
		ft_close("Cylinder  ratio not correct", scene, 5);
	curr->height = atod(scene->line[4], scene, -1E9, 1E9);
	if (!check_input_col(scene->line[5]))
		ft_close("Cylinder color not correct", scene, 5);
	curr->color = atod_vc(scene->line[5], scene, 0, 255);
}
