/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:31:32 by epresa-c          #+#    #+#             */
/*   Updated: 2022/09/19 13:24:57 by olmartin         ###   ########.fr       */
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
# define FALSE 0
# define TRUE 1

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
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*l;
	char	**line;
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
	t_vector	tmp;
}	t_trace;

/* *****************************  vector_utils.c  ****************************/

void		init_node(t_obj *new_node);
void		read_file(t_scene *scene);
t_obj		*start_t_obj(t_scene *scene);
void		add_t_obj(t_scene *scene);
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
void		init_camera(t_scene *scene);
void		init_light(t_scene *scene);
void		init_sphere(t_scene *scene);
void		init_plan(t_scene *scene);
void		init_cyl(t_scene *scene);
int			check_ratio(double min, double max, double nb);
double		atod(char *l, t_scene *scene, double min, double max);
t_color		atod_vc(char *l, t_scene *scene, double min, double max);
int			ft_atoi_rt(char *str, t_scene *scene, double min, double max);
t_vector	atod_v(char *l, t_scene *scene, double min, double max);
void		tab_free(char **tab);
double		stod(char *l);
int			check_input_p_p(char *s);
int			check_input_col(char *s);
int			check_input_pos(char *s);
int			tablen(char **t);
t_obj		*get_curr_cmd(t_scene *scene);
t_obj		*create_obj(t_scene *scene);
//temp
void		print_tobj(t_obj *obj);
void		print_tcam(t_cam *obj);
int			inter_cylinder(t_ray ray, t_obj c, t_ret_ray *ret);
float		vect_len(t_vector v);
float		distance_between_two_vectors(t_vector a, t_vector b);
int			inter_caps(t_ray ray, t_obj c, \
t_ret_ray *ret_local, t_ret_ray *ret);
void		calcule_a_b_c_delta(t_ray ray, t_inter_sp *s_inter, t_obj c);
int			inter_obj(t_ray s_r1, t_scene *scene, t_ret_ray *ret);
int			inter_caps(t_ray ray, t_obj c, \
t_ret_ray *ret_local, t_ret_ray *ret);
void		calcule_caps(t_vector *cyl_top_center, t_vector *cyl_bottom_center, \
t_obj *cylinder_cap, t_obj c);
int			verif_inside_cylindre_cap(t_ret_ray ret_local, \
t_obj c, t_obj cylinder_cap);
int			verif_inside_cylindre_body(const t_obj c, t_ret_ray *ret);
void		tab_free_full(char ***tab);
void		update_ret(int *res, t_ret_ray *ret, \
t_obj current, t_ret_ray loc_ret);

#endif
