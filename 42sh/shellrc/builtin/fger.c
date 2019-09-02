/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fger.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:47:48 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/19 14:05:19 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	if_error(t_masterenv *menv, char **opt)
{
	if (ft_checkpipe(menv, menv->cgc))
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: fg: no job control\n");
		return (1);
	}
	if (ft_tablen(opt) > 1 && opt[1][0] == '-')
	{
		if (!(opt[1][1] == '-' || opt[1][1] == '\0'))
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: fg: %s: invalid option\n"
			, opt[1]);
			ft_printfd(2, "\e[93mfg\e[0m: usage: [job_spec ...]\n");
			return (1);
		}
		else if (opt[1][1] == '-' && opt[1][2] != '\0')
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: fg: %s: invalid option\n"
			, opt[1]);
			ft_printfd(2, "\e[93mfg\e[0m: usage: [job_spec ...]\n");
			return (1);
		}
	}
	return (0);
}

static void	print_finded_job(t_job *job)
{
	t_process	*process;

	process = job->fst_process;
	ft_printfd(1, "%s", process->cmd);
	if (process->next)
		ft_printfd(1, " ");
	process = process->next;
	while (process)
	{
		ft_printfd(1, "%s", process->cmd);
		if (process->next)
			ft_printfd(1, " ");
		process = process->next;
	}
	ft_printfd(1, "\n");
}

static int	without_arg(t_masterenv *menv, t_job *job)
{
	if (!(job = get_current_job()))
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: fg: no such job\n");
		return (menv->nruter = 1);
	}
	print_finded_job(job);
	go_foreground(job, 1);
	menv->nruter = job->ret;
	todo_on_sigchld();
	return (0);
}

int			ft_fg(t_masterenv *menv, char **opt)
{
	int		ambiguous;
	t_job	*job;

	if (if_error(menv, opt))
		return (menv->nruter = 1);
	job = NULL;
	if (!opt[1])
		return (without_arg(menv, job));
	ambiguous = 0;
	if (!(job = search_job(opt[1], &ambiguous)))
	{
		if (ambiguous)
			ft_printfd(2, "\e[93mMastershell\e[0m: fg: ambiguous job spec\n");
		else
			ft_printfd(2, "\e[93mMastershell\e[0m: fg: no such job\n");
		return (menv->nruter = 1);
	}
	print_finded_job(job);
	go_foreground(job, 1);
	menv->nruter = job->ret;
	todo_on_sigchld();
	return (0);
}
