/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:48:26 by hmoulher          #+#    #+#             */
/*   Updated: 2019/01/26 12:48:29 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static void	detect_arg_c(t_parameters *param, va_list arg, va_list arg_cpy)
{
	if (va_arg(arg_cpy, int) != 0)
	{
		if (!(param->arg = (char*)malloc(sizeof(char) * 2)))
			return ;
		param->arg[0] = (char)(va_arg(arg, int));
		param->arg[1] = '\0';
	}
	else
	{
		if (!(param->arg = (char*)malloc(sizeof(char) * 1)))
			return ;
		param->arg[0] = '\0';
		param->specifier = 'N';
	}
}

static void	detect_arg_s(t_parameters *param, va_list arg,
	va_list arg_cpy, va_list arg_cpy2)
{
	char	*str;
	char	str2;

	str = va_arg(arg_cpy, char*);
	str2 = va_arg(arg_cpy2, int);
	if (str)
	{
		if (!(param->arg = (char*)malloc(sizeof(char) *
			(ft_strlen(str) + 1))))
			return ;
		ft_strcpy(param->arg, va_arg(arg, char*));
	}
	else
	{
		if ((param->arg = (char*)malloc(sizeof(char) * 1)))
			param->arg[0] = (char)va_arg(arg, int);
		if (param->arg)
		{
			free(param->arg);
			if (!(param->arg = (char*)malloc(sizeof(char) * 7)))
				return ;
			ft_strcpy(param->arg, "(null)");
		}
	}
}

static void	detect_arg_p(t_parameters *param, va_list arg)
{
	char	*p;

	p = ft_convhex((long)va_arg(arg, void*), 'x');
	if (!(param->arg = (char*)malloc(sizeof(char) * ft_strlen(p))))
		return ;
	ft_strcpy(param->arg, p);
	param->isp = 1;
	param->specifier = 'x';
	if (param->flags)
		param->flags = ft_strjoin_free(param->flags, "#");
	else
	{
		if (!(param->flags = (char*)malloc(sizeof(char) * 2)))
			return ;
		ft_strcpy(param->flags, "#");
	}
	if (p)
		free(p);
}

void		detect_arg_csp(t_parameters *param, va_list arg)
{
	va_list	arg_cpy;
	va_list	arg_cpy2;

	va_copy(arg_cpy, arg);
	va_copy(arg_cpy2, arg);
	if (param->specifier == 'c')
		detect_arg_c(param, arg, arg_cpy);
	else if (param->specifier == 's')
		detect_arg_s(param, arg, arg_cpy, arg_cpy2);
	else if (param->specifier == 'p')
		detect_arg_p(param, arg);
	else if (param->specifier == '%')
	{
		if (!(param->arg = (char*)malloc(sizeof(char) * 2)))
			return ;
		ft_strcpy(param->arg, "%");
	}
	va_end(arg_cpy);
	va_end(arg_cpy2);
}
