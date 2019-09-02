/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:59:47 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/15 10:17:35 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	wait_job(t_job *job)
{
	int		status;
	pid_t	pid;

	if (signal(SIGCHLD, SIG_DFL) == SIG_ERR)
		return ;
	pid = waitpid(-1, &status, WUNTRACED);
	while (set_status_job(pid, status)
		&& !job_stopped(job) && !job_completed(job))
		pid = waitpid(-1, &status, WUNTRACED);
	signal(SIGCHLD, &ft_signal_handler);
}

void	update_jobs(void)
{
	int		status;
	pid_t	pid;

	pid = waitpid(WAIT_ANY, &status, WUNTRACED | WNOHANG | WCONTINUED);
	while (set_status_job(pid, status))
		pid = waitpid(WAIT_ANY, &status, WUNTRACED | WNOHANG | WCONTINUED);
}
