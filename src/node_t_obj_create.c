/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_t_obj_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:25:09 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/19 11:05:50 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_node(t_obj *new_node)
{
		new_node->type = 0;
		new_node->pos = init_vector(0, 0, 0);
		new_node->orientation = init_vector(0, 0, 0);
		new_node->color = init_vec_col(0, 0, 0);
		new_node->intensity = 0;
		new_node->diameter = 0;
		new_node->height = 0;
		new_node->next = NULL;
}

t_obj	*start_t_obj(t_scene *scene)
{
	t_obj	*new_node;

	new_node = malloc(sizeof(t_obj));
	if (new_node == NULL)
		ft_printf("Error malloc: new node creation has failed\n");
	else
	{
		init_node(new_node);
		scene->obj_0 = new_node;
	}
	return (new_node);
}

void	add_t_obj(t_scene *scene)
{
	t_obj	*new_node;
	t_obj	*curr;

	curr = scene->obj_0;
	new_node = malloc(sizeof(t_obj));
	while (curr->next != NULL)
		curr = curr->next;
	if (new_node == NULL)
		ft_printf("Error malloc: new node creation has failed\n");
	else
	{
		init_node(new_node);
		curr->next = new_node;
	}
}

t_obj	*get_curr_cmd(t_scene *scene)
{
	t_obj	*curr;

	curr = scene->obj_0;
	while (curr->next != NULL)
			curr = curr->next;
	return (curr);
}

t_obj	*create_obj(t_scene *scene)
{
	if (scene->obj_0 == NULL)
		start_t_obj(scene);
	else
		add_t_obj(scene);
	return (get_curr_cmd(scene));
}
