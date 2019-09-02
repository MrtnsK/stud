/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prelauncher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:38:03 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 11:00:49 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			*ft_opt_cmd(int k, int i, t_masterenv *menv)
{
	char	*cmd;
	char	*tmp;
	char	c;
	char	sp[2];

	c = 7;
	sp[0] = c;
	sp[1] = '\0';
	while (menv->cgv[++k] && (menv->cgprio[k] == 10
	|| menv->cgprio[k] == 9 || menv->cgprio[k] == 0))
	{
		if (k == i + 1)
			tmp = ft_strdup(menv->cgv[k]);
		else
		{
			cmd = ft_strjoin(tmp, sp);
			free(tmp);
			tmp = ft_strjoin(cmd, menv->cgv[k]);
			free(cmd);
		}
	}
	return (tmp);
}

void			ft_simple(t_masterenv *menv)
{
	int			i;
	int			k;
	char		*tmp;
	char		**opt;

	k = -1;
	while (menv->cgprio[++k] == 8)
		ft_addvar(menv->stock, ft_strdup(menv->cgv[k]));
	i = --k;
	tmp = ft_opt_cmd(k, i, menv);
	opt = ft_strsplit(tmp, 7);
	free(tmp);
	ft_exec_simple(menv, opt);
	ft_supvar(menv, -1);
	ft_freetabc(opt);
}

int				ft_checkbg(t_masterenv *tenv)
{
	int	i;

	i = -1;
	tenv->fg = 1;
	while (tenv->cgv[++i])
		if (tenv->cgprio[i] == 9)
			return (1);
	return (0);
}

int				ft_launcher_mk2(t_keymaster *lock,
t_masterenv *menv)
{
	int i;

	i = -1;
	menv->nruter = 0;
	menv->pipe = 0;
	if (ft_checkcreate(menv))
		return (menv->nruter = 1);
	if (ft_checkbg(menv))
	{
		if (ft_execute_bg(lock, menv))
			menv->fg = 0;
		else
			return (0);
	}
	if (ft_checkpipe(menv, menv->cgc))
		ft_pipe_exec(i, menv);
	else if (ft_checkredir(menv, i, menv->cgc))
		ft_redir(menv);
	else
		ft_simple(menv);
	return (0);
}

int				ft_prelauncher(char **buf, t_masterenv *menv, t_keymaster *lock)
{
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	if (ft_check_final(menv, buf))
		return (0);
	if ((j = ft_add_to_intern_var(menv, i)) >= 0)
		i = j;
	else if (menv->cgv[i] && ft_strcmp(menv->cgv[i], "\0"))
		ft_launcher_mk2(lock, menv);
	tmp = ft_itoa(menv->nruter);
	ft_addvar(menv->internal_var, setvar("?", tmp));
	free(tmp);
	i = -1;
	while (menv->stock[0][++i])
	{
		if (!(tmp = ft_strdup(menv->stock[0][i])))
			return (1);
		ft_addvar(menv->internal_var, tmp);
	}
	ft_inirep(menv, 0);
	ft_freear(menv, buf[0]);
	return (0);
}
