/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:13:27 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 14:41:45 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_execr(t_masterenv *menv, char **opt)
{
	int		k;
	char	*cmd;

	if (!(k = ft_builtin(menv, opt)) || k == -1)
		menv->nruter = k;
	else if (k == -2)
	{
		if (ft_findpathperm(menv, &cmd, opt[0]))
			return (1);
		else
		{
			execve(cmd, opt, menv->stock[0]);
			if (cmd)
			{
				ft_printfd(2, "\e[93mMastershell\e[0m:");
				ft_printfd(2, " %s : Permission denied\n", cmd);
			}
		}
		free(cmd);
	}
	return (0);
}

void		ft_redir_exec(t_masterenv *menv, int k)
{
	int		i;
	char	**opt;
	char	*tmp;

	while (menv->cgprio[++k] == 8)
		ft_addvar(menv->stock, ft_strdup(menv->cgv[k]));
	i = --k;
	tmp = ft_opt_cmd(k, i, menv);
	if (tmp == NULL || tmp[0] == '\0')
		exit(0);
	opt = ft_strsplit(tmp, 7);
	free(tmp);
	ft_execr(menv, opt);
	ft_freetabc(opt);
}

int			ft_agreg(t_masterenv *tenv, int j, int *fd_agregin, int *fd_b)
{
	int	fd;
	int	k;

	fd = ft_recupfd(tenv, j);
	k = -1;
	if (!tenv->cgv[j + 1])
		return (ft_check_agregin(tenv, j));
	if (ft_strcmp(tenv->cgv[j + 1], "-") == 0)
	{
		if (ft_checkfderror(fd))
			return (1);
		*fd_agregin = fd;
		*fd_b = dup(fd);
		close(fd);
	}
	else
	{
		if (ft_check_agregin(tenv, j))
			return (1);
		*fd_agregin = ft_atoi(tenv->cgv[j + 1]);
		if (ft_checkfderror(*fd_agregin))
			return (1);
		dup2(*fd_agregin, fd);
	}
	return (0);
}

int			ft_check(t_masterenv *tenv, int *fd_agregin, int *fd_b)
{
	int i;
	int j;

	i = -1;
	while (tenv->cgv[++i])
	{
		if (ft_checkredirerror(tenv, i, *fd_agregin))
			return (1);
		else if ((j = ft_checkagreg(tenv, i)))
		{
			if (ft_agreg(tenv, j, fd_agregin, fd_b))
				return (1);
		}
	}
	return (0);
}

int			ft_redir(t_masterenv *menv)
{
	int		fd_agregin;
	int		fd_b;
	t_job	*new_j;

	if (!(new_j = ft_init_redir(&fd_agregin, &fd_b, menv)))
		return (0);
	if ((g_pid = fork()) == -1)
		return (-1);
	if (g_pid == 0)
	{
		launch_process(new_j, menv, menv->fg);
		if (ft_check(menv, &fd_agregin, &fd_b))
			exit(REDIR_ERR);
		ft_redir_exec(menv, -1);
		exit((menv->nruter) ? menv->nruter : 0);
	}
	else
	{
		process_info(menv, new_j, g_pid, -1);
		if (ft_restablish(fd_b, fd_agregin))
			return (1);
		ft_supvar(menv, -1);
	}
	back_fore(menv, new_j, menv->fg);
	return (0);
}
