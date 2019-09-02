/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activikey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:47:51 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/29 16:34:15 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_switchpress(t_keymaster *lock, t_stockap *pac, char *toswitch
	, int savepos)
{
	int	i;

	ft_printfd(0, "%s", pac->cd_cap);
	free(lock->out);
	if (!(lock->out = (char*)malloc(sizeof(char) * (ft_strlen(toswitch) + 1))))
		return (1);
	ft_strcpy(lock->out, toswitch);
	lock->lenout = ft_strlen(toswitch);
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
	return (0);
}

static int	ft_pressout(t_keymaster *lock, t_stockap *pac)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char)
		* (lock->lenout + ft_strlen(lock->presspap) + 1))))
		return (1);
	tmp[0] = 0;
	ft_strncpy(tmp, lock->out, lock->curspos - lock->promptsize);
	tmp[lock->curspos - lock->promptsize] = 0;
	ft_strcat(tmp, lock->presspap);
	ft_strcat(tmp, lock->out + lock->curspos - lock->promptsize);
	if (ft_switchpress(lock, pac, tmp, lock->curspos
		+ ft_strlen(lock->presspap)))
		return (1);
	free(tmp);
	return (0);
}

static int	ft_activkey_pt3(t_keymaster *lock, t_stockap *pac
	, t_masterenv *menv)
{
	if (lock->index == 50)
	{
		if (lock->presspap)
			ft_pressout(lock, pac);
	}
	if (lock->index == 51)
		ft_putatbegin(lock, pac);
	if (lock->index == 52)
		ft_putatend(lock, pac);
	if (lock->index == 53)
		return (ft_ctrlder(lock, pac, menv));
	if (lock->index == 54 && !lock->heremode)
		return (ft_cinquantequatre(lock, pac));
	if (lock->index == 54 && lock->heremode)
	{
		lock->index = 0;
		ft_memset(lock->buf, 0, 256);
		lock->buf[0] = 'R';
	}
	if (lock->index == 0 || lock->index == 101)
		return (ft_addcara(lock, pac));
	return (0);
}

static int	ft_activkey_pt2(t_keymaster *lock, t_stockap *pac
	, t_masterenv *menv)
{
	if (lock->index == 1)
		ft_goleft(lock, pac);
	if (lock->index == 2)
		ft_goright(lock, pac);
	if (lock->index == 11)
		ft_gobigleft(lock, pac);
	if (lock->index == 12)
		ft_gobigright(lock, pac);
	if (lock->index == 5 || lock->index == 6)
	{
		if (lock->hist.index == lock->hist.count && lock->hist.count > 0)
		{
			free(lock->hist.usercmd);
			lock->hist.usercmd = ft_strdup(lock->out);
		}
		if (lock->index == 5)
			ft_uphist(lock, pac);
		if (lock->index == 6)
			ft_downhist(lock, pac);
	}
	if (lock->index == 4)
		return (ft_delcara(lock, pac));
	return (ft_activkey_pt3(lock, pac, menv));
}

int			ft_activkey(t_keymaster *lock, t_stockap *pac, t_masterenv *menv)
{
	struct winsize sz;

	if ((ioctl(0, TIOCGWINSZ, &sz)) == -1)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m failed to find terminal size\n");
		return (1);
	}
	pac->nbcol = sz.ws_col;
	if (lock->aukprinted && lock->index < 100)
	{
		if (ft_pathter(lock, pac, lock->aukprinted))
			return (1);
		if (lock->index == 53)
			return (0);
	}
	if (lock->index == 101 && lock->aukprinted)
	{
		if (ft_pathter(lock, pac, (1 + lock->aukprinted)))
			return (1);
		return (0);
	}
	if (lock->index == 100)
		if (ft_autok(lock, pac, menv))
			return (1);
	return (ft_activkey_pt2(lock, pac, menv));
}
