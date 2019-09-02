/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgetbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:51:05 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 11:51:04 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_newgetbuf_pt3(t_keymaster *lock, t_stockap *pac
	, t_masterenv *menv)
{
	lock->out[0] = 0;
	free(lock->out);
	if (lock->heremode)
	{
		free(lock->sep);
		lock->sep = NULL;
		lock->herelvl += 1;
		return (ft_unfinishedlauncher(pac, lock, menv));
	}
	ft_addtohist(g_ultib, lock);
	return (ft_unfinished(pac, lock, menv));
}

int			ft_herror2(t_keymaster *lock)
{
	free(lock->sep);
	lock->sep = NULL;
	lock->out[0] = 0;
	free(lock->out);
	ft_printfd(2, "nice try, but not this time\n");
	return (-1);
}

int			ft_newgetbuf_pt2(char **buf, t_keymaster *lock, t_stockap *pac
	, t_masterenv *menv)
{
	int	fd_file;

	if (lock->heremode == 0)
	{
		if (ft_bufator(buf, lock->out))
			return (1);
	}
	else
	{
		if (ft_strcmp(lock->out, lock->sep))
		{
			if ((fd_file = open(lock->pathfile, O_RDWR | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR)) == -1)
				return (ft_herror2(lock));
			ft_printfd(fd_file, "%s\n", lock->out);
			close(fd_file);
			lock->out[0] = 0;
			free(lock->out);
			return (ft_unfinishedlauncher(pac, lock, menv));
		}
	}
	return (ft_newgetbuf_pt3(lock, pac, menv));
}

int			ft_newgetbuf(char **buf, t_keymaster *lock, t_stockap *pac
	, t_masterenv *menv)
{
	ft_printfd(0, "%s", lock->prompt);
	if (!(lock->out = (char*)malloc(sizeof(char))))
		return (1);
	lock->out[0] = 0;
	lock->lenout = 0;
	lock->curspos = lock->promptsize;
	lock->aukprinted = 0;
	if (ft_newread(lock, pac, menv))
		return (1);
	return (ft_newgetbuf_pt2(buf, lock, pac, menv));
}
