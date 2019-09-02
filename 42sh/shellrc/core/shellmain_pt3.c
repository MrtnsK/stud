/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellmain_pt3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 09:41:28 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 09:41:29 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_is(char *lol)
{
	int i;

	i = -1;
	while (lol[++i])
		if (!ft_isspace(lol[i]))
			return (1);
	return (0);
}

int		ft_protoc(char **buf, t_masterenv *menv, t_keymaster *lock)
{
	if (ft_classor(menv, buf))
		return (1);
	return (ft_prelauncher(buf, menv, lock));
}

int		ft_badending(char **ultib, int opt)
{
	free(ultib[0]);
	return (opt);
}

void	ft_init_preucore1(char **ultib, t_masterenv *menv, int i)
{
	if (ultib[0][i] == '&' && ultib[0][i + 1] == '&')
		menv->mode = 1;
	else if (ultib[0][i] == '|' && ultib[0][i + 1] == '|')
		menv->mode = -1;
	else
		menv->mode = 0;
	if (ultib[0][i] == '&' && ultib[0][i + 1] != '&')
		menv->valfct = 9;
	else
		menv->valfct = 10;
}

int		ft_preultimain_mk2_core1_altend(char **ultib, t_masterenv *menv
	, int i)
{
	if (ultib[0][i] != '\0')
	{
		ft_init_preucore1(ultib, menv, i);
		ultib[0][0] = 0;
		if (ultib[0][i + 1] == '|' || ultib[0][i + 1] == '&')
			i++;
		while (ultib[0][i + 1] && ft_isspace(ultib[0][i + 1]))
			i++;
		ft_strcator(ultib[0], ultib[0] + i + 1);
		i = -1;
		return (i);
	}
	return (ft_badending(ultib, -20));
}
