/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_sigchld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:43:30 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/15 20:08:32 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		print_status(t_job *job, char *status)
{
	t_process	*process;
	int			size;
	char		*tmp;

	process = job->fst_process;
	size = ft_cmd_size(job, &tmp);
	ft_printfd(2, "[%d]%c  ", job->job_nb, job->plus_minus);
	ft_printfd(2, "%s(%d)", status, job->ret);
	ft_printfd(2, "%*s\n", 10 + size, tmp);
	free(tmp);
}

static int	terminated(t_job *job)
{
	job->ret -= 128;
	print_status(job, "Terminated:");
	if (job->ret == 9)
	{
		ft_termoder(2);
		if (ft_cannoner())
			return (1);
	}
	if (!(job = get_joblist(job)))
		return (1);
	return (0);
}

static int	completed(t_job *job)
{
	if (!job->in_fg)
		print_status(job, "Done");
	if (!(job = get_joblist(job)))
		return (1);
	return (0);
}

static int	stopped(t_job *job)
{
	if (job->in_fg)
		print_status(job, "Stopped");
	if (job->ret == 145)
	{
		ft_termoder(2);
		if (ft_cannoner())
			return (1);
	}
	return (0);
}

void		todo_on_sigchld(void)
{
	t_job		*job;
	t_job		*tmp;

	job = get_joblist(NULL);
	while (job)
	{
		tmp = job;
		job = job->next;
		if (job_completed(tmp) && tmp->ret > 128)
		{
			if (terminated(tmp))
				return ;
		}
		else if (job_completed(tmp))
		{
			if (completed(tmp))
				return ;
		}
		else if (job_stopped(tmp) && !tmp->notif && (tmp->notif = 1))
		{
			if (stopped(tmp))
				return ;
		}
	}
}
