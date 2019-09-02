/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:37:06 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:35:55 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			findparserror(char **ultib)
{
	int	i;

	i = -1;
	while (ultib[0][++i])
		if ((i > 0 && ultib[0][i] == '&' && ultib[0][i - 1] != '<'
			&& ultib[0][i - 1] != '>') || ultib[0][i] == ';'
			|| (ultib[0][i] == '|' && ultib[0][i + 1] == '|'))
		{
			i = (findparserror_core(ultib, i));
			if (i == -10)
				return (1);
			if (i == -20)
				return (0);
		}
	return (0);
}

static int	ft_ultilooper(t_masterenv *menv, t_keymaster *lock, t_stockap *pac)
{
	int		hmm;

	if (lock->hist.n == 1)
	{
		free(lock->hist.usercmd);
		ft_freetabc(lock->hist.cmdhist);
		lock->hist.count = 0;
		lock->hist.n = 0;
	}
	ft_create_hist(lock);
	hmm = ft_ultilooperbeginner(pac, lock, menv);
	if (hmm != -1)
		return (hmm);
	menv->nruter = 0;
	if (findparserror(&g_ultib))
	{
		free(g_ultib);
		return (0);
	}
	update_jobs();
	todo_on_sigchld();
	if (ft_preultimain_mk2(&g_ultib, menv, lock))
		return (1);
	todo_on_sigchld();
	return (0);
}

static	int	ft_main(t_masterenv *menv, char **env)
{
	ft_inicap(&g_pac);
	if (ft_cannoner())
		return (1);
	if (!(g_lock.prompt = (char*)lt_add(malloc(sizeof(char)))))
		return (1);
	g_lock.prompt[0] = 0;
	ft_printfd(0, "###############\n  \e[96mMASTERSHELL\n");
	ft_printfd(0, "  \e[93mfinal build\e[0m\n###############\n");
	if (ft_inienv(menv, env))
		return (1);
	if (!(menv->fcts = (char***)lt_add(malloc(sizeof(char**)))))
		return (1);
	if (!(menv->inenv = (char***)lt_add(malloc(sizeof(char**)))))
		return (1);
	if (!(menv->fcts[0] = (char**)lt_add(malloc(sizeof(char*)))))
		return (1);
	if (!(menv->inenv[0] = (char**)lt_add(malloc(sizeof(char*)))))
		return (1);
	if (!(g_lock.fcts = (char***)lt_add(malloc(sizeof(char**)))))
		return (1);
	if (!(g_lock.inenv = (char***)lt_add(malloc(sizeof(char**)))))
		return (1);
	g_lock.fcts = menv->fcts;
	g_lock.inenv = menv->inenv;
	return (0);
}

static int	ft_tini(t_masterenv *menv, char **env)
{
	if (ft_init_jobctrl())
		return (1);
	if (ft_main(menv, env))
		return (1);
	menv->inenv[0][0] = 0;
	menv->fcts[0][0] = 0;
	g_lock.presspap = 0;
	ft_gethistfile(&g_lock, menv);
	if (!ft_init_internalvar(menv))
		return (1);
	ft_inirep(menv, 1);
	g_pid = 0;
	g_lock.sep = NULL;
	g_ultib = NULL;
	menv->als = NULL;
	return (0);
}

int			main(int argc, char *argv[], char **env)
{
	t_masterenv	menv;
	int			ret;

	(void)argv;
	(void)argc;
	ret = init_term();
	if (ret == 0)
	{
		if (ft_tini(&menv, env))
			return (1);
		while (1)
			ft_ultilooper(&menv, &g_lock, &g_pac);
	}
	return (ret);
}
