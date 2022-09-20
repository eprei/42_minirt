/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:03:58 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/20 16:19:30 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	tab_free_full(char ***tab)
{
	int	i;

	i = 0;
	while (*tab && (*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
}

void	init_plane_struct(t_vector	*plane_ori_norm, \
t_vector *plane_pos_norm, t_obj plane)
{
	*plane_pos_norm = plane.pos;
	normalize(plane_pos_norm);
	*plane_ori_norm = plane.orientation;
	normalize(plane_ori_norm);
}
