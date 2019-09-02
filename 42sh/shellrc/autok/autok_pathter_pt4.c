/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autok_pathter_pt4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:13:45 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:13:47 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_pathter_inenvchoice_end(t_keymaster *lock, t_stockap *pac
	, int i)
{
	ft_refreash(lock, pac);
	lock->aukprinted = 0;
	i = -1;
	while (lock->stock.output[++i])
		free(lock->stock.output[i]);
	free(lock->stock.output);
	free(lock->fullname);
	free(lock->final);
	ft_addcompletion(lock, pac);
	return (0);
}

int			ft_pathter_inenvchoice(t_keymaster *lock, t_stockap *pac, int i)
{
	if (!(lock->fullname = (char*)malloc(sizeof(char)
		* (ft_strlen(lock->stock.output[lock->stock.select]) + 1))))
		return (1);
	ft_strcpy(lock->fullname, lock->stock.output[lock->stock.select]);
	if (!ft_strcmp(lock->stock.output[lock->stock.select], lock->final))
	{
		if (!(lock->complete = (char*)malloc(sizeof(char) * 3)))
			return (1);
		lock->complete[0] = '}';
		lock->complete[1] = ' ';
		lock->complete[2] = 0;
	}
	else
	{
		if (!(lock->complete = (char*)malloc(sizeof(char)
			* (3 + ft_strlen(lock->stock.output[lock->stock.select])
				- ft_strlen(lock->final)))))
			return (1);
		ft_strcpy(lock->complete, lock->stock.output[lock->stock.select]
			+ ft_strlen(lock->final));
		ft_strcat(lock->complete, "} ");
	}
	return (ft_pathter_inenvchoice_end(lock, pac, i));
}
