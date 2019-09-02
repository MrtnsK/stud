/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:51:13 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/19 09:01:39 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static	int			ft_exit_args(char **opt, t_masterenv *menv)
{
	int		val;

	if (ft_tablen(opt) > 2)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: exit: too many arguments\n");
		menv->nruter = 1;
		return (1);
	}
	else if (ft_tablen(opt) > 1)
		if (ft_exitn(opt[1], menv))
			return (0);
	val = ft_atoi(opt[1]);
	if (val == -1 && opt[1][0] != '-')
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: exit: ");
		ft_printfd(2, "%s: numeric argument required\n", opt[1]);
		menv->nruter = 255;
	}
	else if (val > 255)
		menv->nruter = 0;
	else if (val < 255)
		menv->nruter = val;
	else
		menv->nruter = 255;
	return (0);
}

static	int			ft_exit_error(t_masterenv *menv, int *nb)
{
	ft_printfd(2, "exit\nthere are stopped jobs.\n");
	*nb = 1;
	if (menv->nruter == 0)
		menv->nruter = 1;
	return (1);
}

static	int			ft_opt(t_masterenv *menv, t_keymaster *lock, int *nb)
{
	if (*nb == 0)
		return (ft_exit_error(menv, nb));
	if (*nb == 1 && lock->hist.cmdhist && lock->hist.index)
		if (ft_strcmp(lock->hist.cmdhist[lock->hist.index - 1],
			"exit") != 0)
			return (ft_exit_error(menv, nb));
	return (0);
}

static	void		ft_exitfin(t_masterenv *menv, char **opt, t_keymaster *lock
, int *nb)
{
	if (opt)
	{
		ft_freetabc(opt);
		ft_tabfree(menv->cgv);
		if (menv->cgtype)
			free(menv->cgtype);
		if (menv->cgprio)
			free(menv->cgprio);
	}
	ft_seeyoulater(menv, lock);
	*nb = 0;
}

int					ft_exiter(t_masterenv *menv, char **opt, t_keymaster *lock)
{
	static	int	nb;

	if (opt && opt[1])
		if (ft_exit_args(opt, menv))
			return (1);
	if (menv->pipe == 1 || !menv->fg)
		exit(menv->nruter);
	if (lock->nb_job)
	{
		if (!opt && nb == 0)
			return (ft_exit_error(menv, &nb));
		else if (opt)
			if (ft_opt(menv, lock, &nb))
				return (1);
		ft_exitfin(menv, opt, lock, &nb);
	}
	else
		ft_exitfin(menv, opt, lock, &nb);
	return (0);
}
