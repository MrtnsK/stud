/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:17:34 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/20 15:04:19 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			error_job(t_job *job, char *str)
{
	(void)job;
	ft_printfd(2, "\e[93mMastershell\e[0m: %s\n", str);
	return (0);
}

void		back_fore_norme(t_masterenv *menv, t_job *job)
{
	go_background(menv, job, 0);
	menv->nruter = 0;
}

static int	ft_jobsusage(char *opt)
{
	int i;

	i = 0;
	while (opt[++i])
		if (opt[i] != 'l' && opt[i] != 'p')
			break ;
	if (opt[i] && opt[i] != 'l' && opt[i] != 'p')
	{
		if (opt[1] == '\0' || (opt[1] == '-' && opt[2] == '\0'))
			return (3);
		ft_printfd(2, "\e[93mMastershell\e[0m: jobs: %s: ", opt);
		ft_printfd(2, "invalid option\n");
		ft_printfd(2, "\e[93mjobs\e[0m: usage: [-l|-p] [job_id...]\n");
		return (0);
	}
	else
	{
		if (opt[i - 1] == 'l')
			return (1);
		else if (opt[i - 1] == 'p')
			return (2);
		else if (opt[i - 1] == '-')
			return (3);
	}
	return (0);
}

int			while_jobser(char **opt, int *f, int *i_opt)
{
	int		tmp_f;

	while (opt[*i_opt] && opt[*i_opt][0] == '-')
	{
		if (!(tmp_f = ft_jobsusage(opt[*i_opt])))
			return (1);
		else if (tmp_f == 3 && (*i_opt)++)
			break ;
		*f = tmp_f;
		(*i_opt)++;
	}
	return (0);
}
