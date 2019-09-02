/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu_arg_detect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:20:42 by hmoulher          #+#    #+#             */
/*   Updated: 2019/07/01 15:11:02 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	detect_arg_none(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X'
		|| param->specifier == 'o' || param->specifier == 'b')
		detect_arg_none_xo(param, arg);
	else if (param->specifier == 'd' || param->specifier == 'i')
	{
		i = ft_itoa(va_arg(arg, int));
		if ((param->arg = (char*)malloc(sizeof(char) * ((ft_strlen(i) + 1)))))
			ft_strcpy(param->arg, i);
	}
	else
	{
		i = ft_unitoa((unsigned int)va_arg(arg, long));
		if ((param->arg = (char*)malloc(sizeof(char) * ((ft_strlen(i) + 1)))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}

void	detect_arg_hh(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X'
		|| param->specifier == 'o' || param->specifier == 'b')
		detect_arg_hh_xo(param, arg);
	else if (param->specifier == 'd' || param->specifier == 'i')
	{
		i = ft_itoa((signed char)va_arg(arg, int));
		if ((param->arg = (char*)malloc(sizeof(char) * ((ft_strlen(i) + 1)))))
			ft_strcpy(param->arg, i);
	}
	else
	{
		i = ft_unitoa((unsigned char)va_arg(arg, int));
		if ((param->arg = (char*)malloc(sizeof(char) * ((ft_strlen(i) + 1)))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}

void	detect_arg_h(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X'
		|| param->specifier == 'o' || param->specifier == 'b')
		detect_arg_h_xo(param, arg);
	else if (param->specifier == 'd' || param->specifier == 'i')
	{
		i = ft_itoa((short)va_arg(arg, int));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else
	{
		i = ft_unitoa((unsigned short int)va_arg(arg, long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}

void	detect_arg_ll(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X'
		|| param->specifier == 'o' || param->specifier == 'b')
		detect_arg_ll_xo(param, arg);
	else if (param->specifier == 'd' || param->specifier == 'i')
	{
		i = ft_itoa((long long int)va_arg(arg, long long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else
	{
		i = ft_unitoa((unsigned long long)va_arg(arg, unsigned long long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}

void	detect_arg_l(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X'
		|| param->specifier == 'o' || param->specifier == 'b')
		detect_arg_l_xo(param, arg);
	else if (param->specifier == 'd' || param->specifier == 'i')
	{
		i = ft_itoa((long)va_arg(arg, long long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else
	{
		i = ft_unitoa((unsigned long long)va_arg(arg, unsigned long long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}
