/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focus_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:01:06 by fdikilu           #+#    #+#             */
/*   Updated: 2019/07/29 20:11:29 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	focus_minus(t_job *job)
{
	t_job	*l_job;
	t_job	*tmp;

	l_job = get_joblist(NULL);
	while (l_job && l_job->plus_minus != '+')
		l_job = l_job->next;
	if (!l_job || job->pgid == l_job->pgid)
		return ;
	tmp = get_joblist(NULL);
	while (tmp && tmp->plus_minus != '-')
		tmp = tmp->next;
	if (tmp)
		tmp->plus_minus = ' ';
	if (l_job)
		l_job->plus_minus = '-';
}

void	check_plus(void)
{
	t_job	*l_job;

	if (!(l_job = get_joblist(NULL)))
		return ;
	while (l_job->next)
	{
		if (l_job->plus_minus == '+')
			return ;
		l_job = l_job->next;
	}
	if (l_job->plus_minus != '+')
		l_job->plus_minus = '+';
}

void	plus_minus(void)
{
	t_job	*tmp;
	t_job	*prev;

	prev = NULL;
	tmp = get_joblist(NULL);
	if (!tmp)
		return ;
	check_plus();
	while (tmp->next)
	{
		if (tmp->plus_minus == '-')
			return ;
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp->plus_minus == ' ')
	{
		tmp->plus_minus = '+';
		if (prev)
			prev->plus_minus = '-';
	}
	else if (tmp->plus_minus == '+')
		if (prev)
			prev->plus_minus = '-';
}
