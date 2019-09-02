/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cderbegin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:45 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:47:03 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_cdgcsuper(t_masterenv *menv, char **tmp, char **pwd, char **opt)
{
	int i;

	i = (menv->cdopt == 0) ? 1 : 2;
	if (ft_is_logical(pwd[0], tmp, menv, opt))
		;
	else if (pwd[0][0] == '/' && pwd[0][1] == 0)
	{
		if (!(tmp[0] = (char*)malloc(sizeof(char)
			* (ft_strlen(opt[i]) + ft_strlen(pwd[0]) + 1))))
			return (1);
		tmp[0] = ft_strcpy(tmp[0], pwd[0]);
		tmp[0] = ft_strcat(tmp[0], opt[i]);
	}
	else
	{
		if (!(tmp[0] = (char*)malloc(sizeof(char)
			* (ft_strlen(opt[i]) + ft_strlen(pwd[0]) + 2))))
			return (1);
		tmp[0] = ft_strcpy(tmp[0], pwd[0]);
		tmp[0] = ft_strcat(tmp[0], "/");
		tmp[0] = ft_strcat(tmp[0], opt[i]);
	}
	return (0);
}

static int	ft_cdgsupminus(t_masterenv *menv, char **tmp)
{
	if (menv->stock[0][menv->repe[2]])
	{
		if (!(tmp[0] = (char *)malloc(sizeof(char)
			* (ft_strlen(menv->stock[0][menv->repe[2]]) - 6))))
			return (1);
		ft_strcpy(tmp[0], menv->stock[0][menv->repe[2]] + 7);
		if (menv->cdopt == 1)
			ft_printnewpwd(menv, tmp);
	}
	else
	{
		ft_printfd(2, "\e[93mcd\e[0m: OLDPWD missing, write full PATH\n");
		return (1);
	}
	return (0);
}

int			ft_cdgsup_pt2(t_masterenv *menv, char **tmp, char **pwd, char **opt)
{
	int i;

	i = (menv->cdopt == 0) ? 1 : 2;
	if (ft_checktmp(pwd, menv, opt, i))
		;
	else if (ft_checkcdpath(pwd, menv, opt, i))
		;
	else if (!(pwd[0] = getcwd(NULL, 0)))
	{
		ft_printfd(2, "\e[93mcd\e[0m: you are lost, write full PATH\n");
		return (1);
	}
	if (ft_cdgcsuper(menv, tmp, pwd, opt))
		return (1);
	free(pwd[0]);
	return (0);
}

int			ft_cdgcsup(t_masterenv *menv, char **tmp, char **pwd, char **opt)
{
	int i;

	i = (menv->cdopt == 0) ? 1 : 2;
	if (menv->cdopt == 1)
	{
		if (ft_cdgsupminus(menv, tmp))
			return (1);
	}
	else if (opt[i][0] == '/')
	{
		if (!(tmp[0] = (char*)malloc(sizeof(char)
			* (ft_strlen(opt[i]) + 1))))
			return (1);
		tmp[0] = ft_strcpy(tmp[0], opt[i]);
	}
	else
	{
		if (ft_cdgsup_pt2(menv, tmp, pwd, opt))
			return (1);
	}
	return (0);
}

int			ft_cdgcequal1(t_masterenv *menv, char **tmp)
{
	if (menv->stock[0][menv->repe[3]])
	{
		if (!(tmp[0] = (char*)malloc(sizeof(char)
			* (ft_strlen(menv->stock[0][menv->repe[3]]) - 4))))
			return (1);
		tmp[0] = ft_strcpy(tmp[0], menv->stock[0][menv->repe[3]] + 5);
	}
	else
	{
		ft_printfd(2, "\e[93mcd\e[0m: $HOME missing, write full PATH\n");
		return (1);
	}
	return (0);
}
