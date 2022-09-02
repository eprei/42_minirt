/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:18:14 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/02 12:25:44 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_vector	op_plus(const t_vector c1, const t_vector c2)
{
	t_vector	*res;

	res = malloc(sizeof(t_vector));
	if (!res)
		return (NULL);
	res->coord[0] = c1.coord[0] + c2.coord[0];
	res->coord[1] = c1.coord[1] + c2.coord[1];
	res->coord[2] = c1.coord[2] + c2.coord[2];
	return (*res);
}	

t_vector	op_minus(const t_vector c1, const t_vector c2)
{
	t_vector	*res;

	res = malloc(sizeof(t_vector));
	if (!res)
		return (NULL);
	res->coord[0] = c1.coord[0] - c2.coord[0];
	res->coord[1] = c1.coord[1] - c2.coord[1];
	res->coord[2] = c1.coord[2] - c2.coord[2];
	return (*res);
}	

t_vector	op_mult(double a, const t_vector c1)
{
	t_vector	*res;

	res = malloc(sizeof(t_vector));
	if (!res)
		return (NULL);
	res->coord[0] = c1.coord[0] * a;
	res->coord[1] = c1.coord[1] * a;
	res->coord[2] = c1.coord[2] * a;
	return (*res);
}	

t_vector	op_div(const t_vector c1, double a)
{
	t_vector	*res;

	res = malloc(sizeof(t_vector));
	if (!res)
		return (NULL);
	res->coord[0] = c1.coord[0] / a;
	res->coord[1] = c1.coord[1] / a;
	res->coord[2] = c1.coord[2] / a;
	return (*res);
}	

double	op_dot(const t_vector c1, const t_vector c2)
{
	return (c1.coord[0] * c2.coord[0] + c1.coord[1] * c2.coord[1] \
			+ c1.coord[2] * c2.coord[2]);
}	
