/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:22:34 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/13 12:28:26 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_a _light(char **line, t_scene *scene)
{
	

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
	if (line[0] == "sp")
		init_sphere(line, scene);
	else if (line[0] == "pl")
		init_plan(line, scene);
	else if (line[0] == "cy")
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
		if (l != NULL && l[n - 1] == '\n')
		{
   			printf("-- %s", l);
			line = ft_split(l, ' ');
			if (line && ft_strlen(line[0] == 1))
				parse_elem(line, scene)
			else if (line && ft_strlen(line[0] == 2))
				parse_obj(line, scene);
			else
			{
				free(l);
				free(line);
				ft_close

			free(l);
//			free(line);
		}
		l = get_next_line(fd);
		n = ft_strlen(l);
	}
	close(fd);
}
