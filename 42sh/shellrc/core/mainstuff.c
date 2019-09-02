/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:27:12 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:25:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_freeenv(t_masterenv *menv)
{
	int i;

	i = -1;
	while (menv->stock[0][++i])
		free(menv->stock[0][i]);
	free(menv->stock[0][i]);
	free(menv->stock[0]);
	free(menv->stock);
	i = -1;
	while (menv->fcts[0][++i])
		free(menv->fcts[0][i]);
	free(menv->fcts[0][i]);
	i = -1;
	while (menv->inenv[0][++i])
		free(menv->inenv[0][i]);
	free(menv->inenv[0][i]);
	lt_remove(menv->inenv[0]);
	ft_tabfree(*menv->internal_var);
	free(menv->internal_var);
}

void	ft_freear(t_masterenv *menv, char *buf)
{
	int i;

	free(buf);
	if (menv->cgc != 0)
	{
		i = -1;
		while (menv->cgv[++i])
			free(menv->cgv[i]);
		free(menv->cgv[i]);
	}
	free(menv->cgv);
	free(menv->cgtype);
	free(menv->cgprio);
}

void	ft_seeyoulater(t_masterenv *menv, t_keymaster *lock)
{
	int	ret;

	ret = menv->nruter;
	if (menv->internal_var[0][menv->rep[0]])
		ft_printfd(0, "\e[93ma bientot %s\e[0m\n",
		menv->internal_var[0][menv->rep[0]] + 5);
	else
		ft_printfd(0, "\e[93ma bientot\e[0m\n");
	ft_freeenv(menv);
	free(lock->sep);
	lt_remove(lock->hist.histfile);
	if (lock->hist.count != 0)
	{
		free(lock->hist.usercmd);
		if (lock->hist.cmdhist)
			ft_freetabc(lock->hist.cmdhist);
	}
	free(g_ultib);
	free(lock->presspap);
	serial_killer();
	ft_termoder(2);
	lt_delet();
	exit(ret);
}

void	ft_seeyoulater_bitch(t_masterenv *menv, t_keymaster *lock)
{
	ft_printfd(2, "\n\e[93mwhat have you done?\n\e[90mRIP\e[0m\n");
	free(lock->out);
	ft_seeyoulater(menv, lock);
}
