/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silly_detect_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:18:25 by hmoulher          #+#    #+#             */
/*   Updated: 2019/01/29 13:18:28 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	check_specifier(const char *format, int i, t_parameters *param)
{
	int ulti_flag;

	ulti_flag = 0;
	while (format[--i] != '%')
	{
		if (format[i] != ' ' && format[i] != '+' && format[i] != '-'
			&& format[i] != '0' && format[i] != '#' && format[i] != '*'
			&& format[i] != '.' && !ft_isdigit(format[i]) && format[i] != 'h'
			&& format[i] != 'l' && format[i] != 'L')
			ulti_flag = 1;
	}
	if (ulti_flag == 1)
		param->specifier = 0;
}

void	detect_flags_2(const char *format, int *ptr_i, t_parameters *param)
{
	int		i;
	char	*str;

	i = *ptr_i;
	while ((param->ismaj == 0 && format[i] != param->specifier)
		|| (param->ismaj && format[i] != (param->specifier - 32)))
	{
		if (format[i] == '-' || format[i] == '+' || format[i] == ' '
			|| format[i] == '#'
			|| ((((i >= 1) && format[i] == '0'
			&& (!ft_isdigit(format[i - 1]))))
			&& (((i >= 1) && format[i] == '0' && format[i - 1] != '.'))))
		{
			str = (char*)malloc(sizeof(char) * 2);
			str[0] = format[i];
			str[1] = '\0';
			param->flags = ft_strjoin_free(param->flags, str);
			free(str);
		}
		i++;
	}
}

void	detect_flags_3(const char *format, int *ptr_i, t_parameters *param)
{
	int		i;

	i = *ptr_i;
	if (!(param->flags = (char*)malloc(sizeof(char))))
		return ;
	param->flags[0] = '\0';
	detect_flags_2(format, &i, param);
	if (param->flags)
		param->flags = ft_plus_ou_moins(param->flags);
}

void	detect_prec2(t_parameters *pm)
{
	if (pm->specifier == 'c' || pm->specifier == '%')
	{
		pm->prexist = 0;
		pm->precision = 0;
	}
}
