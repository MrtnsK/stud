/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:45:47 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:45:52 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_nbdir(t_keymaster *lock)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	int				j;

	if (!is_truedir(lock->tmp))
		return (0);
	pdir = opendir(lock->tmp);
	if (pdir == NULL)
		return (0);
	j = 1;
	while ((pdirent = readdir(pdir)) != NULL)
		j++;
	if (!(lock->contdir = (char**)malloc(sizeof(char*) * j)))
	{
		closedir(pdir);
		return (1);
	}
	lock->contdir[j - 1] = 0;
	closedir(pdir);
	return (0);
}

int			ft_outputfiller(t_keymaster *lock)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	int				l;
	int				j;

	if (ft_nbdir(lock))
		return (1);
	pdir = opendir(lock->tmp);
	if (pdir == NULL)
		return (jpp(lock));
	j = 0;
	while ((pdirent = readdir(pdir)) != NULL)
	{
		l = ft_strlen(pdirent->d_name);
		if (!(lock->contdir[j] = (char*)malloc(sizeof(char) * (l + 1))))
		{
			closedir(pdir);
			return (1);
		}
		lock->contdir[j][l] = 0;
		lock->contdir[j] = ft_strcpy(lock->contdir[j], pdirent->d_name);
		j++;
	}
	closedir(pdir);
	return (-1);
}

static int	ft_addcompletion_pt2(t_keymaster *lock, t_stockap *pac)
{
	int i;
	int savepos;

	lock->lvl = (int)((lock->lenout + lock->promptsize) / pac->nbcol);
	i = lock->curspos;
	savepos = i + ft_strlen(lock->complete);
	free(lock->complete);
	while (++i < (lock->lenout + 1 + lock->promptsize))
		ft_simplegoright(lock, pac);
	i = -1;
	while (++i < lock->lvl)
		ft_printfd(0, "%s%s", pac->dl_cap, pac->up_cap);
	ft_printfd(0, "%s", pac->dl_cap);
	i = -1;
	while (++i < pac->nbcol)
		ft_printfd(0, "%s", pac->left_cap);
	lock->lvl = (int)((lock->lenout + lock->promptsize) / pac->nbcol);
	ft_printfd(0, "%s", pac->savecurs_cap);
	ft_printfd(0, "%s%s%s", lock->prompt, lock->out, pac->backurs_cap);
	lock->curspos = 0;
	i = -1;
	while (++i < savepos)
		ft_simplegoright(lock, pac);
	lock->curspos = savepos;
	return (0);
}

int			ft_addcompletion(t_keymaster *lock, t_stockap *pac)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (lock->lenout + 1))))
		return (1);
	ft_strcpy(tmp, lock->out);
	free(lock->out);
	if (!(lock->out = (char*)malloc(sizeof(char) * (ft_strlen(tmp)
		+ ft_strlen(lock->complete) + 1))))
		return (1);
	ft_strncpy(lock->out, tmp, (lock->curspos - lock->promptsize));
	lock->out[(lock->curspos - lock->promptsize)] = 0;
	ft_strcat(lock->out, lock->complete);
	ft_strcat(lock->out, tmp + (lock->curspos - lock->promptsize));
	lock->lenout += ft_strlen(lock->complete);
	free(tmp);
	return (ft_addcompletion_pt2(lock, pac));
}

int			ft_autok(t_keymaster *lock, t_stockap *pac, t_masterenv *menv)
{
	if ((lock->curspos - lock->promptsize - 1) > -1
		&& !ft_isspace(lock->out[lock->curspos - lock->promptsize - 1])
		&& !ft_isspace(lock->out[lock->curspos - lock->promptsize]))
		ft_gobigright(lock, pac);
	else if ((lock->curspos - lock->promptsize - 1) > -1
		&& !ft_isspace(lock->out[lock->curspos - lock->promptsize - 1])
		&& ft_isspace(lock->out[lock->curspos - lock->promptsize]))
		;
	else if ((lock->curspos - lock->promptsize - 1) > -1
		&& ft_isspace(lock->out[lock->curspos - lock->promptsize - 1])
		&& ft_strchralpha(lock->out) && !ft_iscommand(lock))
		return (ft_autoker(lock, pac, 1, menv));
	else
		return (0);
	return (ft_autoker(lock, pac, 0, menv));
}
