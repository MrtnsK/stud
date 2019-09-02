/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:58:24 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/02 16:21:27 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		launch_process(t_job *job, t_masterenv *menv, int fg)
{
	t_process	*new_p;

	(void)menv;
	new_p = job->fst_process;
	while (new_p->next)
		new_p = new_p->next;
	new_p->pid = getpid();
	if (job->pgid == 0)
		job->pgid = new_p->pid;
	if (setpgid(new_p->pid, job->pgid) == -1)
	{
		error_job(job, "\e[93mMastershell\e[0m: launch_process error\n");
		return ;
	}
	if (fg)
		if (tcsetpgrp(STDIN_FILENO, job->pgid) == -1)
		{
			error_job(job, "\e[93mMastershell\e[0m: launch_process error\n");
			return ;
		}
	ft_reset_signals();
}

void		process_info(t_masterenv *menv, t_job *job, pid_t pid, int start)
{
	if (!job->pgid)
		job->pgid = pid;
	set_process(job, pid, start, menv);
	setpgid(pid, job->pgid);
}

int			launch_job(int foreground, char *path, t_masterenv *menv,
char **opt)
{
	pid_t	pid;
	t_job	*new_j;

	if (!(new_j = new_job()))
		return (0);
	if (!(new_j->fst_process = new_process()))
		return (error_job(new_j, "\e[93mMastershell\e[0m: launch_job error\n"));
	if ((pid = fork()) == -1)
		return (error_job(new_j, "\e[93mMastershell\e[0m: launch_job error\n"));
	if (pid == 0)
	{
		launch_process(new_j, menv, foreground);
		execve(path, opt, menv->stock[0]);
		ft_printfd(2, "\e[93mMastershell\e[0m: Permission denied\n");
		exit(1);
	}
	else
		process_info(menv, new_j, pid, -1);
	back_fore(menv, new_j, foreground);
	free(path);
	return (1);
}
