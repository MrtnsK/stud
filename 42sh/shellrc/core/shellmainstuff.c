/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellmainstuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:40:21 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/15 20:39:15 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_ultilanceur(t_masterenv *menv, int *i, t_keymaster *lock)
{
	char	*tmp;

	if (!g_ultib[*i + 1])
	{
		g_ultib[*i] = 0;
		return (0);
	}
	g_ultib[*i] = 0;
	if (!(tmp = (char*)malloc(sizeof(char)
		* (ft_strlen(g_ultib) + 1))))
		return (1);
	ft_strcpy(tmp, g_ultib);
	if (ft_protoc(&tmp, menv, lock))
		return (1);
	g_ultib[0] = 0;
	ft_strcator(g_ultib, g_ultib + *i + 1);
	*i = -1;
	return (0);
}

void		ft_quoters(int *quoters, int yep)
{
	if (*quoters == 0)
		*quoters = yep;
	else
		*quoters = 0;
}

int			ft_ultimain(t_masterenv *menv, t_keymaster *lock)
{
	int		i;
	int		quoters;

	i = -1;
	quoters = 0;
	while (g_ultib[++i])
	{
		if (g_ultib[i] == '"' && g_ultib[i - 1] != '\\' && quoters != 2)
			ft_quoters(&quoters, 1);
		if (g_ultib[i] == '\'' && g_ultib[i - 1] != '\\' && quoters != 1)
			ft_quoters(&quoters, 2);
		if (g_ultib[i] == ';' && g_ultib[i - 1] != '\\' && !quoters)
		{
			if (ft_ultilanceur(menv, &i, lock))
				return (1);
		}
	}
	return (0);
}

static	int	ft_nruter(t_masterenv *menv, t_keymaster *lock)
{
	if (menv->nruter == 0)
	{
		if (ft_masterprompt(lock))
			return (1);
	}
	else
	{
		if (ft_errorprompt(lock))
			return (1);
	}
	return (0);
}

int			ft_ultilooperbeginner(t_stockap *pac, t_keymaster *lock
	, t_masterenv *menv)
{
	if (ft_nruter(menv, lock))
		return (1);
	if (!(g_ultib = (char*)malloc(sizeof(char))))
		return (1);
	g_ultib[0] = 0;
	lock->heremode = 0;
	lock->search = 0;
	if (ft_unfinishedlauncher(pac, lock, menv))
	{
		free(g_ultib);
		if (lock->heremode == 1)
			return (0);
		return (1);
	}
	if (theresexp(g_ultib, lock))
	{
		if (exp_main(&g_ultib, lock))
		{
			free(g_ultib);
			g_ultib = NULL;
			return (0);
		}
	}
	replace_alias(&g_ultib, menv);
	return (-1);
}
