/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:23:59 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/13 13:21:53 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void			add_process_pt2(t_process **l_process, t_process *new_p)
{
	t_process	*tmp;

	tmp = *l_process;
	if (!(*l_process))
	{
		*l_process = new_p;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_p;
}

static t_process	*addprocess(t_process *new_p)
{
	int			i;
	t_job		*job;

	i = 0;
	job = get_joblist(NULL);
	while (job->next)
	{
		job = job->next;
		i++;
	}
	add_process_pt2(&job->fst_process, new_p);
	return (job->fst_process);
}

t_process			*new_process(void)
{
	t_process	*new_p;

	if (!(new_p = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	new_p->pid = 0;
	new_p->ret = 0;
	new_p->status = 0;
	new_p->stopped = 0;
	new_p->completed = 0;
	new_p->next = NULL;
	return (addprocess(new_p));
}

static void			ft_getpcmd(t_masterenv *menv, int start, t_process *new_p)
{
	int		k;
	char	*cmd;
	char	*tmp;

	k = start;
	if (k != -1 && menv->cgprio[k] == 12)
		tmp = ft_strdup(menv->cgv[k]);
	while (menv->cgv[++k] && menv->cgprio[k] != 12)
	{
		if (k == 0)
			tmp = ft_strdup(menv->cgv[k]);
		else
		{
			cmd = ft_strjoin(tmp, " ");
			free(tmp);
			tmp = ft_strjoin(cmd, menv->cgv[k]);
			free(cmd);
		}
	}
	new_p->cmd = ft_strdup(tmp);
	free(tmp);
}

void				set_process(t_job *job, int pid, int st, t_masterenv *menv)
{
	t_process	*tmp;

	tmp = job->fst_process;
	while (tmp->next)
		tmp = tmp->next;
	tmp->pid = pid;
	ft_getpcmd(menv, st, tmp);
}
