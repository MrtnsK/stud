/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changeprompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:47:31 by kemartin          #+#    #+#             */
/*   Updated: 2019/07/29 14:38:09 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_lastprompt(t_keymaster *lock)
{
	if (lock->lastprompt == 1)
		return (ft_errorprompt(lock));
	if (lock->lastprompt == 2)
		return (ft_dquoteprompt(lock));
	if (lock->lastprompt == 3)
		return (ft_quoteprompt(lock));
	if (lock->lastprompt == 4)
		return (ft_mathprompt(lock));
	if (lock->lastprompt == 5)
		return (ft_mathdquoteprompt(lock));
	if (lock->lastprompt == 6)
		return (ft_mathquoteprompt(lock));
	if (lock->lastprompt == 7)
		return (ft_simpleprompt(lock));
	if (lock->lastprompt == 8)
		return (ft_hereprompt(lock));
	if (lock->lastprompt == 9)
		return (ft_searchprompt(lock));
	if (lock->lastprompt == 10)
		return (ft_braceprompt(lock));
	return (ft_masterprompt(lock));
}

int		ft_masterprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 24))))
		return (1);
	ft_strcpy(lock->prompt, "\e[96mMastershell\e[0m$> ");
	if (lock->curspos)
	{
		lock->curspos += 14 - lock->promptsize;
		lock->selpiv += 14 - lock->promptsize;
	}
	lock->promptsize = 14;
	lock->lastprompt = 0;
	return (0);
}

int		ft_cutprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 33))))
		return (1);
	ft_strcpy(lock->prompt, "\e[96mMaster\e[0m->\e[93mcut\e[0m$> ");
	if (lock->curspos)
	{
		lock->curspos += 14 - lock->promptsize;
		lock->selpiv += 14 - lock->promptsize;
	}
	lock->promptsize = 14;
	return (0);
}

int		ft_cpyprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 33))))
		return (1);
	ft_strcpy(lock->prompt, "\e[96mMaster\e[0m->\e[93mcpy\e[0m$> ");
	if (lock->curspos)
	{
		lock->curspos += 14 - lock->promptsize;
		lock->selpiv += 14 - lock->promptsize;
	}
	lock->promptsize = 14;
	return (0);
}

int		ft_errorprompt(t_keymaster *lock)
{
	lt_remove(lock->prompt);
	if (!(lock->prompt = (char*)lt_add(malloc(sizeof(char) * 24))))
		return (1);
	ft_strcpy(lock->prompt, "\e[93mMastershell\e[0m$> ");
	if (lock->curspos)
	{
		lock->curspos += 14 - lock->promptsize;
		lock->selpiv += 14 - lock->promptsize;
	}
	lock->promptsize = 14;
	lock->lastprompt = 1;
	return (0);
}
