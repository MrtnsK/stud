/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mk2_pt4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:05:48 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/01 12:17:11 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_pars_mk2_helper(t_masterenv *menv, int i, char **buf)
{
	if ((ft_strcpt(menv->cgv[i], '>') > 2)
	|| (ft_strcpt(menv->cgv[i], '|') > 1)
	|| (ft_strcpt(menv->cgv[i], '<') > 3)
	|| (ft_strcpt(menv->cgv[i], '&') > 1)
	|| (ft_strcpt(menv->cgv[i], '>') == 2 && ft_strrchr(menv->cgv[i], '&')))
		return (ft_errorpars_mk2(menv, buf));
	if (ft_strrchr(menv->cgv[i], '<'))
		menv->cgtype[i] = 21;
	if (ft_strrchr(menv->cgv[i], '>'))
		menv->cgtype[i] = 25;
	if (menv->cgtype[i] > 20 && ft_findparserror(menv->cgv[i]))
		return (ft_errorpars_mk2(menv, buf));
	return (0);
}

int			ft_if_prio_pt2(t_masterenv *menv, int i, char **buf)
{
	if (menv->cgtype[i] > 20)
	{
		if (menv->cgtype[i + 1] != 2 && !ft_strrchr(menv->cgv[i], '&'))
		{
			ft_printfd(2,\
			"Mastershell: syntax error near unexpected token `newline'\n");
			free(buf[0]);
			menv->nruter = 1;
			return (1);
		}
		menv->cgprio[i] = menv->cgtype[i];
	}
	return (0);
}

int			ft_if_prio(t_masterenv *menv, int i, int nope, char **buf)
{
	if (menv->cgtype[i] == 1)
	{
		menv->cgprio[i] = 1;
		menv->neight = 0;
	}
	if (menv->cgtype[i] == 8 && menv->neight)
		menv->cgprio[i] = 8;
	if (menv->cgtype[i] == 8 && !menv->neight)
		menv->cgtype[i] = 0;
	if (menv->cgtype[i] == 0 && menv->neight)
	{
		menv->neight = 0;
		menv->cgtype[i] = 1;
		menv->cgprio[i] = 1;
	}
	if (menv->cgtype[i] == 1 && nope)
		menv->cgprio[i] = menv->valfct;
	if (menv->cgtype[i] == 2)
		menv->cgprio[i] = menv->cgtype[i];
	return (ft_if_prio_pt2(menv, i, buf));
}

int			seter_following(int *i, int j[4], char **buf, char multishlag[10])
{
	char	*tmp;

	ft_memset(multishlag, 0, 10);
	ft_strncpy(multishlag, buf[0] + j[1] + 1, j[0] - j[1] - 1);
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(buf[0]) + 1))))
		return (1);
	ft_strcpy(tmp, buf[0]);
	free(buf[0]);
	if (!(buf[0] = (char*)malloc(sizeof(char)
		* (ft_strlen(tmp) + 1 + j[2] + j[3]))))
		return (1);
	ft_strncpy(buf[0], tmp, j[1] + 1);
	buf[0][j[1] + 1] = 0;
	if (j[2])
		ft_strcat(buf[0], " ");
	ft_strcat(buf[0], multishlag);
	if (j[3])
		ft_strcat(buf[0], " ");
	ft_strcat(buf[0], tmp + (j[0]));
	free(tmp);
	*i = j[0] + j[2] + j[3] - 1;
	return (0);
}

int			seter_if(int *i, int j[4], char **buf, char multi)
{
	char	multishlag[10];

	j[0] = *i;
	while (buf[0][j[0]] == multi || buf[0][j[0]] == '&')
		j[0]++;
	if (buf[0][j[0]] && !ft_isspace(buf[0][j[0]]))
		j[3] = 1;
	if (!j[3] && !j[2])
	{
		*i = j[0];
		return (0);
	}
	return (seter_following(i, j, buf, multishlag));
}
