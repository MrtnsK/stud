/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer_pt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:28:00 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/19 11:43:03 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_stock(t_masterenv *menv, int i)
{
	while (menv->internal_var[0][++i])
	{
		if (ft_strcmp("USER", menv->internal_var[0][i]) == -61)
			menv->rep[0] = i;
		if (ft_strcmp("PWD", menv->internal_var[0][i]) == -61)
			menv->rep[1] = i;
		if (ft_strcmp("OLDPWD", menv->internal_var[0][i]) == -61)
			menv->rep[2] = i;
		if (ft_strcmp("HOME", menv->internal_var[0][i]) == -61)
			menv->rep[3] = i;
		if (ft_strcmp("PATH", menv->internal_var[0][i]) == -61)
			menv->rep[4] = i;
	}
}

void	ft_stock2(t_masterenv *menv)
{
	int		k;
	int		j;

	k = -1;
	while (menv->stock[0][++k])
		;
	j = 5;
	while (--j >= 0)
		menv->repe[j] = k;
	while (menv->stock[0][++j])
	{
		if (ft_strcmp("USER", menv->stock[0][j]) == -61)
			menv->repe[0] = j;
		if (ft_strcmp("PWD", menv->stock[0][j]) == -61)
			menv->repe[1] = j;
		if (ft_strcmp("OLDPWD", menv->stock[0][j]) == -61)
			menv->repe[2] = j;
		if (ft_strcmp("HOME", menv->stock[0][j]) == -61)
			menv->repe[3] = j;
		if (ft_strcmp("PATH", menv->stock[0][j]) == -61)
			menv->repe[4] = j;
	}
}

char	*ft_inirep_pt2(int option, t_masterenv *menv, char *save)
{
	if (ft_inenvremplissor(menv))
		return ("a");
	if (menv->internal_var[0][menv->rep[4]]
	&& ft_strcmp(menv->internal_var[0][menv->rep[4]], save)
		&& option != 2)
	{
		lt_remove(save);
		if (!(save = (char*)lt_add(malloc(sizeof(char)
			* (ft_strlen(menv->internal_var[0][menv->rep[4]]) + 1)))))
			save = 0;
		if (save)
			ft_strcpy(save, menv->internal_var[0][menv->rep[4]]);
		if (ft_fctsremplissor(menv))
			return ("a");
	}
	else if (!menv->internal_var[0][menv->rep[4]] && option != 2)
	{
		lt_remove(save);
		if (!(save = (char*)lt_add(malloc(sizeof(char)))))
			save = 0;
		save[0] = 0;
		if (ft_refcts(menv))
			return ("a");
	}
	return (save);
}
