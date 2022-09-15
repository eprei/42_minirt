/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:22:34 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/15 14:58:11 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_a_light(char **line, t_scene *scene)
{
	if (tablen(line) != 3)
		ft_close("Ambiant light arguments not correct\n", scene, 5);
	scene->l_amb.type = 0;
	if (!check_input_p_p(line[1]))
		ft_close("Ambiant light ratio not correct\n", scene, 5);
	scene->l_amb.intensity = atod(line[1], scene, 0, 1);
	if (!check_input_col(line[2]))
		ft_close("Ambiant light color not correct\n", scene, 5);
	scene->l_amb.color = atod_vc(line[2], scene, 0, 255);
	print_tobj(&scene->l_amb);
}

void	parse_elem(char **line, t_scene *scene)
{
	if (line[0][0] == 'A')
		init_a_light(line, scene);
	else if (line[0][0] == 'C')
		init_camera(line, scene);
	else if (line[0][0] == 'L')
		init_light(line, scene);
	else if (ft_strncmp(line[0], "sp", 3) == 0)
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
	if (n > 0 && l[n - 1] == '\n')
		l[n - 1] = '\0';
	while (n != 0)
	{
		if (n > 1)
		{
			printf("-- %s\n", l);
			line = ft_split(l, ' ');
//			if (line && ft_strlen(line[0]) == 1)
			if (line)
				parse_elem(line, scene);
	/*		else if (line && ft_strlen(line[0]) == 2)
				parse_obj(line, scene);
	*/		else
			{
				free(l);
				free(line);
				ft_close("Unknown element in the file !\n", scene, 5);
			}
			free(l);
			free(line);
		}
		l = get_next_line(fd);
		n = ft_strlen(l);
		if (n > 0 && l[n - 1] == '\n')
			l[n - 1] = '\0';
	}
	close(fd);
	exit (0);//pour test, a enlever
}
