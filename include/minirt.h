/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Emiliano <Emiliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:31:32 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/13 10:13:18 by Emiliano         ###   ########.fr       */
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
# define MY_PI 3.1415
# define ESC_KEY 53

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
	t_vector	up;
	t_vector	right;
	double		fov;
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
	int		h;
	int		w;
	void	*mlx_ptr;
	void	*win_ptr;
	t_cam	cam;
	t_obj	l_amb;
	t_obj	p_light;
	t_obj	*obj_0;
	int		n_objs;
}	t_scene;

typedef struct s_inter_sp
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
	double	t;// pas utile depuis multisphere ??
}	t_inter_sp;

typedef struct s_ray
{
	t_vector	o;
	t_vector	d;
}	t_ray;

typedef struct s_ret_ray
{
	t_vector	p;
	t_vector	n;
	double		t;
	t_color		col;
}	t_ret_ray;

typedef struct s_trace
{
	int			i;
	int			j;
	double		t;
	t_vector	intensite_pixel;
	t_ray		s_r1;
	t_ray		s_rli;
	t_vector	p;
	t_vector	n;
	//t_vector	p_light;
	//t_vector	n_light;
	t_vector	tmp;
}	t_trace;

/* *****************************  vector_utils.c  ****************************/

void		init_node(t_obj *new_node);
void		read_file(int fd, t_scene *scene);
t_obj		*start_t_obj(t_scene *scene);
void		add_t_obj(t_scene *scene);
int			count_objs(t_scene *scene);
void		del_content(void *content);
void		rt_lstclear(t_obj **objs, void (*del)(void *));
t_vector	op_plus(const t_vector c1, const t_vector c2);
t_vector	op_minus(const t_vector c1, const t_vector c2);
t_vector	op_mult(double a, const t_vector c1);
t_vector	op_mult_c(double a, const t_color c1);
t_vector	op_div(const t_vector c1, double a);
double		op_dot(const t_vector c1, const t_vector c2);
double		get_norm2(t_vector c1);
void		normalize(t_vector *c1);
int			create_rgb(int r, int g, int v);
double		max_v(double a);
double		min_max(double a);
t_vector	init_vector(double x, double y, double z);
t_color		init_vec_col(int r, int g, int b);
int			raytracing(t_scene *scene);
int			inter_sphere(const t_ray d, const t_obj s, t_ret_ray *ret);
t_vector	albedo(t_color col);
int			deal_key(int key, t_scene *scene);
void		init_cam(t_scene *scene, t_vector pos, t_vector orient, double fov);
void		init_l_amb(t_scene *scene, double intensity, t_color color);
t_vector	cross(t_vector vect_a, t_vector vect_b);
int			inter_plane(const t_ray d, const t_obj plane, t_ret_ray *ret);
void		init_scene(t_scene *scene);
void		ft_close(char *s, t_scene *scene, int level);


#endif
