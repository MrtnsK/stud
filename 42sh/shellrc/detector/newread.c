/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:51:14 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/15 13:52:42 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_newreadstuff(t_keymaster *lock, t_stockap *pac, int option)
{
	if (option == 0)
	{
		if (lock->index != 1 && lock->index != 2
			&& lock->index != 11 && lock->index != 12
			&& lock->index != -2 && lock->index != 5)
		{
			lock->selectmode = 0;
			ft_lastprompt(lock);
			ft_refreash(lock, pac);
		}
		else
		{
			if (ft_bufselecter(lock, pac))
				return (1);
		}
		ft_memset(lock->bigbuf, 0, 256);
		ft_memset(lock->buf, 0, 256);
	}
	else
	{
		ft_memset(lock->bigbuf, 0, 256);
		ft_memset(lock->buf, 0, 256);
		ft_refreash(lock, pac);
	}
	return (0);
}

int		ft_newreadcore(t_keymaster *lock, t_stockap *pac, t_masterenv *menv)
{
	if (lock->selectmode)
	{
		if (ft_newreadstuff(lock, pac, 0))
			return (1);
	}
	else
	{
		ft_memset(lock->bigbuf, 0, 256);
		if (ft_activkey(lock, pac, menv))
			return (1);
		if (lock->index != 3)
			ft_memset(lock->buf, 0, 256);
		else
		{
			ft_putatend(lock, pac);
			write(0, "\n", 1);
			return (0);
		}
	}
	return (-2);
}

void	ft_newread_3(t_keymaster *lock, t_stockap *pac)
{
	int		lenth;

	if (lock->out[0] && lock->search)
	{
		lenth = lock->curspos + ft_strlen(lock->rechist) + 4;
		ft_mutant_refreash(lenth, pac);
		ft_printfd(0, "%s", lock->prompt);
		ft_printfd(0, "`%s': ", lock->out);
	}
	else if (lock->search)
	{
		lenth = lock->curspos + ft_strlen(lock->rechist) + 4;
		ft_mutant_refreash(lenth, pac);
		ft_printfd(0, "%s", lock->prompt);
		ft_printfd(0, "`%s': ", lock->out);
	}
	if (ft_search(lock))
		ft_printfd(0, "%s", lock->rechist);
}

int		ft_newread(t_keymaster *lock, t_stockap *pac, t_masterenv *menv)
{
	int		hmm;

	lock->lvl = 0;
	lock->selectmode = 0;
	while (1)
	{
		if (read(0, lock->buf, 1) == -1)
			ft_seeyoulater_bitch(menv, lock);
		lock->index = ft_getkey(lock->buf, lock);
		if (lock->index == -2)
			ft_newreadstuff(lock, pac, 1);
		else if (lock->index != -1)
		{
			if (!lock->search)
				hmm = ft_newreadcore(lock, pac, menv);
			else
				hmm = ft_newreadcore_2(lock, pac);
			if (hmm != -2)
				return (hmm);
			if (lock->search)
				ft_newread_3(lock, pac);
		}
	}
	return (0);
}
