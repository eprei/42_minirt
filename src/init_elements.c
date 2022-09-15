/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:21:48 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/15 16:10:17 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_camera(char **line, t_scene *scene)
{
	if (tablen(line) != 4)
		ft_close("Camera arguments not correct\n", scene, 5);
	if (!check_input_pos(line[1]))
		ft_close("Camera  position not correct\n", scene, 5);
	scene->cam.pos = atod_v(line[1], scene, -1E9, 1E9);
	if (!check_input_pos(line[2]))
		ft_close("Camera  orientation not correct\n", scene, 5);
	scene->cam.orient = atod_v(line[2], scene, -1, 1);
	if (!check_input_p_p(line[3]))
		ft_close("Camera FOV not correct\n", scene, 5);
	scene->cam.fov = atod(line[3], scene, 0, 180);
	print_tcam(&scene->cam);
}

void	init_light(char **line, t_scene *scene)
{
	if (tablen(line) != 3)
		ft_close("Light arguments not correct\n", scene, 5);
	scene->p_light.type = 2;
	if (!check_input_pos(line[1]))
		ft_close("Light  position not correct\n", scene, 5);
	scene->p_light.pos = atod_v(line[1], scene, -1E9, 1E9);
	if (!check_input_pos(line[2]))
		ft_close("Light  ratio not correct\n", scene, 5);
	scene->p_light.diameter = atod(line[2], scene, -1, 1);
	print_tobj(&scene->p_light);
}

void	init_sphere(char **line, t_scene *scene)
{
	t_obj	*curr;

	curr = create_obj(scene);
	if (tablen(line) != 4)
		ft_close("Sphere arguments not correct\n", scene, 5);
	curr->type = 3;
	if (!check_input_pos(line[1]))
		ft_close("Sphere  position not correct\n", scene, 5);
	curr->pos = atod_v(line[1], scene, -1E9, 1E9);
	if (!check_input_pos(line[2]))
		ft_close("Sphere  ratio not correct\n", scene, 5);
	curr->diameter = atod(line[2], scene, -1E9, 1E9);
	if (!check_input_col(line[3]))
		ft_close("Sphere color not correct\n", scene, 5);
	curr->color = atod_vc(line[3], scene, 0, 255);
	print_tobj(curr);
}

void	init_plan(char **line, t_scene *scene)
{
	t_obj	*curr;

	curr = create_obj(scene);
	if (tablen(line) != 4)
		ft_close("Plan arguments not correct\n", scene, 5);
	curr->type = 4;
	if (!check_input_pos(line[1]))
		ft_close("Plan  position not correct\n", scene, 5);
	curr->pos = atod_v(line[1], scene, -1E9, 1E9);
	if (!check_input_pos(line[2]))
		ft_close("Plan  ratio not correct\n", scene, 5);
	curr->orientation = atod_v(line[2], scene, -1E9, 1E9);
	if (!check_input_col(line[3]))
		ft_close("Plan color not correct\n", scene, 5);
	curr->color = atod_vc(line[3], scene, 0, 255);
	print_tobj(curr);
}

void	init_cyl(char **line, t_scene *scene)
{
	t_obj	*curr;

	curr = create_obj(scene);
	if (tablen(line) != 6)
		ft_close("Cylinder arguments not correct\n", scene, 5);
	curr->type = 5;
	if (!check_input_pos(line[1]))
		ft_close("Cylinder  position not correct\n", scene, 5);
	curr->pos = atod_v(line[1], scene, -1E9, 1E9);
	if (!check_input_pos(line[2]))
		ft_close("Cylinder  ratio not correct\n", scene, 5);
	curr->orientation = atod_v(line[2], scene, -1E9, 1E9);
	if (!check_input_pos(line[3]))
		ft_close("Cylinder  ratio not correct\n", scene, 5);
	curr->diameter = atod(line[3], scene, -1E9, 1E9);
	if (!check_input_pos(line[4]))
		ft_close("Cylinder  ratio not correct\n", scene, 5);
	curr->height = atod(line[4], scene, -1E9, 1E9);
	if (!check_input_col(line[5]))
		ft_close("Cylinder color not correct\n", scene, 5);
	curr->color = atod_vc(line[5], scene, 0, 255);
	print_tobj(curr);
}
