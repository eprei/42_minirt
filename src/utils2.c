/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:17:27 by olmartin          #+#    #+#             */
/*   Updated: 2022/09/13 17:13:01 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	check_ratio(double min, double max, double nb)
{
	if (nb >= min && nb <= max)
		return (1);
	return (0);
}

double	atod(char *l)
{
	double	res;
	char *dec;

	res = ft_atoi(l);
	dec = ft_strchr(l, '.');
	if (++dec)
	{
		res += ft_atoi(dec) / pow(10, ft_strlen(dec));
		//res = ft_atoi(dec) / (ft_strlen(dec) * 10);
		printf("l is decimal %f\n", res);
	}

	return (res);
}

int	ft_atoi_rt(char *str)
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
			ft_close("Problem with caracter '-'",sta);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + (str[i] - '0');
		else
			ft_error(s_sta);
		i++;
	}
	if ((s * nb) > 255 || (s * nb) < 0)
		return (-1);
	return (s * nb);
}

t_color	atod_vc(char *l)
{
	char	**res;
	int		rgb[3];
	int		nb;
	int		i;

	i = 0;
	res = ft_split(l, ',');
	while (res)
	{
		rgb[i] = atod(*res++);
		if (rgb[i++] < 0)
			rgb[0] = -1;
	}
	tab_free(res);
	free(res);		
	return(init_vec_col(rgb[0], rgb[1], rgb[2]));
}
