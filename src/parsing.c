/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:22:34 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/13 17:10:51 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_a_light(char **line, t_scene *scene)
{
(void)line;
(void)scene;
	double res;

	scene->l_amb.type = 0;
	res = atod(line[1]); 
	if ((check_ratio(0, 1, res)))
	{
		scene->l_amb.intensity = res;
		scene->l_amb.color = atod_vc(line[3]);
		if (scene->l_amb.color.r == -1)
			ft_close("Ambiant light color not in range 0 - 255\n", scene, 5);
	}
	else
		ft_close("Ambiant light intensity not in range 0 - 1\n", scene, 5);
}

void	parse_elem(char **line, t_scene *scene)
{
	if (line[0][0] == 'A')
		init_a_light(line, scene);
	else if (line[0][0] == 'C')
		init_camera(line, scene);
	else if (line[0][0] == 'L')
		init_light(line, scene);
	else
		ft_close("Unknown element in the file !\n", scene, 5);
}

void	parse_obj(char **line, t_scene *scene)
{
	if (ft_strncmp(line[0], "sp", 3) == 0)
		init_sphere(line, scene);
	else if (ft_strncmp(line[0], "pl", 3) == 0)
		init_plan(line, scene);
	else if (ft_strncmp(line[0], "cy", 3) == 0)
		init_cyl(line, scene);
	else
		ft_close("Unknown element in the file !\n", scene, 5);
}

void	read_file(int fd, t_scene *scene)
{
	char	*l;
	char	**line;
	size_t	n;

	l = get_next_line(fd);
	n = ft_strlen(l);
	while (n != 0)
	{
		if (n > 1)
		{
   			printf("-- %s", l);
			line = ft_split(l, ' ');
			if (line && ft_strlen(line[0]) == 1)
				parse_elem(line, scene);
			else if (line && ft_strlen(line[0]) == 2)
				parse_obj(line, scene);
			else
			{
				free(l);
				free(line);
				ft_close("Unknown element in the file !\n", scene, 5);
			}
			free(l);
//			free(line);
		}
		l = get_next_line(fd);
		n = ft_strlen(l);
	}
	close(fd);
	exit (0);//pour test, a enlever
}
