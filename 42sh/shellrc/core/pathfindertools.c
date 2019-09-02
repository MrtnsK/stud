/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfindertools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:35:28 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:25:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_findfcter(t_masterenv *menv, char **tmp, t_fcter *fcter,
char *cmd)
{
	int j;

	j = fcter->i;
	fcter->i += 1;
	while (menv->internal_var[0][menv->rep[4]][fcter->i] != ':'
		&& menv->internal_var[0][menv->rep[4]][fcter->i])
		fcter->i += 1;
	if (!(tmp[0] = (char*)malloc(sizeof(char) *
		(ft_strlen(cmd) + fcter->i - j + 2))))
		return (1);
	if (menv->internal_var[0][menv->rep[4]][fcter->i])
		fcter->stop = 1;
	else
		fcter->stop = 0;
	menv->internal_var[0][menv->rep[4]][fcter->i] = 0;
	ft_strcpy(tmp[0], menv->internal_var[0][menv->rep[4]] + j);
	if (fcter->stop)
		menv->internal_var[0][menv->rep[4]][fcter->i] = ':';
	ft_strcat(tmp[0], "/");
	ft_strcat(tmp[0], cmd);
	if (is_file(tmp[0]) && !is_dir(tmp[0]))
		fcter->stop = 0;
	return (0);
}

int			ft_findfct(t_masterenv *menv, char **tmp, char *cmd)
{
	int		j;
	t_fcter	fcter;

	fcter.i = -1;
	while (menv->internal_var[0][menv->rep[4]][++(fcter.i)] != '=')
		fcter.stop = 1;
	j = fcter.i;
	while (fcter.stop && menv->internal_var[0][menv->rep[4]][++(fcter.i)])
	{
		if (ft_findfcter(menv, tmp, &fcter, cmd))
			return (1);
		if (fcter.stop)
			ft_findfctscript(tmp);
	}
	if (j == fcter.i - 1)
	{
		tmp[0] = NULL;
		return (0);
	}
	if (!tmp[0] || (is_file(tmp[0]) && !is_dir(tmp[0])))
		return (0);
	ft_findfctscript(tmp);
	return (0);
}
