/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipetools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:29:00 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 14:50:24 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_checkpipe(t_masterenv *menv, int i)
{
	int j;

	j = -1;
	while (++j < i)
	{
		if (ft_strcmp(menv->cgv[j], "|") == 0)
			return (j);
	}
	return (0);
}

int		ft_getnextpipe(t_masterenv *menv, int ind)
{
	int j;

	j = ind;
	while (menv->cgv[++j])
	{
		if (ft_strcmp(menv->cgv[j], "|") == 0)
			return (j);
	}
	return (j);
}

void	ft_dup(int *fdd, int *pipefd, int fd)
{
	dup2(*fdd, 0);
	if (fd)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
	}
	else
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
	}
}

int		ft_exec(t_masterenv *menv, char **opt)
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

void	ft_executor_pipe(int start, int end, t_masterenv *menv)
{
	int		k;
	char	*tmp;
	char	**redir;

	k = start;
	while (menv->cgprio[++k] == 8)
		ft_addvar(menv->stock, ft_strdup(menv->cgv[k]));
	start = --k;
	tmp = ft_opt_pipe(k, start, menv, end);
	if (tmp == NULL || tmp[0] == '\0')
		exit(0);
	redir = ft_strsplit(tmp, 7);
	free(tmp);
	ft_exec(menv, redir);
	ft_freetabc(redir);
}
