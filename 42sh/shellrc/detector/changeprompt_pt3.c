/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changeprompt_pt3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:49:59 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:50:01 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_simpleprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 3))))
		return (1);
	ft_strcpy(lock->prompt, "> ");
	if (lock->curspos)
	{
		lock->curspos += 2 - lock->promptsize;
		lock->selpiv += 2 - lock->promptsize;
	}
	lock->promptsize = 2;
	lock->lastprompt = 7;
	return (0);
}

int		ft_hereprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 10))))
		return (1);
	ft_strcpy(lock->prompt, "heredoc> ");
	if (lock->curspos)
	{
		lock->curspos += 9 - lock->promptsize;
		lock->selpiv += 9 - lock->promptsize;
	}
	lock->promptsize = 9;
	lock->lastprompt = 8;
	return (0);
}

int		ft_searchprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 25))))
		return (1);
	ft_strcpy(lock->prompt, "\e[0;32mMastersearch\e[0m ");
	if (lock->curspos)
	{
		lock->curspos += 13 - lock->promptsize;
		lock->selpiv += 13 - lock->promptsize;
	}
	lock->promptsize = 13;
	lock->lastprompt = 9;
	return (0);
}

int		ft_braceprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 13))))
		return (1);
	ft_strcpy(lock->prompt, "braceparam> ");
	if (lock->curspos)
	{
		lock->curspos += 13 - lock->promptsize;
		lock->selpiv += 13 - lock->promptsize;
	}
	lock->promptsize = 12;
	lock->lastprompt = 10;
	return (0);
}
