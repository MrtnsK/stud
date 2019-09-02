/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:24:26 by fdikilu           #+#    #+#             */
/*   Updated: 2019/07/31 13:46:01 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_job			*new_job(void)
{
	t_job	*new_j;

	if (!(new_j = (t_job *)malloc(sizeof(t_job))))
		return (NULL);
	new_j->pgid = 0;
	new_j->ret = 0;
	new_j->notif = 0;
	new_j->pipe = 0;
	new_j->in_fg = 1;
	new_j->job_nb = 1;
	new_j->plus_minus = ' ';
	new_j->fst_process = NULL;
	new_j->next = NULL;
	get_joblist(new_j);
	return (new_j);
}

static void		add_job(t_job *l_job, t_job *new_job)
{
	while (l_job->next)
		l_job = l_job->next;
	new_job->job_nb = l_job->job_nb + 1;
	l_job->next = new_job;
}

static t_job	*add_and_del(t_job *l_job, t_job *new_j)
{
	if (l_job->pgid == new_j->pgid)
	{
		l_job = l_job->next;
		free_job(new_j);
		g_lock.nb_job -= 1;
		return (l_job);
	}
	if (in_the_list(new_j))
	{
		g_lock.nb_job -= 1;
		return (l_job);
	}
	add_job(l_job, new_j);
	g_lock.nb_job += 1;
	return (NULL);
}

t_job			*get_joblist(t_job *new_j)
{
	t_job			*tmp;
	static t_job	*l_job = NULL;

	if (l_job && !g_lock.nb_job)
		l_job = NULL;
	if (!l_job)
	{
		if (!new_j)
			return (NULL);
		l_job = new_j;
		g_lock.nb_job += 1;
		return (l_job);
	}
	if (l_job && !new_j && g_lock.nb_job == 0)
		return (NULL);
	if (new_j)
		if ((tmp = add_and_del(l_job, new_j)))
			return (l_job = tmp);
	return (l_job);
}
