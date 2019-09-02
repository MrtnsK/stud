/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:26:19 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 14:12:17 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_getitright(char **toretouch, int k, int j, t_masterenv *menv)
{
	char	*tmp;
	int		l;

	l = -1;
	while (menv->stock[0][k][++l] != '=')
		;
	if (!(tmp = (char*)malloc(sizeof(char) *
		(ft_strlen(toretouch[0]) + ft_strlen(toretouch[0] + j)
			+ ft_strlen(menv->stock[0][k] + l)))))
		return (1);
	ft_strcpy(tmp, toretouch[0]);
	ft_strcat(tmp, menv->stock[0][k] + l + 1);
	ft_strcat(tmp, toretouch[0] + j);
	free(toretouch[0]);
	if (!(toretouch[0] = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
	{
		free(tmp);
		return (1);
	}
	ft_strcpy(toretouch[0], tmp);
	free(tmp);
	return (0);
}

static int	ft_getitend(char **toretouch, int k, int j, t_masterenv *menv)
{
	if (menv->stock[0][k])
	{
		if (ft_getitright(toretouch, k, j, menv))
			return (1);
	}
	else
		ft_strcator(toretouch[0], toretouch[0] + j);
	return (0);
}

int			ft_getit(char **toretouch, int i, t_masterenv *menv)
{
	char	*tmp;
	int		j;
	int		k;
	int		b;

	j = i;
	while (!ft_isspace(toretouch[0][++j]) && toretouch[0][j]
		&& toretouch[0][j] != '/' && toretouch[0][j] != ':'
		&& toretouch[0][j] != ';' && toretouch[0][j] != '|')
		;
	if (j == i + 1)
		return (0);
	b = (toretouch[0][j] == '/' && toretouch[0][j] == ';'
		&& toretouch[0][j] == '|') ? 1 : 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (j - i - b))))
		return (1);
	tmp[j - i - b - 1] = 0;
	ft_strncpy(tmp, toretouch[0] + i + 1, j - i - b - 1);
	k = -1;
	while (menv->stock[0][++k])
		if (ft_strcmp(tmp, menv->stock[0][k]) == -61)
			break ;
	toretouch[0][i] = 0;
	free(tmp);
	return (ft_getitend(toretouch, k, j, menv) ? 1 : 0);
}
