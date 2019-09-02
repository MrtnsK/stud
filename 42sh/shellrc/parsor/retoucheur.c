/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retoucheur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:36:32 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:25:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_abspt1(char **toretouch, int i)
{
	if (toretouch[0][i + 2] && toretouch[0][i + 2] == 'a')
		toretouch[0][i] = '\a';
	else if (toretouch[0][i + 2] && toretouch[0][i + 2] == 'b')
		toretouch[0][i] = '\b';
	else if (toretouch[0][i + 2] && toretouch[0][i + 2] == 'e')
		toretouch[0][i] = '\e';
	else if (toretouch[0][i + 2] && toretouch[0][i + 2] == 'f')
		toretouch[0][i] = '\f';
	else if (toretouch[0][i + 2] && toretouch[0][i + 2] == 'n')
		toretouch[0][i] = '\n';
	else if (toretouch[0][i + 2] && toretouch[0][i + 2] == 'r')
		toretouch[0][i] = '\r';
	else if (toretouch[0][i + 2] && toretouch[0][i + 2] == 't')
		toretouch[0][i] = '\t';
	else if (toretouch[0][i + 2] && toretouch[0][i + 2] == 'v')
		toretouch[0][i] = '\v';
	else if (toretouch[0][i + 2] && toretouch[0][i + 2] >= '0'
		&& toretouch[0][i + 2] <= '7')
		toretouch[0][i] = toretouch[0][i + 2] - '0';
	else
		return (0);
	return (1);
}

static void	ft_addbackslash(char **toretouch, int i)
{
	int flag;

	flag = 1;
	if (ft_abspt1(toretouch, i))
		;
	else
	{
		toretouch[0][i] = '\\';
		flag = 0;
	}
	toretouch[0][i + 1] = 0;
	if (flag)
		ft_strcat(toretouch[0], toretouch[0] + i + 3);
	else
		ft_strcat(toretouch[0], toretouch[0] + i + 2);
}

int			ft_switcher(char **toretouch, int i, t_masterenv *menv)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(toretouch[0])
		+ ft_strlen(menv->internal_var[0][menv->rep[3]]) - 5))))
		return (1);
	tmp[0] = 0;
	tmp = ft_strncat(tmp, toretouch[0], i);
	tmp = ft_strcat(tmp, menv->internal_var[0][menv->rep[3]] + 5);
	tmp = ft_strcat(tmp, toretouch[0] + i + 1);
	free(toretouch[0]);
	if (!(toretouch[0] = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
		return (1);
	toretouch[0][0] = 0;
	ft_strcat(toretouch[0], tmp);
	free(tmp);
	return (0);
}

int			ft_retoucheurcore(char **toretouch, t_masterenv *menv, int i)
{
	if (toretouch[0][i] == '\\' && toretouch[0][i + 1] == '\\')
		ft_addbackslash(toretouch, i);
	else if (toretouch[0][i] == '\\' && toretouch[0][i + 1] != '\\'
		&& toretouch[0][i + 1] != '~')
	{
		toretouch[0][i] = 0;
		ft_strcat(toretouch[0], toretouch[0] + i + 1);
	}
	if (toretouch[0][i] == '~' && menv->internal_var[0][menv->rep[3]] && (i == 0
		|| (toretouch[0][i - 1] && toretouch[0][i - 1] == ' ')))
		if (ft_switcher(toretouch, i, menv))
			return (1);
	return (0)	;
}

int			ft_retoucheur(char **toretouch, t_masterenv *menv)
{
	int		i;

	i = -1;
	if (toretouch[0] == 0)
		return (0);
	if (!ft_simple_dollar(menv, toretouch))
		return (1);
	if (!ft_dollar_expansion(menv, toretouch))
		return (1);
	if (ft_calculator(toretouch, menv))
		return (1);
	while (toretouch[0][++i])
		if (ft_retoucheurcore(toretouch, menv, i))
			return (1);
	return (0);
}
