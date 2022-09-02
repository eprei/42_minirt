/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:12:48 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/02 17:18:42 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_scene	*scene;
	t_cam	*cam;
	t_obj	*obj1;
	void	*mlx_ptr;
	void	*win_ptr;	

	scene = (t_scene*)malloc(sizeof(t_scene));
	cam = (t_cam*)malloc(sizeof(t_cam));
	obj1 = (t_obj*)malloc(sizeof(t_obj));
	if (!scene || !cam || !obj1)
		//close
		return (0);
	scene->h = 1000;
	scene->w = 1000;
	cam->fov = 60 * M_PI / 180;
	obj1->pos.x = 0;obj1->pos.y = 0;obj1->pos.z = -55;
	obj1->diameter = 20;
	scene->p_light.pos.x = 15;scene->p_light.pos.y = 70;
	scene->p_light.pos.z = -40;scene->p_light.intensity = 1000000;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, scene->h, scene->w, "42 testRT");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (1);
	}




	printf("RED = %x\n", create_rgb(0, 125, 0));
	return (0);
}
