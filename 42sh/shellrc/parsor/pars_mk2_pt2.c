/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mk2_pt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:04:11 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/17 14:10:31 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_findparserror_v2(t_masterenv *menv, char **buf)
{
	int		i;

	i = 0;
	if (menv->cgc == 0)
		return (ft_prio(menv, buf));
	while (menv->cgv[++i])
	{
		if (menv->cgtype[i] > 10 && menv->cgtype[i] < 20)
		{
			if (menv->cgtype[i - 1] > 10 && menv->cgtype[i - 1] < 20)
				return (ft_errorpars_mk2(menv, buf));
		}
		if (menv->cgtype[i] == 12 && !menv->cgv[i + 1])
			return (ft_errorpars_mk2(menv, buf));
	}
	return (ft_prio(menv, buf));
}

int			ft_checkintvar(char *lol)
{
	int i;

	i = -1;
	if (ft_isdigit(lol[0]) || lol[0] == '=')
		return (0);
	while (lol[++i])
	{
		if (lol[i] == '=')
			return (1);
		if (!ft_isalnum(lol[i]) && lol[i] != '_')
			return (0);
	}
	return (0);
}

int			ft_pars_mk2(t_masterenv *menv, char **buf)
{
	int		i;

	i = -1;
	while (menv->cgv[++i])
	{
		if (i > 0 && menv->cgtype[i - 1] > 20)
			menv->cgtype[i] = 2;
		if (i == 0 || (menv->cgtype[i - 1] < 20 && menv->cgtype[i - 1] > 10))
			menv->cgtype[i] = 1;
		if (ft_checkintvar(menv->cgv[i]))
			menv->cgtype[i] = 8;
		if (!ft_strcmp(menv->cgv[i], "|"))
			menv->cgtype[i] = 12;
		if (menv->cgtype[i] != 9 && menv->cgtype[i] != 8)
			if (ft_pars_mk2_helper(menv, i, buf))
				return (1);
	}
	return (ft_findparserror_v2(menv, buf));
}

int			ft_seter(int *i, char **buf, char multi)
{
	int		j[4];

	j[2] = 0;
	j[3] = 0;
	j[1] = *i - 1;
	if (j[1] != -1 && !ft_isspace(buf[0][j[1]])
		&& ((!ft_isdigit(buf[0][j[1]]) || (multi != '>' && multi != '<'))))
		j[2] = 1;
	else if (j[1] != -1 && ft_isdigit(buf[0][j[1]])
		&& (multi == '>' || multi == '<'))
	{
		while (j[1] >= 0 && ft_isdigit(buf[0][j[1]]))
			j[1]--;
		if (!ft_isspace(buf[0][j[1]]))
		{
			j[2] = 1;
			j[1] = *i - 1;
		}
	}
	return (seter_if(i, j, buf, multi));
}

int			ft_ultimain_mk2(char **buf)
{
	int		i;
	int		quoters;

	i = -1;
	quoters = 0;
	while (buf[0][++i])
	{
		if (buf[0][i] == '"' && (i == 0 || buf[0][i - 1] != '\\')
			&& quoters != 2)
			ft_quoters(&quoters, 1);
		if (buf[0][i] == '\'' && (i == 0 || buf[0][i - 1] != '\\')
			&& quoters != 1)
			ft_quoters(&quoters, 2);
		if ((buf[0][i] == '|' || buf[0][i] == '<' || buf[0][i] == '>'
			|| buf[0][i] == '&') && !quoters)
		{
			if (ft_seter(&i, buf, buf[0][i]))
				return (1);
		}
	}
	return (0);
}
