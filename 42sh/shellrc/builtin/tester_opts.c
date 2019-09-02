/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:42:06 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/15 12:48:48 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static	int		ft_check_opt1pt2(char *opt)
{
	if (!ft_strcmp(opt, "-r"))
		return (9);
	else if (!ft_strcmp(opt, "-S"))
		return (10);
	else if (!ft_strcmp(opt, "-s"))
		return (11);
	else if (!ft_strcmp(opt, "-u"))
		return (12);
	else if (!ft_strcmp(opt, "-w"))
		return (13);
	else if (!ft_strcmp(opt, "-x"))
		return (14);
	else if (!ft_strcmp(opt, "-z"))
		return (15);
	else
		return (0);
}

int				ft_check_opt1(char *opt)
{
	if (!ft_strcmp(opt, "-b"))
		return (1);
	else if (!ft_strcmp(opt, "-c"))
		return (2);
	else if (!ft_strcmp(opt, "-d"))
		return (3);
	else if (!ft_strcmp(opt, "-e"))
		return (4);
	else if (!ft_strcmp(opt, "-f"))
		return (5);
	else if (!ft_strcmp(opt, "-g"))
		return (6);
	else if (!ft_strcmp(opt, "-L"))
		return (7);
	else if (!ft_strcmp(opt, "-p"))
		return (8);
	else
		return (ft_check_opt1pt2(opt));
}

int				ft_check_opt2(char *opt)
{
	if (!ft_strcmp(opt, "="))
		return (16);
	else if (!ft_strcmp(opt, "!="))
		return (17);
	else if (!ft_strcmp(opt, "-eq"))
		return (18);
	else if (!ft_strcmp(opt, "-ne"))
		return (19);
	else if (!ft_strcmp(opt, "-ge"))
		return (20);
	else if (!ft_strcmp(opt, "-lt"))
		return (21);
	else if (!ft_strcmp(opt, "-le"))
		return (22);
	else if (!ft_strcmp(opt, "-gt"))
		return (23);
	else
		return (0);
}

static	int		ft_error(int flag, unsigned long long int out, int str)
{
	if ((flag == 1 && (10 * out + (str - '0')) > 9223372036854775807)
	|| (flag == -1 && (10 * out + (str - '0') - 1) > 9223372036854775807))
		return (1);
	return (0);
}

int				ft_error_integer(long long int *nb, char *str)
{
	int						flag;
	unsigned long long int	out;

	flag = 1;
	out = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (ft_error(flag, out, *str))
				return (1);
			out = out * 10 + (*str - '0');
		}
		else
			return (1);
		str++;
	}
	*nb = (long long)out * flag;
	return (0);
}
