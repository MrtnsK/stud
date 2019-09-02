/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:37:55 by pharatyk          #+#    #+#             */
/*   Updated: 2019/06/26 13:07:26 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_findfctscript(char **tmp)
{
	free(tmp[0]);
	tmp[0] = NULL;
}

int			ft_unsetenver(t_masterenv *menv, int i, char **tenv, int k)
{
	k = -1;
	while (menv->stock[0][++k])
		;
	if (!(tenv = (char**)malloc(sizeof(char*) * (k + 1))))
		return (1);
	tenv[k] = 0;
	k = -1;
	while (menv->stock[0][++k])
		tenv[k] = menv->stock[0][k];
	free(menv->stock[0][i]);
	free(menv->stock[0]);
	if (!(menv->stock[0] = (char**)malloc(sizeof(char*) * (k))))
		return (1);
	menv->stock[0][--k] = 0;
	k = -1;
	while (++k < i)
		menv->stock[0][k] = tenv[k];
	while (tenv[++k])
		menv->stock[0][k - 1] = tenv[k];
	free(tenv);
	ft_inirep(menv, 0);
	return (0);
}

int			ft_unsetenv(t_masterenv *menv, char **opt)
{
	int		i;
	int		j;
	int		k;
	char	**tenv;

	tenv = NULL;
	k = 0;
	if (ft_tablen(opt) > 1)
	{
		j = 0;
		while (opt[++j])
		{
			i = -1;
			while (menv->stock[0][++i]
				&& ft_strcmp(opt[j], menv->stock[0][i]) != -61)
				;
			if (menv->stock[0][i])
				if (ft_unsetenver(menv, i, tenv, k))
					return (1);
		}
	}
	ft_inirep(menv, 0);
	return (0);
}
