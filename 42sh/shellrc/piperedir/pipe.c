/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:03:35 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/18 09:42:49 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static	int		ft_redir_execp(int start, int end, t_masterenv *menv)
{
	int		j;
	int		fd_agregin;
	int		fd_b;
	int		a;

	a = start;
	fd_agregin = -1;
	while (++a < end)
	{
		if (ft_checkredirerror(menv, a, fd_agregin))
			exit(1);
		else if ((j = ft_checkagreg(menv, a)))
		{
			if (ft_agreg(menv, j, &fd_agregin, &fd_b))
				exit(1);
		}
	}
	ft_executor_pipe(start, end, menv);
	if (fd_agregin != -1)
		dup2(fd_b, fd_agregin);
	return (0);
}

static	void	ft_execp(int start, int end, t_masterenv *menv)
{
	if (ft_checkredir(menv, start, end))
		ft_redir_execp(start, end, menv);
	else
		ft_executor_pipe(start, end, menv);
	exit(0);
}

int				ft_fork_parent(t_job *cur_j, t_masterenv *menv, int nb)
{
	int			pipefd[nb][2];
	int			fdd;
	int			i;
	int			start;
	int			ind;

	ind = ft_init_pipe(&start, &i, &fdd, menv);
	while (21)
	{
		if (!ft_pipe_error(cur_j, &i, pipefd[++i], (ind != menv->cgc) ? 1 : 0))
			return (0);
		if (g_pid == 0)
		{
			launch_process(cur_j, menv, menv->fg);
			ft_dup(&fdd, pipefd[i], (ind == menv->cgc) ? 1 : 0);
			ft_execp(start, ind, menv);
		}
		else
			fdd = ft_process_pipe(menv, cur_j, start, pipefd[i]);
		if (ft_get_next(&start, &ind, menv))
			break ;
	}
	while (i > -1)
		ft_close_pipe(pipefd[i--]);
	return (1);
}

int				ft_pipe_exec(int i, t_masterenv *menv)
{
	int		count;
	t_job	*new_j;

	if (!(new_j = new_job()))
		return (0);
	count = 0;
	menv->pipe = 1;
	while (menv->cgv[++i])
		if (ft_strcmp(menv->cgv[i], "|") == 0)
			count++;
	new_j->pipe = 1;
	if (ft_fork_parent(new_j, menv, count))
		back_fore(menv, new_j, menv->fg);
	return (0);
}
