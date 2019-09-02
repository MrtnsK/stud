/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:43:53 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/14 13:35:30 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		print_job_l(t_job *job)
{
	t_process	*process;

	process = job->fst_process;
	ft_printfd(1, "[%d]%c %d ", job->job_nb, job->plus_minus, process->pid);
	if (process->stopped)
		ft_printfd(1, "Stopped: %d %*s\n", job->ret - 128,
		15 + ft_strlen(process->cmd), process->cmd);
	else
		ft_printfd(1, "Running %*s\n", 17 + ft_strlen(process->cmd),
		process->cmd);
	process = process->next;
	while (process)
	{
		ft_print_pipe(process);
		process = process->next;
	}
}

void		print_job(t_job *job)
{
	t_process	*process;
	int			size;
	char		*tmp;

	size = ft_cmd_size(job, &tmp);
	process = job->fst_process;
	ft_printfd(1, "[%d]%c  ", job->job_nb, job->plus_minus);
	if (process->stopped)
		ft_printfd(1, "Stopped(%d) %*s\n", job->ret, 12 + size, tmp);
	else
		ft_printfd(1, "Running %*s\n", 17 + size, tmp);
	free(tmp);
}

static void	print_all(int flag)
{
	t_job	*job;

	job = get_joblist(NULL);
	while (job)
	{
		if (flag == 1)
			print_job_l(job);
		else if (flag == 2)
			ft_printfd(1, "%d\n", job->pgid);
		else
			print_job(job);
		job = job->next;
	}
}

int			ft_jobs(t_masterenv *menv, char **opt)
{
	int		f;
	int		i_opt;
	int		ambiguous;
	t_job	*job;

	(void)menv;
	i_opt = 1;
	f = 0;
	if (ft_tablen(opt) > 1)
		if (while_jobser(opt, &f, &i_opt))
			return (1);
	if (!opt[i_opt])
		print_all(f);
	else
	{
		while (opt[i_opt])
		{
			ambiguous = 0;
			job = search_job(opt[i_opt], &ambiguous);
			print_in_while_jobser(job, f, ambiguous);
			i_opt++;
		}
	}
	return (0);
}
