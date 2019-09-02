/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activikey_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:22:46 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 10:22:47 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_activkey_2(t_keymaster *lock, t_stockap *pac)
{
	struct winsize sz;

	if ((ioctl(0, TIOCGWINSZ, &sz)) == -1)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m failed to find terminal size\n");
		return (1);
	}
	pac->nbcol = sz.ws_col;
	if (lock->index == 0 || lock->index == 101)
	{
		ft_addcara(lock, pac);
		lock->curspos = lock->curspos + 1;
	}
	if (lock->index == 4)
	{
		ft_delcara(lock, pac);
		if (lock->curspos > lock->promptsize)
			lock->curspos = lock->curspos - 1;
	}
	return (0);
}

int	ft_cinquantequatre(t_keymaster *lock, t_stockap *pac)
{
	lock->search = 1;
	lock->out[0] = 0;
	ft_memset(lock->buf, 0, 256);
	ft_memset(lock->bigbuf, 0, 256);
	ft_searchprompt(lock);
	ft_putatend(lock, pac);
	ft_mutant_refreash(lock->curspos + 1, pac);
	ft_printfd(0, "%s", lock->prompt);
	lock->curspos = lock->promptsize;
	lock->lenout = 0;
	return (0);
}
