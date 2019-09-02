/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:46:13 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/18 17:34:16 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static	int	ft_export_cd(t_masterenv *tenv, int c)
{
	char	**pw;
	int		size;

	size = (c < 3) ? 1 : 2;
	if (!(pw = (char **)malloc(sizeof(char *) * (size + 1))))
		return (-1);
	pw[size] = 0;
	if (c < 3)
	{
		if (!(pw[0] = (c == 1) ? ft_strdup("PWD") : ft_strdup("OLDPWD")))
			return (-1);
	}
	else
	{
		if (!(pw[0] = ft_strdup("PWD")))
			return (-1);
		if (!(pw[1] = ft_strdup("OLDPWD")))
		{
			free(pw[0]);
			return (-1);
		}
	}
	ft_export(tenv, pw);
	ft_freetabc(pw);
	return (0);
}

void		ft_supvar(t_masterenv *tenv, int start)
{
	char	**var_sup;
	int		lim;
	int		c;

	c = 0;
	if (!(lim = ft_supvarinit(tenv, start)))
		return ;
	var_sup = ft_supvarcre(tenv, lim, -1, -1);
	ft_unset(tenv->stock, var_sup, 0);
	lim = -1;
	while (var_sup[++lim])
	{
		if (!ft_strcmp(var_sup[lim], "PWD"))
			c = (c == 2) ? 3 : 1;
		else if (!ft_strcmp(var_sup[lim], "OLDPWD"))
			c = (c == 1) ? 3 : 2;
	}
	if (c)
		ft_export_cd(tenv, c);
	ft_freetabc(var_sup);
	ft_inirep(tenv, 0);
}

int			ft_check_exit(t_masterenv *tenv)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (tenv->cgprio[++i] == 8)
		;
	if (tenv->cgprio[i] == 10)
	{
		if (ft_strcmp(tenv->cgv[i], "exit") == 0)
		{
			while (tenv->cgprio[++i] == 0)
				c++;
			if (c == 1 || c == 0)
			{
				if (tenv->nruter == 127 && c == 1
				&& ft_strcmp(tenv->cgv[i - 1], "127") == 0)
					return (1);
				else if (tenv->nruter == 127)
					return (0);
				return (1);
			}
		}
	}
	return (0);
}

int			ft_exec_simple(t_masterenv *menv, char **opt)
{
	int		k;
	char	*cmd;

	if (!(k = ft_builtin(menv, opt)))
		menv->nruter = k;
	else if (k == -2)
	{
		if (ft_findpathperm(menv, &cmd, opt[0]))
			return (1);
		else
			launch_job(menv->fg, cmd, menv, opt);
	}
	return (0);
}

int			ft_exitn(char *opt, t_masterenv *menv)
{
	int		i;

	i = 0;
	if (opt[i] != '-' && !ft_isdigit(opt[i]))
	{
		ft_printfd(2,
		"\e[93mMastershell\e[0m: exit: %s: numeric argument required\n", opt);
		menv->nruter = 255;
		return (1);
	}
	else
	{
		while (opt[++i])
		{
			if (!ft_isdigit(opt[i]))
			{
				ft_printfd(2, "\e[93mMastershell\e[0m: exit: ");
				ft_printfd(2, "%s: numeric argument required\n", opt);
				menv->nruter = 255;
				return (1);
			}
		}
	}
	return (0);
}
