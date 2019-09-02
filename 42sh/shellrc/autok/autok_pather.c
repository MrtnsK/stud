/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autok_pather.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:46:12 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:25:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_pather_pt1_spe(t_keymaster *lock, int i, t_masterenv *menv)
{
	if (i > 0 && !ft_isspace(lock->tmp[i - 1]))
	{
		free(lock->tmp);
		return (-2);
	}
	if (!menv->internal_var[0][menv->rep[3]])
	{
		free(lock->tmp);
		return (-2);
	}
	if (ft_switcher(&lock->tmp, i, menv))
		return (-1);
	return (ft_pather_pt1(lock, menv));
}

int			ft_pather_pt1(t_keymaster *lock, t_masterenv *menv)
{
	int		i;
	int		len;

	i = -1;
	while (lock->tmp[++i])
		if (lock->tmp[i] == '~')
			return (ft_pather_pt1_spe(lock, i, menv));
	while (lock->tmp[--i] != '/')
		;
	if (lock->tmp[i + 1])
	{
		len = ft_strlen(lock->tmp + i + 1);
		if (!(lock->final = (char*)malloc(sizeof(char) * (len + 1))))
			return (-1);
		ft_strcpy(lock->final, lock->tmp + i + 1);
		lock->tmp[i + 1] = 0;
	}
	else
	{
		if (!(lock->final = (char*)malloc(sizeof(char))))
			return (-1);
		lock->final[0] = 0;
	}
	return (i);
}

int			ft_pather(t_keymaster *lock, t_stockap *pac, t_masterenv *menv)
{
	int			i;

	i = ft_pather_pt1(lock, menv);
	if (i == -1)
		return (1);
	if (i == -2)
		return (0);
	if (i > 0 && lock->tmp[i - 1] == '/')
		return (ft_pather_pakoul(lock));
	if (i != 0)
		lock->tmp[i] = 0;
	if (!is_truedir(lock->tmp))
		return (ft_pather_pakoul(lock));
	if ((i = ft_outputfiller(lock)) != -1)
		return (i);
	lock->nb_auto = 0;
	while (lock->contdir[++i])
	{
		if (ft_strchrstrfirst(lock->contdir[i], lock->final))
			lock->nb_auto += 1;
	}
	return (ft_pather_end(lock, pac, i));
}

int			ft_iscommand(t_keymaster *lock)
{
	int	i;
	int check;
	int	cpts;

	i = lock->curspos - lock->promptsize;
	cpts = 0;
	check = 1;
	while (--i >= 0 && lock->out[i] != ';' && lock->out[i] != '|')
	{
		if (check == 0 && !ft_isspace(lock->out[i]))
		{
			cpts++;
			check = 1;
		}
		if (check == 1 && ft_isspace(lock->out[i]))
			check = 0;
	}
	if (cpts > 0)
		return (0);
	return (1);
}
