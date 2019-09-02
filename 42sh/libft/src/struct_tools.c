/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:28:34 by hmoulher          #+#    #+#             */
/*   Updated: 2019/01/29 13:28:36 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	init_t_parameters(t_parameters *param)
{
	param->specifier = 0;
	param->flags = NULL;
	param->widist = 0;
	param->width = 0;
	param->prexist = 0;
	param->precision = 0;
	param->lenght = NULL;
	param->arg = NULL;
	param->sign = 0;
	param->maj = 0;
	param->isp = 0;
	param->ismaj = 0;
}

void	free_struct(t_parameters *param)
{
	if (param->flags)
		free(param->flags);
	if (param->lenght)
		free(param->lenght);
	if (param->arg)
		free(param->arg);
}

void	n(t_parameters *param, t_norm *nrm)
{
	if (param->masterflag[1] == 2)
	{
		ft_putchar(0);
		ft_putstr(param->arg);
	}
	else
	{
		ft_putstr(param->arg);
		ft_putchar(0);
	}
	nrm->printed_char += ft_strlen(param->arg) + 1;
}

void	nfd(t_parameters *param, t_norm *nrm, int fd)
{
	if (param->masterflag[1] == 2)
	{
		ft_putchar_fd(0, fd);
		ft_putstr_fd(param->arg, fd);
	}
	else
	{
		ft_putstr_fd(param->arg, fd);
		ft_putchar_fd(0, fd);
	}
	nrm->printed_char += ft_strlen(param->arg) + 1;
}

void	check_maj_specifier(t_parameters *param)
{
	if (param->specifier != 'X' && param->specifier >= 'A'
		&& param->specifier <= 'Z')
	{
		param->specifier = ft_tolower(param->specifier);
		param->ismaj = 1;
	}
}
