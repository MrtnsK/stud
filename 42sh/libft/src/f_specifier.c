/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:42:44 by hmoulher          #+#    #+#             */
/*   Updated: 2019/01/23 13:58:01 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static void	detect_arg_f_none(t_parameters *param, va_list arg)
{
	char *f;

	f = ft_ftoa(va_arg(arg, double), param->precision);
	if ((!(ft_strcmp(f, "nan"))) || (!(ft_strcmp(f, "inf")))
		|| (!(ft_strcmp(f, "-inf"))))
	{
		param->specifier = 's';
		param->prexist = 0;
		param->precision = 0;
	}
	if (!(param->arg = (char*)malloc(sizeof(char) * (ft_strlen(f) + 1))))
		return ;
	ft_strcpy(param->arg, f);
	if (f)
		free(f);
}

static void	detect_arg_lf(t_parameters *param, va_list arg)
{
	char *f;

	f = ft_ftoa(va_arg(arg, double), param->precision);
	if (!(param->arg = (char*)malloc(sizeof(char) * (ft_strlen(f) + 1))))
		return ;
	ft_strcpy(param->arg, f);
	if (f)
		free(f);
}

static void	detect_arg_ulf(t_parameters *param, va_list arg)
{
	char *f;

	f = ft_ftoa(va_arg(arg, long double), param->precision);
	if (!(param->arg = (char*)malloc(sizeof(char) * (ft_strlen(f) + 1))))
		return ;
	ft_strcpy(param->arg, f);
	if (f)
		free(f);
}

void		detect_len_f(const char *str, int i, t_parameters *pm, va_list arg)
{
	while (str[i - 1] == '#' || str[i - 1] == ' ' || str[i - 1] == '+'
		|| str[i - 1] == '-' || str[i - 1] == '0' || (ft_isdigit(str[i - 1])))
		i--;
	if (i > 0 && str[i - 1] == 'l')
	{
		if (!(pm->lenght = (char*)malloc(sizeof(char) * 2)))
			return ;
		ft_strcpy(pm->lenght, "l");
		detect_arg_lf(pm, arg);
		return ;
	}
	else if (i > 0 && str[i - 1] == 'L')
	{
		if (!(pm->lenght = (char*)malloc(sizeof(char) * 2)))
			return ;
		ft_strcpy(pm->lenght, "L");
		detect_arg_ulf(pm, arg);
		return ;
	}
	detect_arg_f_none(pm, arg);
}
