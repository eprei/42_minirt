/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_t_obj_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:34:28 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/20 10:05:00 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	del_content(void *content)
{
	(void)content;
	content = 0;// a voir
}

void	rt_lstclear(t_obj **objs, void (*del)(void *))
{
	t_obj	*ptr;
	t_obj	*tmp;

	if (del == 0 || objs == 0)
		return ;
	ptr = *objs;
	while (ptr != 0)
	{
		tmp = ptr->next;
		del(ptr);
		free(ptr);
		ptr = tmp;
	}
	*objs = 0;
}

void	ft_close(char *s, t_scene *scene, int level)
{
	(void)s;
	(void)level;
	ft_printf("%s\n", s);
	if (scene->obj_0)
		rt_lstclear(&scene->obj_0, &del_content);
//	while (1)
//		;
	exit (0);
}

int	deal_key(int key, t_scene *scene)
{
	if (key == ESC_KEY)
		ft_close("You have choosen to close the window !", scene, 10);
	return (0);
}

void	ft_error(char *s, t_scene *scene, int level)
{
	ft_printf("Error\n");
	close(scene->fd);
	if (level > 4)
	{
		tab_free_full(&scene->line);
		tab_free_full(&scene->res);
		free(scene->l);
	}	
	ft_close(s, scene, level);
}
