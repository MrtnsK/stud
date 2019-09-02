/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autok_pather_pt2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:46:21 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:46:24 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_pather_1opt(t_keymaster *lock, int i)
{
	i = -1;
	while (lock->contdir[++i])
		if (ft_strchrstrfirst(lock->contdir[i], lock->final))
		{
			if (!(lock->fullname = (char*)malloc(sizeof(char)
				* (ft_strlen(lock->tmp) + ft_strlen(lock->contdir[i]) + 2))))
				return (1);
			ft_strcpy(lock->fullname, lock->tmp);
			ft_strcat(lock->fullname, "/");
			ft_strcat(lock->fullname, lock->contdir[i]);
			if (is_truedir(lock->fullname))
			{
				if (ft_pather_1opt_dir(lock, i))
					return (1);
			}
			else
			{
				if (ft_pather_1opt_file(lock, i))
					return (1);
			}
			ft_pather_free(lock);
			break ;
		}
	return (0);
}

static int	ft_pather_multiopt(t_keymaster *lok, int i)
{
	if (!(lok->stock.output = (char**)malloc(sizeof(char*)
		* (lok->nb_auto + 1))))
		return (1);
	lok->stock.output[lok->nb_auto] = 0;
	lok->stock.argc = lok->nb_auto;
	lok->stock.select = 0;
	i = -1;
	lok->nb_auto = 0;
	while (lok->contdir[++i])
		if (ft_strchrstrfirst(lok->contdir[i], lok->final))
		{
			if (!(lok->stock.output[lok->nb_auto] =
					(char*)malloc(sizeof(char)
						* (ft_strlen(lok->contdir[i]) + 1))))
				return (1);
			ft_strcpy(lok->stock.output[lok->nb_auto], lok->contdir[i]);
			lok->nb_auto += 1;
		}
	return (0);
}

static int	ft_pather_multioptbasic(t_keymaster *lock, t_stockap *pac, int i)
{
	int			savepos;
	t_basiks	tools;

	savepos = lock->curspos;
	ft_simpleputatend(lock, pac);
	ft_printfd(0, "\n");
	if (ft_basic(&lock->stock, pac, &tools, lock))
		return (1);
	lock->aukprinted = 1;
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

int			ft_pather_end(t_keymaster *lock, t_stockap *pac, int i)
{
	if (lock->nb_auto == 1)
	{
		if (ft_pather_1opt(lock, i))
			return (1);
	}
	else if (lock->nb_auto > 1)
	{
		if (ft_pather_multiopt(lock, i))
			return (1);
		if (ft_pather_multioptbasic(lock, pac, i))
			return (1);
	}
	i = -1;
	while (lock->contdir[++i])
		free(lock->contdir[i]);
	free(lock->contdir);
	if (lock->nb_auto == 1)
		ft_addcompletion(lock, pac);
	if (lock->nb_auto == 0)
	{
		free(lock->final);
		free(lock->tmp);
	}
	return (0);
}

int			ft_autokerbis(t_keymaster *lock, t_stockap *pac, int mode
	, t_masterenv *menv)
{
	char		*tmp;

	if (mode)
	{
		if (!(lock->tmp = (char*)malloc(sizeof(char) * 3)))
			return (1);
		ft_strcpy(lock->tmp, "./");
		return (ft_pather(lock, pac, menv));
	}
	if (!(tmp = (char*)malloc(sizeof(char)
		* (ft_strlen(lock->tmp) + 1))))
		return (1);
	ft_strcpy(tmp, lock->tmp);
	free(lock->tmp);
	if (!(lock->tmp = (char*)malloc(sizeof(char)
		* (ft_strlen(tmp) + 3))))
		return (1);
	ft_strcpy(lock->tmp, "./");
	ft_strcat(lock->tmp, tmp);
	free(tmp);
	return (ft_pather(lock, pac, menv));
}
