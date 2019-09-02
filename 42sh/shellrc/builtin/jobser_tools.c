/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:56:16 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/13 13:27:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	print_error_jobser(int ambiguous)
{
	if (ambiguous)
		ft_printfd(2, "\e[93mMastershell\e[0m: jobs: ambiguous job spec\n");
	else
		ft_printfd(2, "\e[93mMastershell\e[0m: jobs: no such job\n");
}

void		print_in_while_jobser(t_job *job, int flag, int ambiguous)
{
	if (flag == 1)
	{
		if (!job)
			print_error_jobser(ambiguous);
		else
			print_job_l(job);
	}
	else if (flag == 2)
	{
		if (!job)
			print_error_jobser(ambiguous);
		else
			ft_printfd(1, "%d\n", job->pgid);
	}
	else
	{
		if (!job)
			print_error_jobser(ambiguous);
		else
			print_job(job);
	}
}

void		ft_print_pipe(t_process *process)
{
	if (process->stopped)
	{
		ft_printfd(1, "%10d Stopped: %d ", process->pid, process->ret - 128);
		ft_printfd(1, "%*s\n", 15 + ft_strlen(process->cmd), process->cmd);
	}
	else if (process->completed)
	{
		ft_printfd(1, "%10d Done(%d) ", process->pid, process->ret);
		ft_printfd(1, "%*s\n", 19 + ft_strlen(process->cmd), process->cmd);
	}
	else
		ft_printfd(1, "%10d Running %*s\n", process->pid,
		23 + ft_strlen(process->cmd), process->cmd);
}

int			ft_cmd_size(t_job *job, char **tmp)
{
	t_process	*p;
	char		*final;
	char		*cmd;

	p = job->fst_process;
	if (job->pipe == 0)
		final = ft_strdup(p->cmd);
	else
		final = ft_strjoin(p->cmd, " ");
	p = p->next;
	while (p)
	{
		cmd = ft_strjoin(final, " ");
		free(final);
		final = ft_strjoin(cmd, p->cmd);
		free(cmd);
		p = p->next;
	}
	tmp[0] = ft_strdup(final);
	free(final);
	return (ft_strlen(tmp[0]));
}
