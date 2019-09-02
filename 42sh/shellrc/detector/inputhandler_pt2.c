/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputhandler_pt2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:50:39 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:50:40 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_switchout(t_keymaster *lock, t_stockap *pac, char *toswitch)
{
	ft_putatbegin(lock, pac);
	ft_printfd(0, "%s", pac->cd_cap);
	free(lock->out);
	if (!(lock->out = (char*)malloc(sizeof(char) * (ft_strlen(toswitch) + 1))))
		return (1);
	ft_strcpy(lock->out, toswitch);
	lock->lenout = ft_strlen(toswitch);
	lock->lvl = (int)((lock->lenout + lock->promptsize) / pac->nbcol);
	ft_printfd(0, "%s", lock->out);
	lock->curspos = lock->promptsize + lock->lenout;
	if ((lock->curspos % pac->nbcol) == 0)
	{
		lock->curspos -= 1;
		ft_simplegoright(lock, pac);
	}
	return (0);
}

void		ft_mutant_refreash(int lenth, t_stockap *pac)
{
	int	i;

	i = -1;
	while (++i < lenth + 4)
		ft_printfd(0, "%s", pac->left_cap);
	ft_printfd(0, "%s", pac->cd_cap);
}

static void	ft_bufselectedstuff(t_keymaster *lock, t_stockap *pac
	, int savepos, int mode)
{
	if (mode == 0)
	{
		ft_putnstr_fd(lock->out, 0, savepos - lock->promptsize);
		ft_printfd(0, "%s", pac->rv_cap);
		ft_putnstr_fd(lock->out + savepos - lock->promptsize, 0
			, lock->selpiv - savepos);
		ft_printfd(0, "%s", pac->me_cap);
		ft_printfd(0, "%s", lock->out + lock->selpiv - lock->promptsize);
	}
	else
	{
		ft_putnstr_fd(lock->out, 0, lock->selpiv - lock->promptsize);
		ft_printfd(0, "%s", pac->rv_cap);
		ft_putnstr_fd(lock->out + lock->selpiv - lock->promptsize, 0
			, savepos - lock->selpiv);
		ft_printfd(0, "%s", pac->me_cap);
		ft_printfd(0, "%s", lock->out + savepos - lock->promptsize);
	}
}

static int	ft_bufselected(t_keymaster *lock, t_stockap *pac)
{
	int	savepos;
	int	i;

	savepos = lock->curspos;
	ft_putatbegin(lock, pac);
	i = -1;
	while (++i < lock->promptsize)
		ft_printfd(0, "%s", pac->left_cap);
	ft_printfd(0, "%s", pac->cd_cap);
	ft_printfd(0, "%s", lock->prompt);
	if (savepos < lock->selpiv)
		ft_bufselectedstuff(lock, pac, savepos, 0);
	else
		ft_bufselectedstuff(lock, pac, savepos, 1);
	lock->curspos = lock->promptsize + lock->lenout;
	if ((lock->curspos % pac->nbcol) == 0)
	{
		lock->curspos -= 1;
		ft_simplegoright(lock, pac);
	}
	i = lock->curspos + 1;
	while (--i > savepos)
		ft_goleft(lock, pac);
	return (0);
}

int			ft_bufselecter(t_keymaster *lock, t_stockap *pac)
{
	if (lock->index == 1)
		ft_goleft(lock, pac);
	if (lock->index == 2)
		ft_goright(lock, pac);
	if (lock->index == 11)
		ft_gobigleft(lock, pac);
	if (lock->index == 12)
		ft_gobigright(lock, pac);
	if (lock->index == 5)
		return (ft_savepresspap(lock, pac));
	if (lock->curspos == lock->selpiv)
	{
		ft_refreash(lock, pac);
		return (0);
	}
	return (ft_bufselected(lock, pac));
}
