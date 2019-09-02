/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autok_pathter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:46:32 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:46:35 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_pather_free(t_keymaster *lock)
{
	free(lock->fullname);
	free(lock->tmp);
	free(lock->final);
}

int			ft_pather_pakoul(t_keymaster *lock)
{
	free(lock->final);
	free(lock->tmp);
	return (0);
}

static int	ft_pathter_endmodes(t_keymaster *lock, int mode, t_stockap *pac)
{
	int i;

	ft_refreash(lock, pac);
	if (mode == 1)
	{
		lock->aukprinted = 0;
		i = -1;
		while (lock->stock.output[++i])
			free(lock->stock.output[i]);
		free(lock->stock.output);
		free(lock->tmp);
		free(lock->final);
		return (0);
	}
	else if (mode == 3 || mode == 5)
	{
		lock->aukprinted = 0;
		i = -1;
		while (lock->stock.output[++i])
			free(lock->stock.output[i]);
		free(lock->stock.output);
		free(lock->final);
		return (0);
	}
	return (0);
}

static int	ft_pathter_next(t_keymaster *lock, t_stockap *pac)
{
	int			i;
	int			savepos;
	t_basiks	tools;

	lock->stock.select = ((lock->stock.select + 1) % lock->stock.argc);
	savepos = lock->curspos;
	ft_simpleputatend(lock, pac);
	ft_printfd(0, "\n");
	if (ft_basic(&lock->stock, pac, &tools, lock))
		return (1);
	i = -2;
	while (++i < (tools.nbligne + lock->lvl))
		ft_printfd(0, "%s", pac->up_cap);
	lock->curspos = 0;
	i = -1;
	while (++i < pac->nbcol)
		ft_printfd(0, "%s", pac->left_cap);
	i = -1;
	while (++i < savepos)
		ft_simplegoright(lock, pac);
	return (0);
}

int			ft_pathter(t_keymaster *lock, t_stockap *pac, int mode)
{
	int			i;

	i = 0;
	if (mode == 1 || mode == 3 || mode == 5)
	{
		return (ft_pathter_endmodes(lock, mode, pac));
	}
	else if (mode == 0)
	{
		return (ft_pathter_next(lock, pac));
	}
	else if (mode == 2)
	{
		return (ft_pathter_pathchoice(lock, pac, i));
	}
	else if (mode == 4)
	{
		return (ft_pathter_commandchoice(lock, pac, i));
	}
	else if (mode == 6)
	{
		return (ft_pathter_inenvchoice(lock, pac, i));
	}
	return (0);
}
