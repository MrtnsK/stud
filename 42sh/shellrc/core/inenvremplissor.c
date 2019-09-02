/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inenvremplissor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:00:31 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/18 16:18:27 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_inenvfill(t_masterenv *menv, int j)
{
	int		i;
	int		lim;

	i = -1;
	while (menv->internal_var[0][++j])
	{
		lim = ft_strchri(menv->internal_var[0][j], '=');
		if (!(menv->inenv[0][++i] =
		ft_strsub(menv->internal_var[0][j], 0, lim)))
		{
			menv->inenv[0] = 0;
			return (-1);
		}
	}
	return (i);
}

int			ft_inenvremplissor(t_masterenv *menv)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	j = -1;
	while (menv->inenv[0][++i])
		free(menv->inenv[0][i]);
	lt_remove(menv->inenv[0]);
	size = ft_tablen(menv->internal_var[0]) + 1;
	if (!(menv->inenv[0] = (char**)lt_add(malloc(sizeof(char*) * size))))
	{
		menv->inenv[0] = 0;
		return (1);
	}
	if ((i = ft_inenvfill(menv, j)) == -1)
	{
		menv->inenv[0] = 0;
		return (1);
	}
	menv->inenv[0][size - 1] = 0;
	return (0);
}
