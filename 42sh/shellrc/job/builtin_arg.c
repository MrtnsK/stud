/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:52:14 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/03 14:26:25 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_job			*get_job_with_nb(char *arg)
{
	int		job_nb;
	t_job	*job;

	job_nb = ft_atoi(arg);
	job = get_joblist(NULL);
	while (job)
	{
		if (job->job_nb == job_nb)
			return (job);
		job = job->next;
	}
	return (NULL);
}

t_job			*get_current_job(void)
{
	t_job	*job;

	job = get_joblist(NULL);
	while (job)
	{
		if (job->plus_minus == '+')
			return (job);
		job = job->next;
	}
	return (NULL);
}

t_job			*get_previous_job(void)
{
	t_job	*job;

	job = get_joblist(NULL);
	while (job)
	{
		if (job->plus_minus == '-')
			return (job);
		job = job->next;
	}
	return (NULL);
}

static t_job	*get_job_simple_str(char *arg, int *ambiguous)
{
	t_job	*job;

	if ((job = get_job_with_nb(arg)))
		return (job);
	else if ((job = get_job_with_str(arg, ambiguous)))
		return (job);
	else
		return (NULL);
}

t_job			*search_job(char *arg, int *ambiguous)
{
	t_job	*job;

	if (!(job = NULL) && arg[0] != '%' && arg[0] != '+' && arg[0] != '-')
		return (get_job_simple_str(arg, ambiguous));
	else if (arg[0] == '+' || (arg[0] == '%' && arg[1] == 0))
		return (get_current_job());
	else if (arg[0] == '-' && !arg[1])
		return (get_previous_job());
	if (arg[1] == '+' || arg[1] == '%')
		return (get_current_job());
	else if (arg[1] == '-')
		return (get_previous_job());
	if (arg[1] != 0)
	{
		if ((job = get_job_with_nb(&arg[1])))
			return (job);
		else if ((job = get_job_with_str(&arg[1], ambiguous)))
			return (job);
	}
	else
		return (get_current_job());
	return (job);
}
