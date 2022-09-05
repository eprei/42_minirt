/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:12:48 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/05 17:15:36 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int		res;
	t_scene	*scene;
	t_obj	*obj1;
	//void	*mlx_ptr;
	//void	*win_ptr;	

	scene = (t_scene*)malloc(sizeof(t_scene));
	obj1 = (t_obj*)malloc(sizeof(t_obj));
	if (!scene)
		//close
		return (0);
	scene->h = 1000;
	scene->w = 1000;
	scene->cam.fov = 60 * M_PI / 180;
	obj1->pos.x = 0;obj1->pos.y = 0;obj1->pos.z = -55;
	obj1->diameter = 20;
	obj1->color.r = 1;obj1->color.r = 0;obj1->color.r = 0;
	scene->p_light.pos.x = 15;scene->p_light.pos.y = 70;
	scene->p_light.pos.z = -40;scene->p_light.intensity = 1000000;
	scene->mlx_ptr = mlx_init();
	if (scene->mlx_ptr == NULL)
		return (1);
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, scene->h, scene->w, "42 testRT");
	if (scene->win_ptr == NULL)
	{
		free(scene->win_ptr);
		return (1);
	}
	res = raytracing(scene, obj1);
	
	mlx_loop(scene->mlx_ptr);


	mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
	free(scene->mlx_ptr);



//	printf("RED = %x\n", create_rgb(0, 125, 0));
	return (0);
}
