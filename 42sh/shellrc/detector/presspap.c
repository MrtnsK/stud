/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presspap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:51:27 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:51:29 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_savepresspap_pt2(t_keymaster *lock, t_stockap *pac)
{
	if (lock->selectmode == 2 && (lock->curspos < lock->selpiv))
	{
		lock->out[lock->curspos - lock->promptsize] = 0;
		ft_strcator(lock->out, lock->out + lock->selpiv - lock->promptsize);
		lock->lenout = ft_strlen(lock->out);
	}
	else if (lock->selectmode == 2)
	{
		lock->out[lock->selpiv - lock->promptsize] = 0;
		ft_strcator(lock->out, lock->out + lock->curspos - lock->promptsize);
		lock->lenout = ft_strlen(lock->out);
	}
	lock->selectmode = 0;
	ft_lastprompt(lock);
	ft_refreash(lock, pac);
	return (0);
}

int			ft_savepresspap(t_keymaster *lock, t_stockap *pac)
{
	int len;

	if (lock->presspap)
		free(lock->presspap);
	if (lock->curspos < lock->selpiv)
		len = lock->selpiv - lock->curspos;
	else
		len = lock->curspos - lock->selpiv;
	if (len == 0)
		lock->presspap = 0;
	if (!(lock->presspap = (char*)malloc(sizeof(char) * (len + 1))))
		return (1);
	lock->presspap[len] = 0;
	if (lock->curspos < lock->selpiv)
		ft_strncpy(lock->presspap, lock->out
			+ lock->curspos - lock->promptsize, len);
	else
		ft_strncpy(lock->presspap, lock->out
			+ lock->selpiv - lock->promptsize, len);
	return (ft_savepresspap_pt2(lock, pac));
}
