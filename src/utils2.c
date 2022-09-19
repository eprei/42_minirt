/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:17:27 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/19 11:10:56 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	check_ratio(double min, double max, double nb)
{
	if (nb >= min && nb <= max)
		return (1);
	return (0);
}

int	ft_atoi_rt(char *str, t_scene *scene, double min, double max)
{
	int		i;
	int		s;
	long	nb;

	i = 0;
	s = 1;
	nb = 0;
	if (str[i] == '-')
	{
		s = -1;
		i++;
		if (str[i] == '\0' || (str[i] < '1' || str[i] > '9'))
			ft_close("Non-numerical character", scene, 5);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + (str[i] - '0');
		else
			ft_close("Non-numerical character", scene, 5);
		i++;
	}
	if ((s * nb) > max || (s * nb) < min)
		return (-10);
	return (s * nb);
}

double	atod(char *l, t_scene *scene, double min, double max)
{
	double	res;
	double	fac;
	char	*dec;

	fac = 1;
	if (strncmp(l, "-0.", 3) == 0)
		fac = -1;
	res = ft_atoi(l);
	dec = ft_strchr(l, '.');
	if (dec && ++dec)
		res += ft_atoi_rt(dec, scene, min, 1E9) / pow(10, ft_strlen(dec));
	res = res * fac;
	if (res < min || res > max)
		ft_close("Value is not correct\n", scene, 5);
	return (res);
}

t_color	atod_vc(char *l, t_scene *scene, double min, double max)
{
	char	**res;
	int		rgb[3];
	int		i;

	i = 0;
	res = ft_split(l, ',');
	if (tablen(res) != 3)
		ft_close("Color arguments not correct\n", scene, 5);
	while (res[i])
	{
		rgb[i] = atod(res[i], scene, min, max);
		i++;
	}
	tab_free(res);
	free(res);
	return (init_vec_col(rgb[0], rgb[1], rgb[2]));
}

t_vector	atod_v(char *l, t_scene *scene, double min, double max)
{
	char	**res;
	double	vec[3];
	int		i;

	i = 0;
	res = ft_split(l, ',');
	if (tablen(res) != 3)
		ft_close("Color arguments not correct\n", scene, 5);
	while (res[i])
	{
		vec[i] = atod(res[i], scene, min, max);
		i++;
	}
	tab_free(res);
	free(res);
	return (init_vector(vec[0], vec[1], vec[2]));
}