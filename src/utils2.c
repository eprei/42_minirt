/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:17:27 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/14 15:36:22 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	stod(char *s)
{
	double	rez;
	double	fact;
	int		point;
	int		d;

	rez = 0;
	fact = 1;
	if (*s == '-')
	{
		s++;
		fact = -1;
	}
	while (*s)
	{
		if (*s == '.')
		{
			point = 1;
			s++;
			continue;
		}
		d = *s - '0';
		if (d <= 0 && d <= 9)
		{
			if (point)
				fact /= 10.0f;
			rez = rez * 10.0f + (float)d;
		}
		s++;
	}
	return (rez * fact);
}

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
	char *dec;

	(void)scene;
	res = ft_atoi(l);
	dec = ft_strchr(l, '.');
	if (dec && ++dec)
		res += ft_atoi_rt(dec, scene, min, 1E9) / pow(10, ft_strlen(dec));
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
		if (rgb[i] < 0 || rgb[i] > 255)
        	ft_close("Color is not correct\n", scene, 5);
		i++;	
	}
	tab_free(res);
	free(res);		
	return(init_vec_col(rgb[0], rgb[1], rgb[2]));
}
