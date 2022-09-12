/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:12:48 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/12 12:48:51 by olmartin         ###   ########.fr       */
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
	scene->h = 1000;
	scene->w = 1000;
	scene->cam.fov = 60 * M_PI / 180;
	start_t_obj(scene);
	scene->obj_0->pos = init_vector(0, 0, -55);
	scene->obj_0->diameter = 20;
	scene->obj_0->color = init_vec_col(255, 100, 0);
	add_t_obj(scene);
	scene->obj_0->next->pos = init_vector(30, -10, -60);
	scene->obj_0->next->diameter = 20;
	scene->obj_0->next->color = init_vec_col(100, 200, 0);
	scene->p_light.pos = init_vector(-20, 5, 0);
	scene->p_light.intensity = 1000000;
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
