/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echoer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:25:28 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/30 10:14:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			ft_echostuff(char **opt, t_echotools *ect)
{
	ect->nope = 0;
	ect->j = 0;
	while (opt[ect->i][ect->j] && ect->nonstop)
	{
		if (opt[ect->i][ect->j] == '\\'
			&& opt[ect->i][ect->j + 1] == 'c')
		{
			ect->flag = 1;
			ect->nonstop = 0;
		}
		else
			write(1, &opt[ect->i][ect->j], 1);
		ect->j += 1;
	}
	if (opt[ect->i + 1] && ect->nonstop)
		write(1, " ", 1);
}

static	int		ft_echowriterror(t_masterenv *menv)
{
	struct stat fd;

	if (fstat(1, &fd) == -1)
	{
		ft_printfd(2,
		"\e[93mMastershell\e[0m: echo: write error: bad file descriptor\n");
		menv->nruter = 1;
		return (1);
	}
	return (0);
}

int				ft_echo(t_masterenv *menv, char **opt)
{
	t_echotools ect;

	ect.flag = 0;
	ect.nope = 1;
	ect.nonstop = 1;
	if (ft_tablen(opt) > 1)
	{
		ect.i = 1;
		while (opt[ect.i] && ect.nonstop)
		{
			if (!ft_strcmp(opt[ect.i], "-n") && ect.nope)
				ect.flag = 1;
			else
				ft_echostuff(opt, &ect);
			ect.i += 1;
		}
	}
	if (ft_echowriterror(menv))
		return (1);
	if (ect.flag == 0)
		write(1, "\n", 1);
	return (0);
}
