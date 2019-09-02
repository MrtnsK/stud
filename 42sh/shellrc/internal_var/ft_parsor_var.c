/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsor_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:41:55 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/03 11:41:48 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_add_to_intern_var(t_masterenv *menv, int i)
{
	int		j;
	int		k;
	char	*tmp;

	j = i;
	while (menv->cgprio[j] == 8 && menv->cgv[j + 1]
		&& menv->cgprio[j + 1] == 8)
		j++;
	if (menv->cgprio[i] != 8)
		return (-1);
	if (menv->cgv[j + 1] && menv->cgprio[j + 1] != 11
		&& menv->cgprio[j + 1] != 13 && menv->cgprio[j + 1] != 14
		&& menv->cgprio[j + 1] != 15)
		return (-1);
	k = i;
	while (k <= j)
	{
		if (!(tmp = ft_strdup(menv->cgv[k++])))
			return (-1);
		ft_addvar(menv->internal_var, tmp);
	}
	return (j);
}
