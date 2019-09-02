/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newread_pt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:22:31 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 10:22:33 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_newreadcore_2core_1(t_keymaster *lock, t_stockap *pac)
{
	ft_memset(lock->buf, 0, 256);
	lock->search = 0;
	lock->out[0] = 0;
	ft_masterprompt(lock);
	ft_mutant_refreash(lock->curspos + ft_strlen(lock->rechist) + 4, pac);
	ft_printfd(0, "%s", lock->prompt);
	lock->curspos = lock->promptsize;
	lock->lenout = 0;
	free(lock->rechist);
	lock->rechist = NULL;
	return (-2);
}

static int	ft_newreadcore_2core_2(t_keymaster *lock, t_stockap *pac)
{
	ft_mutant_refreash(lock->curspos + ft_strlen(lock->rechist) + 4, pac);
	ft_printfd(0, "%s", lock->prompt);
	free(lock->out);
	if (!(lock->out = (char*)malloc(sizeof(char)
		* (ft_strlen(lock->rechist) + 1))))
		return (1);
	if (!lock->rechist)
	{
		ft_mutant_refreash(lock->curspos + 1, pac);
		return (0);
	}
	ft_strcpy(lock->out, lock->rechist);
	ft_printfd(0, ": %s\n", lock->out);
	free(lock->rechist);
	return (0);
}

int			ft_newreadcore_2(t_keymaster *lock, t_stockap *pac)
{
	ft_memset(lock->bigbuf, 0, 256);
	if (lock->index != 0 && lock->index != 3 && lock->index != 4
		&& lock->index != 101)
		return (ft_newreadcore_2core_1(lock, pac));
	if (ft_activkey_2(lock, pac))
		return (1);
	if (lock->index != 3)
		ft_memset(lock->buf, 0, 256);
	else
		return (ft_newreadcore_2core_2(lock, pac));
	return (-2);
}
