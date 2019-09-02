/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufgetortools_pt2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:23:54 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 15:23:56 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_unfinishedollar2(int *cpt, int *i)
{
	*cpt = 0;
	*i += 1;
	while (g_ultib[*i])
	{
		if (g_ultib[*i] == '{')
			*cpt += 1;
		if (g_ultib[*i] == '}')
			*cpt -= 1;
		if (*cpt == 0)
			break ;
		*i += 1;
	}
	return (0);
}

static int	ft_dollar2(int i, int cpt, t_keymaster *lock)
{
	ft_unfinishedollar2(&cpt, &i);
	if (g_ultib[i - 1] == '\\' && !g_ultib[i])
	{
		g_ultib[i - 1] = 0;
		if (ft_simpleprompt(lock))
			return (1);
		return (-20);
	}
	if (g_ultib[i] != '}')
	{
		if (ft_braceprompt(lock))
			return (-10);
		return (-20);
	}
	return (i);
}

int			ft_unfinishedcore_pt2(int i, int cpt, t_keymaster *lock)
{
	if (g_ultib[i] == '$' && g_ultib[i + 1] == '{')
	{
		if ((i = ft_dollar2(i, cpt, lock)) == -10 || i == -20)
			return (i);
	}
	if (g_ultib[i] == '\\' && !g_ultib[i + 1] && g_ultib[i - 1] != '\\')
	{
		g_ultib[i] = 0;
		if (ft_simpleprompt(lock))
			return (1);
		return (-20);
	}
	return (i);
}
