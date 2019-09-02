/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:59:00 by pharatyk          #+#    #+#             */
/*   Updated: 2019/04/12 12:59:04 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static void		procedurefd(int fd, t_parameters *param,
	t_norm *nrm, const char *format)
{
	if (param->specifier != 0)
	{
		ft_printprec(param);
		ft_printsign(param);
		ft_widthower(param);
		if (param->specifier == 'N')
			nfd(param, nrm, fd);
		else
		{
			ft_putstr_fd(param->arg, fd);
			nrm->printed_char += ft_strlen(param->arg);
		}
	}
	else
		nrm->i = nrm->j;
	if (param->specifier == 0)
		procedure2(format, nrm);
	free_struct(param);
}

int				ft_printfd(int fd, const char *format, ...)
{
	va_list			arg;
	t_parameters	param;
	t_norm			sympa;

	sympa.i = 0;
	sympa.printed_char = 0;
	va_start(arg, format);
	while (format[sympa.i])
	{
		if (format[sympa.i] != '%')
		{
			ft_putchar_fd(format[sympa.i], fd);
			sympa.printed_char += 1;
		}
		else
		{
			sympa.j = sympa.i;
			param = parameters_parser(format, arg, sympa.i);
			sympa.i = go_end(format, sympa.i + 1);
			procedurefd(fd, &param, &sympa, format);
		}
		sympa.i += 1;
	}
	va_end(arg);
	return (sympa.printed_char);
}
