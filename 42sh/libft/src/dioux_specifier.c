/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:47:56 by hmoulher          #+#    #+#             */
/*   Updated: 2019/01/26 12:47:59 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static void	is_unsigned(const char *str, int i, t_parameters *pm, va_list arg)
{
	if (i > 1 && str[i - 2] == 'h')
	{
		if ((pm->lenght = (char*)malloc(sizeof(char) * 3)))
			ft_strcpy(pm->lenght, "hh");
		detect_arg_hh(pm, arg);
	}
	else
	{
		if ((pm->lenght = (char*)malloc(sizeof(char) * 2)))
			ft_strcpy(pm->lenght, "h");
		detect_arg_h(pm, arg);
	}
}

static void	is_long(const char *str, int i, t_parameters *pm, va_list arg)
{
	if (i > 1 && str[i - 2] == 'l')
	{
		if ((pm->lenght = (char*)malloc(sizeof(char) * 3)))
			ft_strcpy(pm->lenght, "ll");
		detect_arg_ll(pm, arg);
	}
	else
	{
		if ((pm->lenght = (char*)malloc(sizeof(char) * 2)))
			ft_strcpy(pm->lenght, "l");
		detect_arg_l(pm, arg);
	}
}

void		detect_len_d(const char *str, int i, t_parameters *pm, va_list arg)
{
	while (str[i - 1] == '#' || str[i - 1] == ' ' || str[i - 1] == '+'
		|| str[i - 1] == '-' || str[i - 1] == '0' || (ft_isdigit(str[i - 1])))
		i--;
	if (i > 0 && str[i - 1] == 'h')
		is_unsigned(str, i, pm, arg);
	else if (i > 0 && str[i - 1] == 'l')
		is_long(str, i, pm, arg);
	else
		detect_arg_none(pm, arg);
}
