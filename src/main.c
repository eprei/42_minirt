/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:12:48 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/13 10:28:25 by Emiliano         ###   ########.fr       */
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
	int		res;
	t_scene	scene;

	(void)argc;
	(void)argv;
	init_scene(&scene);
	scene.mlx_ptr = mlx_init();
	if (scene.mlx_ptr == NULL)
		return (1);
	scene.win_ptr = mlx_new_window(scene.mlx_ptr, scene.h, \
			scene.w, "42 testRT");
	if (scene.win_ptr == NULL)
	{
		free(scene.win_ptr);
		return (1);
	}
	res = raytracing(&scene);
	mlx_key_hook(scene.win_ptr, &deal_key, &scene);
	mlx_hook(scene.win_ptr, 17, 0, &exit_button, NULL);
	mlx_loop(scene.mlx_ptr);
	mlx_destroy_window(scene.mlx_ptr, scene.win_ptr);
	free(scene.mlx_ptr);
	return (0);
}
