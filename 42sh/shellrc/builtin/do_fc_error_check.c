/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fc_error_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:54:32 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/16 09:02:13 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		illegal_opt(char c)
{
	ft_printfd(2, "\e[93mMastershell\e[0m: fc: -%c: invalid option\n", c);
	ft_printfd(2, "fc: usage: fc [-e ename] [-nlr] [first] [last] \
or fc -s [pat=rep] [cmd]\n");
	return (-1);
}

void	fc_usage(void)
{
	ft_printfd(2, "\e[93mMastershell\e[0m: fc: -e: \
option requires an argument\n");
	ft_printfd(2, "fc: usage: fc [-e ename] [-nlr] [first] [last] \
or fc -s [pat=rep] [cmd]\n");
}

void	error_list(void)
{
	ft_printfd(2, "\e[93mMastershell\e[0m: fc: \
history specification out of range\n");
}

int		ft_strdigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]) && i < 2)
			return (0);
		i++;
	}
	return (1);
}

int		ft_stralpha(char *str)
{
	if (ft_isdigit(str[0]))
		return (0);
	return (1);
}
