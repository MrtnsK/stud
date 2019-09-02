/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cder.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:33 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:46:36 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_cd2op(t_masterenv *menv, char **tmp)
{
	free(menv->stock[0][menv->repe[2]]);
	if (!(menv->stock[0][menv->repe[2]] = (char*)malloc(sizeof(char)
		* (ft_strlen(menv->stock[0][menv->repe[1]]) + 4))))
	{
		free(tmp[0]);
		return (1);
	}
	menv->stock[0][menv->repe[2]][0] = 0;
	ft_strcat(menv->stock[0][menv->repe[2]], "OLD");
	ft_strcat(menv->stock[0][menv->repe[2]], menv->stock[0][menv->repe[1]]);
	free(menv->stock[0][menv->repe[1]]);
	chdir(tmp[0]);
	return (ft_cd2op_pt2(menv, tmp[0]));
}

static int	ft_cdoldop(t_masterenv *menv, char **tmp, char **pwd)
{
	if (!(pwd[0] = getcwd(NULL, 0)))
	{
		free(tmp[0]);
		return (1);
	}
	free(menv->stock[0][menv->repe[2]]);
	if (!(menv->stock[0][menv->repe[2]] = (char*)malloc(sizeof(char)
		* (ft_strlen(pwd[0]) + 8))))
	{
		free(tmp[0]);
		return (1);
	}
	menv->stock[0][menv->repe[2]][0] = 0;
	ft_strcat(menv->stock[0][menv->repe[2]], "OLDPWD=");
	ft_strcat(menv->stock[0][menv->repe[2]], pwd[0]);
	free(pwd[0]);
	chdir(tmp[0]);
	free(tmp[0]);
	return (0);
}

static int	ft_cdpwdop(t_masterenv *menv, char **tmp)
{
	chdir(tmp[0]);
	return (ft_cd2op_pt2(menv, tmp[0]));
}

static int	ft_cdbeginner(t_masterenv *menv, char **tmp, char **pwd, char **opt)
{
	if (ft_getopt(opt, menv))
		return (1);
	if ((ft_tablen(opt) == 2 && menv->cdopt < 2) ||
	((menv->cdopt == 2 || menv->cdopt == 3) && ft_tablen(opt) == 3)
	|| menv->cdopt == 1)
	{
		if (ft_cdgcsup(menv, tmp, pwd, opt))
			return (1);
	}
	else if (ft_tablen(opt) == 1 || (menv->cdopt > 1 && ft_tablen(opt) == 2))
	{
		if (ft_cdgcequal1(menv, tmp))
			return (1);
	}
	else
	{
		ft_printfd(2, "\e[93mcd\e[0m: too many arguments\n");
		return (1);
	}
	return (0);
}

int			ft_cd(t_masterenv *menv, char **opt)
{
	char	*tmp;
	char	*pwd;

	menv->cdpath = 0;
	if (ft_cdbeginner(menv, &tmp, &pwd, opt) || ft_cdchecker(&tmp))
		return (1);
	if (menv->stock[0][menv->repe[2]] && menv->stock[0][menv->repe[1]])
	{
		if (ft_cd2op(menv, &tmp))
			return (1);
	}
	else if (menv->stock[0][menv->repe[2]] && !menv->stock[0][menv->repe[1]])
	{
		if (ft_cdoldop(menv, &tmp, &pwd))
			return (1);
	}
	else if (!menv->stock[0][menv->repe[2]] && menv->stock[0][menv->repe[1]])
	{
		if (ft_cdpwdop(menv, &tmp))
			return (1);
	}
	else
		ft_microcd(&tmp);
	ft_inirep(menv, 0);
	return (0);
}
