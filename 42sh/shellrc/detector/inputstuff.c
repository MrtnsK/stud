/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputstuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:50:46 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:50:49 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_goleft(t_keymaster *lock, t_stockap *pac)
{
	int i;

	if (lock->curspos <= lock->promptsize)
		return ;
	if ((lock->curspos % pac->nbcol) == 0)
	{
		ft_printfd(0, "%s", pac->up_cap);
		i = -1;
		while (++i < pac->nbcol)
			ft_printfd(0, "%s", pac->right_cap);
	}
	else
		ft_printfd(0, "%s", pac->left_cap);
	lock->curspos -= 1;
}

void	ft_simplegoright(t_keymaster *lock, t_stockap *pac)
{
	if ((lock->curspos % pac->nbcol) == (pac->nbcol - 1))
		ft_printfd(0, "%s", pac->down_cap);
	else
		ft_printfd(0, "%s", pac->right_cap);
	lock->curspos += 1;
}

void	ft_goright(t_keymaster *lock, t_stockap *pac)
{
	if (lock->curspos >= (lock->lenout + lock->promptsize))
		return ;
	if ((lock->curspos % pac->nbcol) == (pac->nbcol - 1))
		ft_printfd(0, "%s", pac->down_cap);
	else
		ft_printfd(0, "%s", pac->right_cap);
	lock->curspos += 1;
}

void	ft_putatend(t_keymaster *lock, t_stockap *pac)
{
	int i;

	i = lock->curspos;
	while (++i < (lock->lenout + 1 + lock->promptsize))
		ft_goright(lock, pac);
}

void	ft_putatbegin(t_keymaster *lock, t_stockap *pac)
{
	while (lock->curspos > lock->promptsize)
		ft_goleft(lock, pac);
}
