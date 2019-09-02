/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changeprompt_pt2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:49:51 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:49:53 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_dquoteprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 18))))
		return (1);
	ft_strcpy(lock->prompt, "\e[93mdquote\e[0m> ");
	if (lock->curspos)
	{
		lock->curspos += 8 - lock->promptsize;
		lock->selpiv += 8 - lock->promptsize;
	}
	lock->promptsize = 8;
	lock->lastprompt = 2;
	return (0);
}

int		ft_quoteprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 17))))
		return (1);
	ft_strcpy(lock->prompt, "\e[93mquote\e[0m> ");
	if (lock->curspos)
	{
		lock->curspos += 7 - lock->promptsize;
		lock->selpiv += 7 - lock->promptsize;
	}
	lock->promptsize = 7;
	lock->lastprompt = 3;
	return (0);
}

int		ft_mathprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 21))))
		return (1);
	ft_strcpy(lock->prompt, "\e[93mmathsubst\e[0m> ");
	if (lock->curspos)
	{
		lock->curspos += 11 - lock->promptsize;
		lock->selpiv += 11 - lock->promptsize;
	}
	lock->promptsize = 11;
	lock->lastprompt = 4;
	return (0);
}

int		ft_mathquoteprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 27))))
		return (1);
	ft_strcpy(lock->prompt, "\e[93mquote mathsubst\e[0m> ");
	if (lock->curspos)
	{
		lock->curspos += 17 - lock->promptsize;
		lock->selpiv += 17 - lock->promptsize;
	}
	lock->promptsize = 17;
	lock->lastprompt = 6;
	return (0);
}

int		ft_mathdquoteprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 28))))
		return (1);
	ft_strcpy(lock->prompt, "\e[93mdquote mathsubst\e[0m> ");
	if (lock->curspos)
	{
		lock->curspos += 18 - lock->promptsize;
		lock->selpiv += 18 - lock->promptsize;
	}
	lock->promptsize = 18;
	lock->lastprompt = 5;
	return (0);
}
