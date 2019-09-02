/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classortools_pt2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:03:09 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 10:03:10 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	freethatshit(t_masterenv *menv, int j, char *buf)
{
	int i;

	i = -1;
	while (++i < j + 1)
		free(menv->cgv[i]);
	free(menv->cgv);
	free(menv->cgprio);
	free(menv->cgtype);
	free(buf);
	return (-10);
}

int	ft_remplissorpt1calchelper(int i, char *buf, char par)
{
	int		cpt;
	char	rap;

	rap = ')';
	if (par == '{')
		rap = '}';
	cpt = 1;
	i += 1;
	while (buf[++i])
	{
		if (buf[i] == par)
			cpt++;
		if (buf[i] == rap)
			cpt--;
		if (cpt == 0)
		{
			i++;
			break ;
		}
	}
	return (i);
}
