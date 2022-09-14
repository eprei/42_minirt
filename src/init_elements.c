/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:21:48 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/14 16:17:34 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_camera(char **line, t_scene *scene)
{
	if (tablen(line) != 4)
        ft_close("Camera arguments not correct\n", scene, 5);
    cam.type = 1;
    if (!check_input_p_p(line[1]))
        ft_close("Camera intensity not correct\n", scene, 5);
    cam.intensity = atod(line[1], scene, 0, 1);
    if (!check_input_col(line[2]))
        ft_close("Camera color not correct\n", scene, 5);
    cam.color = atod_vc(line[2], scene, 0, 255);
    print_tobj(&cam);
}

void	init_light(char **line, t_scene *scene)
{
(void)line;
(void)scene;
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
