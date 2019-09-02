/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_foreground.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:34:11 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/19 12:45:20 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		go_background(t_masterenv *menv, t_job *job, int cont)
{
	char		*tmp;
	t_process	*new_p;

	job->in_fg = 0;
	new_p = job->fst_process;
	focus_minus(job);
	job->plus_minus = '+';
	if (!cont)
	{
		ft_printfd(2, "[%d] %d\n", job->job_nb, job->pgid);
		if (!(tmp = ft_itoa(job->pgid)))
		{
			update_jobs();
			return ;
		}
		ft_addvar(menv->internal_var, setvar("!", tmp));
		free(tmp);
	}
	if (cont)
		if (kill(-job->pgid, SIGCONT))
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: go_background error\n");
			return ;
		}
	update_jobs();
}

void		go_foreground(t_job *job, int cont)
{
	t_process	*tmp;

	ft_termoder(2);
	if (tcsetpgrp(STDIN_FILENO, job->pgid) == -1)
		return ;
	if (cont)
		if (kill(-job->pgid, SIGCONT) == -1)
		{
			error_job(job, "\e[93mMastershell\e[0m: go_foreground error\n");
			return ;
		}
	job->notif = 0;
	job->in_fg = 1;
	tmp = job->fst_process;
	while (tmp)
	{
		tmp->stopped = 0;
		tmp = tmp->next;
	}
	wait_job(job);
	ft_termoder(2);
	ft_cannoner();
	if (tcsetpgrp(0, g_lock.shell_pgid) == -1)
		error_job(job, "\e[93mMastershell\e[0m: go_foreground error\n");
	g_pid = 0;
}

void		back_fore(t_masterenv *menv, t_job *job, int fg)
{
	t_process	*p;

	if (fg && job->pipe)
	{
		go_foreground(job, 0);
		p = job->fst_process;
		if ((WIFSIGNALED(p->status) || WIFSTOPPED(p->status))
			&& p->status != 13)
			menv->nruter = job->ret;
		else
		{
			while (p->next)
				p = p->next;
			menv->nruter = p->ret;
			job->ret = p->ret;
		}
	}
	else if (fg && !job->pipe)
	{
		go_foreground(job, 0);
		menv->nruter = job->ret;
	}
	else
		back_fore_norme(menv, job);
}
