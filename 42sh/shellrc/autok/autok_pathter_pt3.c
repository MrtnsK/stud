/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autok_pathter_pt3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:46:56 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:46:58 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_pathter_pathchoice_dir(t_keymaster *lock)
{
	if (!ft_strcmp(lock->stock.output[lock->stock.select], lock->final))
	{
		if (!(lock->complete = (char*)malloc(sizeof(char) * 2)))
			return (1);
		lock->complete[0] = '/';
		lock->complete[1] = 0;
	}
	else
	{
		if (!(lock->complete = (char*)malloc(sizeof(char)
			* (2 + ft_strlen(lock->stock.output[lock->stock.select])
				- ft_strlen(lock->final)))))
			return (1);
		ft_strcpy(lock->complete, lock->stock.output[lock->stock.select]
			+ ft_strlen(lock->final));
		ft_strcat(lock->complete, "/");
	}
	return (0);
}

int			ft_pathter_pathchoice_file(t_keymaster *lock)
{
	if (!ft_strcmp(lock->stock.output[lock->stock.select], lock->final))
	{
		if (!(lock->complete = (char*)malloc(sizeof(char) * 2)))
			return (1);
		lock->complete[0] = ' ';
		lock->complete[1] = 0;
	}
	else
	{
		if (!(lock->complete = (char*)malloc(sizeof(char)
			* (2 + ft_strlen(lock->stock.output[lock->stock.select])
				- ft_strlen(lock->final)))))
			return (1);
		ft_strcpy(lock->complete, lock->stock.output[lock->stock.select]
			+ ft_strlen(lock->final));
		ft_strcat(lock->complete, " ");
	}
	return (0);
}

int			ft_autoker(t_keymaster *lock, t_stockap *pac, int mode
	, t_masterenv *menv)
{
	int			i;
	int			j;

	if (lock->aukprinted)
		return (ft_pathter(lock, pac, 0));
	if (mode == 1)
		return (ft_autokerbis(lock, pac, 1, menv));
	i = (lock->curspos - lock->promptsize);
	j = i;
	while (--i >= 0 && !ft_isspace(lock->out[i]))
		;
	i++;
	if (!(lock->tmp = (char*)malloc(sizeof(char) * (j - i + 1))))
		return (1);
	ft_strncpy(lock->tmp, lock->out + i, (j - i));
	lock->tmp[j - i] = 0;
	if (lock->tmp[0] == '$' && lock->tmp[1] && lock->tmp[2]
		&& lock->tmp[1] == '{' && lock->tmp[2] != '{')
		return (ft_inenver(lock, pac));
	if (ft_strchr(lock->tmp, '/'))
		return (ft_pather(lock, pac, menv));
	if (!ft_iscommand(lock) && ft_strnchralpha(lock->out, i))
		return (ft_autokerbis(lock, pac, 0, menv));
	return (ft_commander(lock, pac));
}

int			ft_maxfinder_ender(t_basiks *tools, struct winsize w)
{
	tools->lignemax = 0;
	while ((tools->lignemax * tools->max) < w.ws_col)
		tools->lignemax += 1;
	if ((tools->lignemax * tools->max) > w.ws_col)
		tools->lignemax -= 1;
	return (0);
}
