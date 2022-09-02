/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:31:32 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/02 12:06:28 by Emiliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>

# define AMBIENT_LIGHT 0
# define CAMERA 1
# define POINT_LIGHT 2
# define SPHERE 3
# define PLAN 4
# define CYLINDER 5
# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_cam
{
	t_vector	pos;
	t_vector	orient;
	int			fov;
}	t_cam;

typedef struct s_obj
{
	int				type;
	t_vector		pos;
	t_vector		orientation;
	t_color			color;
	double			intensity;
	double			diameter;
	double			height;
	struct s_obj	*next;
}	t_obj;

typedef struct s_scene
{
	t_cam	cam;
	t_obj	l_amb;
	t_obj	p_light;
	t_obj	*obj_0;
	int		n_objs;
}	t_scene;

#endif
