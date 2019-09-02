/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:59:37 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/15 10:26:04 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	return_value(t_job *l_job, t_process *tmp, int status)
{
	tmp->status = status;
	if (WIFEXITED(status))
	{
		l_job->ret = WEXITSTATUS(status);
		tmp->ret = l_job->ret;
		tmp->completed = 1;
	}
	else if (WIFSIGNALED(status))
	{
		l_job->ret = 128 + WTERMSIG(status);
		tmp->ret = l_job->ret;
		tmp->completed = 1;
	}
	else if (WIFSTOPPED(status))
	{
		l_job->ret = 128 + WSTOPSIG(status);
		tmp->ret = l_job->ret;
		tmp->stopped = 1;
		focus_minus(l_job);
		l_job->plus_minus = '+';
	}
}

int			set_status_job(pid_t pid, int status)
{
	t_job		*l_job;
	t_process	*tmp;

	l_job = get_joblist(NULL);
	if (pid <= 0)
		return (0);
	while (l_job)
	{
		tmp = l_job->fst_process;
		while (tmp)
		{
			if (tmp->pid == pid)
			{
				return_value(l_job, tmp, status);
				return (1);
			}
			tmp = tmp->next;
		}
		l_job = l_job->next;
	}
	return (0);
}

int			job_stopped(t_job *job)
{
	t_process	*tmp;

	tmp = job->fst_process;
	while (tmp)
	{
		if (tmp->pid && !tmp->stopped && !tmp->completed)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			job_completed(t_job *job)
{
	t_process	*tmp;

	tmp = job->fst_process;
	while (tmp)
	{
		if (tmp->pid && !tmp->completed)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
