/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:50:07 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:50:08 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_getkey_select(t_keymaster *lock, int opt)
{
	if (lock->selectmode)
	{
		lock->selectmode = 0;
		ft_lastprompt(lock);
	}
	else if (opt == 1)
	{
		lock->selectmode = 1;
		lock->selpiv = lock->curspos;
		ft_cpyprompt(lock);
	}
	else
	{
		lock->selectmode = 2;
		lock->selpiv = lock->curspos;
		ft_cutprompt(lock);
	}
	return (-2);
}

static int	ft_getkey_pt3(char *buf)
{
	if (buf[0] == '\t' && buf[1] == 0)
		return (100);
	if (buf[0] == '\n' && buf[1] == 0)
		return (3);
	if (buf[0] == 127 && buf[1] == 0)
		return (4);
	if (buf[0] == ' ' && buf[1] == 0)
		return (101);
	if (ft_isprint(buf[0]) && buf[1] == 0)
		return (0);
	return (-2);
}

static int	ft_getkey_pt2(char *buf, t_keymaster *lock)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 70 && buf[3] == 0)
		return (52);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59
		&& buf[4] == 50 && buf[5] == 65 && buf[6] == 0)
		return (50);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59
		&& buf[4] == 50 && buf[5] == 67 && buf[6] == 0)
		return (ft_getkey_select(lock, 1));
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59
		&& buf[4] == 50 && buf[5] == 68 && buf[6] == 0)
		return (ft_getkey_select(lock, 0));
	if ((buf[0] == 27 && buf[1] == 91 && buf[2] == 0)
		|| (buf[0] == 27 && buf[1] == 0)
		|| (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 0)
		|| (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59
		&& buf[4] == 0) || (buf[0] == 27 && buf[1] == 91 && buf[2] == 49
		&& buf[3] == 59 && buf[4] == 50 && buf[5] == 0) || (buf[0] == -30
		&& buf[1] == 0) || (buf[0] == -30 && buf[1] == -105 && buf[2] == 0))
	{
		ft_memset(lock->bigbuf, 0, 256);
		ft_strcpy(lock->bigbuf, buf);
		ft_memset(lock->buf, 0, 256);
		return (-1);
	}
	return (ft_getkey_pt3(buf));
}

int			ft_getkey(char *buf, t_keymaster *lock)
{
	if (lock->bigbuf[0])
	{
		ft_strcat(lock->bigbuf, buf);
		ft_memset(buf, 0, 256);
		ft_strcpy(buf, lock->bigbuf);
	}
	if (buf[0] == 18 && buf[1] == 0)
		return (54);
	if (buf[0] == 4 && buf[1] == 0)
		return (53);
	if (buf[0] == 27 && buf[1] == 102 && buf[2] == 0)
		return (12);
	if (buf[0] == 27 && buf[1] == 98 && buf[2] == 0)
		return (11);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
		return (1);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
		return (2);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && buf[3] == 0)
		return (5);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && buf[3] == 0)
		return (6);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 72 && buf[3] == 0)
		return (51);
	return (ft_getkey_pt2(buf, lock));
}
