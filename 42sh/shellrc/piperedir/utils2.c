/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:29:08 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/19 14:10:44 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static	int		ft_builtin_pt4(t_masterenv *tenv, char **opt)
{
	if (!ft_strcmp(opt[0], "alias"))
	{
		if ((tenv->nruter = add_alias(tenv, opt)))
			return (-3);
		return (0);
	}
	else if (!ft_strcmp(opt[0], "unalias"))
	{
		if ((tenv->nruter = unalias(&tenv, opt)))
			return (-3);
		return (0);
	}
	else if (!ft_strcmp(opt[0], "fc"))
	{
		if ((tenv->nruter = ft_dofc(tenv, &g_lock, opt)))
			return (-3);
		return (0);
	}
	return (-2);
}

static	int		ft_builtin_pt3(t_masterenv *tenv, char **opt)
{
	if (!ft_strcmp(opt[0], "bg"))
	{
		if ((tenv->nruter = ft_bg(tenv, opt)))
			return (-3);
		return (0);
	}
	else if (!ft_strcmp(opt[0], "test") || (!ft_strcmp(opt[0], "[")
	&& opt[1] && ft_strcmp(opt[1], "]")))
	{
		if (ft_tester(tenv, opt))
			return (-3);
		return (0);
	}
	return (ft_builtin_pt4(tenv, opt));
}

static	int		ft_builtin_pt2(t_masterenv *tenv, char **opt)
{
	if (!ft_strcmp(opt[0], "cd"))
	{
		if ((tenv->nruter = ft_cd(tenv, opt)))
			return (-3);
		return (tenv->nruter);
	}
	else if (!ft_strcmp(opt[0], "set"))
	{
		if (ft_set(*tenv->internal_var))
			return (-3);
		return (0);
	}
	else if (!ft_strcmp(opt[0], "jobs"))
	{
		if ((tenv->nruter = ft_jobs(tenv, opt)))
			return (-3);
		return (0);
	}
	else if (!ft_strcmp(opt[0], "fg"))
	{
		if ((ft_fg(tenv, opt)))
			return (-3);
		return (tenv->nruter);
	}
	return (ft_builtin_pt3(tenv, opt));
}

int				ft_builtin(t_masterenv *tenv, char **opt)
{
	int	k;

	if (!ft_strcmp(opt[0], "echo"))
		return (ft_echo(tenv, opt));
	else if (!ft_strcmp(opt[0], "type"))
		return (ft_typer(tenv, opt));
	else if (!ft_strcmp(opt[0], "unset"))
	{
		ft_unsetenv(tenv, opt);
		return (tenv->nruter = ft_unset(tenv->internal_var, &opt[1], 0));
	}
	else if (!ft_strcmp(opt[0], "export"))
		return ((tenv->nruter = ft_export(tenv, &opt[1])));
	else if (!ft_strcmp(opt[0], "exit"))
		return (ft_exiter(tenv, opt, &g_lock));
	else if ((k = ft_builtin_pt2(tenv, opt)) == -3)
		return (1);
	else if (k == 0)
		return (0);
	else if (k)
		return (k);
	return (-2);
}

int				ft_savefdb(int *fd)
{
	struct stat		st;
	int				i;

	i = -1;
	while (++i < 3)
		fd[i] = i + 10;
	i = -1;
	while (fd[++i])
	{
		if (fstat(i, &st))
			return (1);
		if (dup2(i, fd[i]) == -1)
			return (1);
	}
	return (0);
}
