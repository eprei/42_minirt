/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:46:00 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/15 10:17:03 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	check_input_pos(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == '.' || (s[i] >= '0' && s[i] <= '9') || s[i] == ',' || s[i] == '-'))
		return (0);
		i++;
	}
	return (1);
}

int	check_input_p_p(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == '.' || (s[i] >= '0' && s[i] <= '9')))
		return (0);
		i++;
	}
	return (1);
}

int	check_input_col(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == ',' || (s[i] >= '0' && s[i] <= '9')))
		return (0);
		i++;
	}
	return (1);
}

void	print_tobj(t_obj *obj)
{
	printf("Objet\n");
	printf("type :%d   pos %f - %f - %f\n", obj->type, obj->pos.x, obj->pos.y, obj->pos.z);
	printf("Orient :%f - %f - %f  color %d - %d - %d\n", obj->orientation.x, obj->orientation.y, obj->orientation.z, obj->color.r ,obj->color.g, obj->color.b);
	printf("Inten: %f Diam: %f Height: %f\n", obj->intensity, obj->diameter, obj->height);
}

void	print_tcam(t_cam *obj)
{
	printf("Camera\n");
	printf("Pos %f - %f - %f\n", obj->pos.x, obj->pos.y, obj->pos.z);
	printf("Orient :%f - %f - %f  up %f - %f - %f\n", obj->orient.x, obj->orient.y, obj->orient.z, obj->up.x ,obj->up.y, obj->up.z);
	printf("Right %f - %f - %f  FOV: %f\n", obj->right.x, obj->right.y, obj->right.z, obj->fov) ;
}

