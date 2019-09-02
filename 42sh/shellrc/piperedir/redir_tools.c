/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:42:51 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/18 09:39:01 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_job	*ft_init_redir(int *fd_agregin, int *fd_b, t_masterenv *menv)
{
	t_job	*new_j;
	int		i;

	i = -1;
	*fd_agregin = -1;
	*fd_b = -1;
	while (menv->cgv[++i] && menv->cgprio[i] == 8)
		;
	if (menv->cgv[i] && !ft_notbltin(menv->cgv[i]))
	{
		ft_exec_builtin_redir(menv);
		return (NULL);
	}
	if (!(new_j = new_job()))
		return (NULL);
	if (!(new_j->fst_process = new_process()))
		return (NULL);
	return (new_j);
}

int		ft_init_pipe(int *start, int *i, int *fdd, t_masterenv *tenv)
{
	int		ind;

	*fdd = 0;
	*i = -1;
	ind = ft_getnextpipe(tenv, *i);
	*start = -1;
	return (ind);
}

int		ft_process_pipe(t_masterenv *tenv, t_job *cur_j, int start, int *pipefd)
{
	process_info(tenv, cur_j, g_pid, start);
	ft_supvar(tenv, start);
	close(pipefd[1]);
	return (pipefd[0]);
}

int		ft_pipe_error(t_job *cur_j, int *i, int *pipefd, int k)
{
	if (k && pipe(pipefd) != 0)
		return (error_job(cur_j, "\e[93mMastershell\e[0m: pipe error\n"));
	if (!(cur_j->fst_process = new_process()))
		return (error_job(cur_j, "\e[93mMastershell\e[0m: pipe error\n"));
	if ((g_pid = fork()) == -1)
		return (error_job(cur_j, "\e[93mMastershell\e[0m: fork error\n"));
	if (!k)
		*i -= 1;
	return (1);
}

int		ft_get_next(int *start, int *ind, t_masterenv *tenv)
{
	if (*ind == tenv->cgc)
		return (1);
	*start = *ind;
	*ind = ft_getnextpipe(tenv, *ind);
	return (0);
}
