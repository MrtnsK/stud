/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ox_arg_detect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:20:59 by hmoulher          #+#    #+#             */
/*   Updated: 2019/01/29 11:21:01 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	detect_arg_none_xo(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X')
	{
		i = ft_convhex((unsigned int)va_arg(arg, long), param->specifier);
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'o')
	{
		i = ft_convhoc((unsigned int)va_arg(arg, long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'b')
	{
		i = ft_convbin((unsigned int)va_arg(arg, long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}

void	detect_arg_hh_xo(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X')
	{
		i = ft_convhex((unsigned char)va_arg(arg, int), param->specifier);
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'o')
	{
		i = ft_convhoc((unsigned char)va_arg(arg, int));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'b')
	{
		i = ft_convbin((unsigned char)va_arg(arg, int));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}

void	detect_arg_h_xo(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X')
	{
		i = ft_convhex((unsigned short int)va_arg(arg, long), param->specifier);
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'o')
	{
		i = ft_convhoc((unsigned short int)va_arg(arg, long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'b')
	{
		i = ft_convbin((unsigned short int)va_arg(arg, long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}

void	detect_arg_ll_xo(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X')
	{
		i = ft_convhex((unsigned long long)va_arg(arg, unsigned long long),
			param->specifier);
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'o')
	{
		i = ft_convhoc((unsigned long long)va_arg(arg, unsigned long long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'b')
	{
		i = ft_convbin((unsigned long long)va_arg(arg, unsigned long long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}

void	detect_arg_l_xo(t_parameters *param, va_list arg)
{
	char *i;

	i = NULL;
	if (param->specifier == 'x' || param->specifier == 'X')
	{
		i = ft_convhex((unsigned long)va_arg(arg, long long), param->specifier);
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'o')
	{
		i = ft_convhoc((unsigned long)va_arg(arg, long long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	else if (param->specifier == 'b')
	{
		i = ft_convhoc((unsigned long)va_arg(arg, long long));
		if ((param->arg = (char*)malloc(sizeof(char) * (ft_strlen(i) + 1))))
			ft_strcpy(param->arg, i);
	}
	if (i)
		free(i);
}
