/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silly_detect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:48:08 by hmoulher          #+#    #+#             */
/*   Updated: 2019/01/26 12:48:10 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	detect_sign_n_maj(t_parameters *param)
{
	char *tmp;

	if (param->arg[0] == '-' && (ft_isdigit(param->arg[1]))
		&& param->specifier != 's')
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(param->arg) + 1))))
			return ;
		ft_strcpy(tmp, param->arg);
		free(param->arg);
		if (!(param->arg = (char*)malloc(sizeof(char) * ft_strlen(tmp))))
			return ;
		ft_strcpy(param->arg, tmp + 1);
		param->sign = 1;
		free(tmp);
	}
	if (param->specifier == 'x')
		param->maj = 0;
	else if (param->specifier == 'X')
		param->maj = 1;
}

int		detect_specifier(const char *format, int i, t_parameters *param)
{
	while (format[i])
	{
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p')
		{
			param->specifier = format[i];
			check_specifier(format, i, param);
			break ;
		}
		else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'o'
			|| format[i] == 'u' || format[i] == 'x' || format[i] == 'X'
			|| format[i] == 'f' || format[i] == 'b' || format[i] == 'F')
		{
			param->specifier = format[i];
			check_specifier(format, i, param);
			break ;
		}
		else if (format[i] == '%')
		{
			param->specifier = format[i];
			check_specifier(format, i, param);
			break ;
		}
		i++;
	}
	return (i);
}

void	detect_flags(const char *format, int *ptr_i, t_parameters *param)
{
	int i;
	int j;
	int k;

	i = *ptr_i;
	j = i;
	k = -1;
	while (format[i] == '-' || format[i] == '+' || format[i] == '0'
		|| format[i] == ' ' || format[i] == '#')
		i++;
	if (i != *ptr_i)
	{
		if (!(param->flags = (char*)malloc(sizeof(char) * ((i - j) + 1))))
			return ;
		while (j < i)
			param->flags[++k] = format[j++];
		param->flags[++k] = '\0';
		*ptr_i = i;
		detect_flags_2(format, &i, param);
		param->flags = ft_plus_ou_moins(param->flags);
	}
	else
	{
		detect_flags_3(format, &i, param);
	}
}

void	detect_width(const char *str, int *ptr_i, t_parameters *pm, va_list arg)
{
	int i;
	int save;

	i = *ptr_i;
	if (ft_isdigit(str[i]))
	{
		pm->width = ft_atoi(str + i);
		pm->widist = 1;
		while (ft_isdigit(str[i]))
			i++;
	}
	if (str[i] == '*')
	{
		save = (size_t)va_arg(arg, int);
		if (save < 0)
		{
			pm->flags = ft_strjoin_free(pm->flags, "-");
			pm->flags = ft_plus_ou_moins(pm->flags);
		}
		save < 0 ? save *= -1 : save;
		pm->width = save;
		pm->widist = 1;
		i++;
	}
	*ptr_i = i;
}

void	detect_prec(const char *str, int *p_i, t_parameters *pm, va_list arg)
{
	int i;

	i = *p_i;
	i++;
	if (ft_isdigit(str[i]))
	{
		pm->precision = ft_atoi(str + i);
		pm->prexist = 1;
		while (ft_isdigit(str[i]))
			i++;
	}
	else if (str[i] == '*')
	{
		pm->precision = (size_t)va_arg(arg, int);
		pm->prexist = 1;
		i++;
	}
	else
	{
		pm->prexist = 1;
		pm->precision = 0;
	}
	detect_prec2(pm);
	*p_i = i;
}
