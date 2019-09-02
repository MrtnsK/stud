/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_arg_pt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:52:37 by fdikilu           #+#    #+#             */
/*   Updated: 2019/07/31 12:18:32 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_job	*in_while_with(t_job *job, char *arg)
{
	char		*tmp;
	t_job		*to_return;
	t_process	*process;

	to_return = NULL;
	process = job->fst_process;
	if (!(tmp = ft_strnew(0)))
		return (NULL);
	while (process)
	{
		if (!(tmp = ft_strjoin_free(tmp, process->cmd)))
			return (NULL);
		process = process->next;
	}
	if (ft_strstr(tmp, &arg[1]))
	{
		free(tmp);
		return (job);
	}
	free(tmp);
	return (NULL);
}

static t_job	*with(char *arg, int *ambiguous)
{
	t_job		*job;
	t_job		*tmp;
	t_job		*to_return;

	job = get_joblist(NULL);
	to_return = NULL;
	while (job)
	{
		if ((tmp = in_while_with(job, arg)))
		{
			if (!to_return)
				to_return = in_while_with(job, arg);
			else
			{
				*ambiguous = 1;
				return (NULL);
			}
		}
		job = job->next;
	}
	return (to_return);
}

static t_job	*in_while_without(t_job *job, char *arg)
{
	char		*tmp;
	t_job		*to_return;
	t_process	*process;

	to_return = NULL;
	process = job->fst_process;
	if (!(tmp = ft_strnew(0)))
		return (NULL);
	while (process)
	{
		if (!(tmp = ft_strjoin_free(tmp, process->cmd)))
			return (NULL);
		process = process->next;
	}
	if (!ft_strncmp(tmp, arg, ft_strlen(arg)))
	{
		free(tmp);
		return (job);
	}
	free(tmp);
	return (NULL);
}

static t_job	*without(char *arg, int *ambiguous)
{
	t_job		*job;
	t_job		*tmp;
	t_job		*to_return;

	job = get_joblist(NULL);
	to_return = NULL;
	while (job)
	{
		if ((tmp = in_while_without(job, arg)))
		{
			if (!to_return)
				to_return = tmp;
			else
			{
				*ambiguous = 1;
				return (NULL);
			}
		}
		job = job->next;
	}
	return (to_return);
}

t_job			*get_job_with_str(char *arg, int *ambiguous)
{
	if (arg[0] == '?')
		return (with(arg, ambiguous));
	else
		return (without(arg, ambiguous));
}
