/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:12:48 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/19 11:41:24 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	exit_button(void)
{
	write(1, "You have choosen to close the window !\n", 39);
	exit(0);
}

int	parse_file(char *file, t_scene *scene)
{
	int		fd;
	char	*a;

	a = ft_strrchr(file, '.');
	if (a == NULL || ft_strncmp(a, ".rt", 3) != 0)
		ft_close("Invalid mapfile extension! Mandatory: .rt", scene, 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_close("Invalid file !", scene, 0);
	read_file(fd, scene);
	return (0);
}

int	main(int argc, char **argv)
{
	int		res;
	t_scene	scene;

	(void)argc;
	(void)argv;
	scene.obj_0 = NULL;
	if (argc != 2)
		ft_close("Invalid number of arguments ! Mandatory : one file", &scene, 0);
	res = parse_file(argv[1], &scene);
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
