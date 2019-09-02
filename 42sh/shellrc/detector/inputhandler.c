/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:50:31 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/29 16:20:09 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_addcara(t_keymaster *lock, t_stockap *pac)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (lock->lenout + 1))))
		return (1);
	ft_strcpy(tmp, lock->out);
	free(lock->out);
	if (!(lock->out = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + 2))))
		return (1);
	ft_strncpy(lock->out, tmp, (lock->curspos - lock->promptsize));
	lock->out[(lock->curspos - lock->promptsize)] = 0;
	ft_strcat(lock->out, lock->buf);
	ft_strcat(lock->out, tmp + (lock->curspos - lock->promptsize));
	lock->lenout += 1;
	free(tmp);
	if (!lock->search)
		ft_addcaracursor(lock, pac);
	return (0);
}

void	ft_addcaracursor(t_keymaster *lock, t_stockap *pac)
{
	int i;
	int savepos;

	savepos = lock->curspos + 1;
	ft_printfd(0, "%s", pac->cd_cap);
	lock->lvl = (int)((lock->lenout + lock->promptsize) / pac->nbcol);
	ft_printfd(0, "%s", lock->out + lock->curspos - lock->promptsize);
	lock->curspos = lock->promptsize + lock->lenout;
	if ((lock->curspos % pac->nbcol) == 0)
	{
		lock->curspos -= 1;
		ft_simplegoright(lock, pac);
	}
	i = lock->curspos + 1;
	while (--i > savepos)
		ft_goleft(lock, pac);
}

int		ft_delcara(t_keymaster *lock, t_stockap *pac)
{
	char *tmp;

	if (lock->curspos <= lock->promptsize)
		return (0);
	if (!(tmp = (char*)malloc(sizeof(char) * (lock->lenout + 1))))
		return (1);
	ft_strcpy(tmp, lock->out);
	free(lock->out);
	if (!(lock->out = (char*)malloc(sizeof(char) * lock->lenout)))
		return (1);
	ft_strncpy(lock->out, tmp, (lock->curspos - lock->promptsize - 1));
	lock->out[(lock->curspos - lock->promptsize - 1)] = 0;
	if (tmp[(lock->curspos - lock->promptsize - 1)])
		ft_strcator(lock->out, tmp + (lock->curspos - lock->promptsize));
	lock->lenout -= 1;
	free(tmp);
	if (!lock->search)
		ft_delcaracursor(lock, pac);
	return (0);
}

void	ft_delcaracursor(t_keymaster *lock, t_stockap *pac)
{
	int i;
	int savepos;

	savepos = lock->curspos - 1;
	if ((lock->curspos % pac->nbcol) == 0)
	{
		ft_goleft(lock, pac);
		lock->curspos += 1;
	}
	else
		ft_printfd(0, "%s", pac->left_cap);
	ft_printfd(0, "%s", pac->cd_cap);
	lock->lvl = (int)((lock->lenout + lock->promptsize) / pac->nbcol);
	ft_printfd(0, "%s", lock->out + lock->curspos - lock->promptsize - 1);
	lock->curspos = lock->promptsize + lock->lenout;
	if ((lock->curspos % pac->nbcol) == 0 && lock->curspos != savepos)
	{
		lock->curspos -= 1;
		ft_simplegoright(lock, pac);
	}
	i = lock->curspos + 1;
	while (--i > savepos)
		ft_goleft(lock, pac);
}

void	ft_refreash(t_keymaster *lock, t_stockap *pac)
{
	int	savepos;
	int	i;

	savepos = lock->curspos;
	ft_putatbegin(lock, pac);
	i = -1;
	while (++i < 20)
		ft_printfd(0, "%s", pac->left_cap);
	ft_printfd(0, "%s", pac->cd_cap);
	lock->lvl = (int)((lock->lenout + lock->promptsize) / pac->nbcol);
	ft_printfd(0, "%s%s", lock->prompt, lock->out);
	lock->curspos = lock->promptsize + lock->lenout;
	if ((lock->curspos % pac->nbcol) == 0)
	{
		lock->curspos -= 1;
		ft_simplegoright(lock, pac);
	}
	i = lock->curspos + 1;
	while (--i > savepos)
		ft_goleft(lock, pac);
}
