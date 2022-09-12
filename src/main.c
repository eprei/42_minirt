/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:12:48 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/12 14:57:49 by Emiliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	exit_button(void)
{
	write(1, "You have choosen to close the window !\n", 39);
	exit(0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int		res;
	t_scene	*scene;
	t_obj	*obj1;
	//void	*mlx_ptr;
	//void	*win_ptr;

	scene = (t_scene *)malloc(sizeof(t_scene));
	obj1 = (t_obj *)malloc(sizeof(t_obj));
	if (!scene)
		//close
		return (0);

	t_vector	pos;
	t_vector	orient;
	double		fov;

	fov = 90;
	pos = init_vector(50, 0, -55);
	orient = init_vector(-1, -0.2, 0);
	init_cam(scene, pos, orient, fov);

	t_color	l_amb_color;
	double	l_amb_intensity;

	l_amb_intensity = 0.4;
	l_amb_color = init_vec_col(255, 255, 255);

	init_l_amb(scene, l_amb_intensity, l_amb_color);

	scene->h = 800;
	scene->w = 800;
	start_t_obj(scene);
	scene->obj_0->type = PLAN;
	scene->obj_0->pos = init_vector(0, -20, 0);
	scene->obj_0->orientation = init_vector(0, 1, 0);
	scene->obj_0->color = init_vec_col(200, 10, 10);
	add_t_obj(scene);
	scene->obj_0->next->type = SPHERE;
	scene->obj_0->next->pos = init_vector(0, 0, -55);
	scene->obj_0->next->diameter = 20;
	scene->obj_0->next->color = init_vec_col(255, 100, 0);
	add_t_obj(scene);
	scene->obj_0->next->next->type = SPHERE;
	scene->obj_0->next->next->pos = init_vector(30, -10, -60);
	scene->obj_0->next->next->diameter = 10;
	scene->obj_0->next->next->color = init_vec_col(100, 200, 0);
	scene->p_light.pos = init_vector(25, 60, -65);
	scene->p_light.intensity = 500000;

	scene->mlx_ptr = mlx_init();
	if (scene->mlx_ptr == NULL)
		return (1);
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, scene->h, \
			scene->w, "42 testRT");
	if (scene->win_ptr == NULL)
	{
		free(scene->win_ptr);
		return (1);
	}
	res = raytracing(scene);
	mlx_key_hook(scene->win_ptr, &deal_key, scene);
	mlx_hook(scene->win_ptr, 17, 0, &exit_button, NULL);
	mlx_loop(scene->mlx_ptr);
	mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
	free(scene->mlx_ptr);
	return (0);
}
