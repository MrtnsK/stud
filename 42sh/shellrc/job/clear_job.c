/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:08:16 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/15 18:35:20 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	free_process(t_process *process)
{
	if (!process)
		return ;
	free(process->cmd);
	free(process);
}

void		free_job(t_job *job)
{
	t_process	*tmp;
	t_process	*process;

	if (!job)
		return ;
	process = job->fst_process;
	while (process)
	{
		tmp = process;
		process = process->next;
		free_process(tmp);
	}
	free(job);
}

void		serial_killer(void)
{
	t_job		*tmp;
	t_job		*l_job;

	l_job = get_joblist(NULL);
	while (l_job && g_lock.nb_job)
	{
		tmp = l_job;
		l_job = l_job->next;
		free_job(tmp);
		g_lock.nb_job -= 1;
	}
}

int			in_the_list(t_job *job)
{
	t_job	*l_job;
	t_job	*tmp;

	if (!(l_job = get_joblist(NULL)))
		return (0);
	while (l_job && l_job->pgid != job->pgid)
		l_job = l_job->next;
	if (!l_job)
		return (0);
	tmp = get_joblist(NULL);
	while (tmp->next->pgid != l_job->pgid)
		tmp = tmp->next;
	tmp->next = l_job->next;
	free_job(l_job);
	plus_minus();
	return (1);
}
