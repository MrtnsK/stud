/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:20:03 by pharatyk          #+#    #+#             */
/*   Updated: 2019/03/04 11:20:04 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static double	ft_endatof(double out, double mantisse, int sign, int k)
{
	if (sign == -1)
		out *= -1;
	while ((int)mantisse != 0)
		mantisse /= 10;
	while (k-- > 0)
		mantisse /= 10;
	out += mantisse;
	return (out * sign);
}

double			ft_atof(char *str)
{
	double				out;
	double				mantisse;
	int					sign;
	int					i;
	int					k;

	k = 0;
	if (str[0] == '-')
		sign = -1;
	else
		sign = 1;
	i = -1;
	while (str[++i] && str[i] != '.')
		;
	if (str[i] == 0)
		return ((double)ft_ultimatoi(str));
	str[i] = 0;
	out = (double)ft_ultimatoi(str);
	while (str[++i] == '0')
		k++;
	mantisse = (double)ft_ultimatoi(str + i);
	return (ft_endatof(out, mantisse, sign, k));
}
