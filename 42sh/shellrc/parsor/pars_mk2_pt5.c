/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mk2_pt5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:03:48 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/20 14:52:24 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_findparserror(char *check)
{
	int i;

	i = -1;
	if (ft_strrchr(check, '>') || ft_strrchr(check, '<'))
	{
		while (check[++i])
			;
		if (ft_isdigit(check[--i]) && (ft_strrchr(check, '<')
			|| (ft_strrchr(check, '>') && !ft_strrchr(check, '&'))))
			return (1);
	}
	else
	{
		if (ft_strrdigit(check))
			return (1);
		if (ft_strrchr(check, '&'))
			return (1);
	}
	return (0);
}

static int	ft_piperror_core(t_masterenv *menv, char **buf, int j)
{
	int test;

	test = 0;
	while (--j > 0 && menv->cgprio[j] != 12)
		if (menv->cgprio[j] == 8 || menv->cgprio[j] == 9
			|| menv->cgprio[j] == 10 || menv->cgprio[j] == 1)
			test = 1;
	if (menv->cgprio[j] == 8 || menv->cgprio[j] == 9
		|| menv->cgprio[j] == 10 || menv->cgprio[j] == 1)
		test = 1;
	if (!test)
	{
		ft_printfd(2, "parse error\n");
		ft_freetabc(menv->cgv);
		free(buf[0]);
		free(menv->cgprio);
		free(menv->cgtype);
		return (1);
	}
	return (0);
}

int			ft_piperror(t_masterenv *menv, char **buf)
{
	int i;

	i = -1;
	while (menv->cgv[++i])
	{
		if (menv->cgprio[i] > 10)
		{
			if (ft_piperror_core(menv, buf, i))
				return (1);
		}
	}
	return (0);
}
