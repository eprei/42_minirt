/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:21:48 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/15 11:29:12 by olmartin         ###   ########.fr       */
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
(void)line;
(void)scene;
}

void	init_plan(char **line, t_scene *scene)
{
(void)line;
(void)scene;
}

void	init_cyl(char **line, t_scene *scene)
{
(void)line;
(void)scene;
}
