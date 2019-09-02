/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:47:45 by hmoulher          #+#    #+#             */
/*   Updated: 2019/01/26 12:47:49 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

int				go_end(const char *format, int i)
{
	i--;
	while (format[++i])
	{
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p')
			return (i);
		else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'o'
			|| format[i] == 'u' || format[i] == 'x' || format[i] == 'X'
			|| format[i] == 'f' || format[i] == 'b' || format[i] == 'F')
			return (i);
		else if (format[i] == '%')
			return (i);
	}
	return (0);
}

t_parameters	parameters_parser(const char *format, va_list arg, int i)
{
	int				pos;
	t_parameters	param;

	init_t_parameters(&param);
	pos = detect_specifier(format, ++i, &param);
	check_maj_specifier(&param);
	detect_flags(format, &i, &param);
	detect_width(format, &i, &param, arg);
	if (format[i] == '.')
		detect_prec(format, &i, &param, arg);
	if (param.specifier == 'd' || param.specifier == 'i'
		|| param.specifier == 'o' || param.specifier == 'u'
		|| param.specifier == 'x' || param.specifier == 'X'
		|| param.specifier == 'b')
		detect_len_d(format, pos, &param, arg);
	else if (param.specifier == 'f' || param.specifier == 'F')
		detect_len_f(format, pos, &param, arg);
	else if (param.specifier == 'c' || param.specifier == 's'
		|| param.specifier == 'p' || param.specifier == '%')
		detect_arg_csp(&param, arg);
	if (param.arg)
		detect_sign_n_maj(&param);
	if (param.widist && param.width && param.specifier == 'N')
		param.width -= 1;
	return (param);
}

void			procedure2(const char *format, t_norm *sympa)
{
	sympa->i += 1;
	while (format[sympa->i] == ' ' || format[sympa->i] == '+'
		|| format[sympa->i] == '-' || format[sympa->i] == '0'
		|| format[sympa->i] == '#' || format[sympa->i] == '*'
		|| format[sympa->i] == '.' || ft_isdigit(format[sympa->i])
		|| format[sympa->i] == 'h' || format[sympa->i] == 'l'
		|| format[sympa->i] == 'L')
		sympa->i += 1;
	sympa->i -= 1;
}

static void		procedure(t_parameters *param, t_norm *nrm, const char *format)
{
	if (param->specifier != 0)
	{
		ft_printprec(param);
		ft_printsign(param);
		ft_widthower(param);
		if (param->specifier == 'N')
			n(param, nrm);
		else
		{
			ft_putstr(param->arg);
			nrm->printed_char += ft_strlen(param->arg);
		}
	}
	else
		nrm->i = nrm->j;
	if (param->specifier == 0)
		procedure2(format, nrm);
	free_struct(param);
}

int				ft_printf(const char *format, ...)
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
			ft_putchar(format[sympa.i]);
			sympa.printed_char += 1;
		}
		else
		{
			sympa.j = sympa.i;
			param = parameters_parser(format, arg, sympa.i);
			sympa.i = go_end(format, sympa.i + 1);
			procedure(&param, &sympa, format);
		}
		sympa.i += 1;
	}
	va_end(arg);
	return (sympa.printed_char);
}
