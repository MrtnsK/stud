/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputstuffpt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:50:57 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/18 17:41:00 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_gobigleft(t_keymaster *lock, t_stockap *pac)
{
	if (!ft_isspace(lock->out[lock->curspos - lock->promptsize])
		&& ft_isspace(lock->out[lock->curspos - lock->promptsize - 1]))
		ft_goleft(lock, pac);
	while (ft_isspace(lock->out[lock->curspos - lock->promptsize])
		&& lock->curspos > lock->promptsize)
		ft_goleft(lock, pac);
	while (!ft_isspace(lock->out[lock->curspos - lock->promptsize])
		&& lock->curspos > lock->promptsize)
		ft_goleft(lock, pac);
	if (lock->curspos != lock->promptsize)
		ft_goright(lock, pac);
}

void	ft_gobigright(t_keymaster *lock, t_stockap *pac)
{
	while (ft_isspace(lock->out[lock->curspos - lock->promptsize])
		&& lock->curspos < (lock->lenout + lock->promptsize))
		ft_goright(lock, pac);
	while (!ft_isspace(lock->out[lock->curspos - lock->promptsize])
		&& lock->curspos < (lock->lenout + lock->promptsize))
		ft_goright(lock, pac);
}

void	ft_simpleputatend(t_keymaster *lock, t_stockap *pac)
{
	int i;

	i = lock->curspos;
	while (++i < (lock->lenout + 1 + lock->promptsize))
		ft_simplegoright(lock, pac);
}

int		ft_ctrlderopt(t_keymaster *lock)
{
	free(lock->out);
	if (!(lock->out = (char*)malloc(sizeof(char)
		* (ft_strlen(lock->sep) + 1))))
		return (1);
	ft_strcpy(lock->out, lock->sep);
	lock->lenout = ft_strlen(lock->out);
	lock->curspos += ft_strlen(lock->out);
	lock->index = 3;
	return (0);
}

int		ft_ctrlder(t_keymaster *lock, t_stockap *pac, t_masterenv *menv)
{
	if (lock->lenout == 0 && (lock->lastprompt == 0 || lock->lastprompt == 1))
	{
		free(lock->out);
		write(0, "\n", 1);
		menv->pipe = 0;
		menv->fg = 1;
		return (ft_exiter(menv, NULL, lock));
	}
	else if (lock->lastprompt == 8 && lock->lenout == 0)
		return (ft_ctrlderopt(lock));
	else if (lock->lenout
		&& lock->curspos != (lock->lenout + lock->promptsize))
	{
		ft_goright(lock, pac);
		return (ft_delcara(lock, pac));
	}
	return (ft_autok(lock, pac, menv));
}
