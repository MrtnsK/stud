/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellmain_pt4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 09:41:33 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 09:41:35 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_preultimain_mk2_core1(char **ultib, t_masterenv *menv
	, t_keymaster *lock, int i)
{
	char	*derive;

	if ((menv->mode > 0 && menv->nruter) || (menv->mode < 0 && !menv->nruter))
		return (ft_preultimain_mk2_core1_altend(ultib, menv, i));
	if (!(derive = (char*)malloc(sizeof(char) * (i + 1))))
		return (ft_badending(ultib, -10));
	ft_strncpy(derive, ultib[0], i);
	derive[i] = 0;
	ft_init_preucore1(ultib, menv, i);
	if (ft_ultimain_mk2(&derive))
		return (-10);
	if (ft_protoc(&derive, menv, lock))
		return (ft_badending(ultib, -10));
	ultib[0][0] = 0;
	if (ultib[0][i + 1] == '|' || ultib[0][i + 1] == '&')
		i++;
	while (ultib[0][i + 1] && ft_isspace(ultib[0][i + 1]))
		i++;
	ft_strcator(ultib[0], ultib[0] + i + 1);
	i = -1;
	return (i);
}

int	ft_preultimain_mk2_core2(char **ultib, t_masterenv *menv
	, t_keymaster *lock)
{
	if ((menv->mode > 0 && menv->nruter) || (menv->mode < 0 && !menv->nruter))
		return (ft_badending(ultib, 0));
	menv->valfct = 10;
	if (ft_ultimain_mk2(ultib))
		return (1);
	if (ft_protoc(ultib, menv, lock))
		return (1);
	return (0);
}

int	ft_preultimain_mk2_pt2(char **ultib, t_masterenv *menv
	, t_keymaster *lock)
{
	update_jobs();
	if (ft_is(ultib[0]))
		return (ft_preultimain_mk2_core2(ultib, menv, lock));
	else
		free(ultib[0]);
	return (0);
}

int	ft_preultimain_mk2_i(char **ultib, int i)
{
	if (ultib[0][i] == '"')
		while (ultib[0][++i] != '"')
			;
	if (ultib[0][i] == '\'')
		while (ultib[0][++i] != '\'')
			;
	return (i);
}

int	ft_preultimain_mk2(char **ultib, t_masterenv *menv
	, t_keymaster *lock)
{
	int		i;

	i = -1;
	menv->mode = 0;
	while (ultib[0][++i])
	{
		i = ft_preultimain_mk2_i(ultib, i);
		if (ultib[0][i] == '$' && ultib[0][i + 1] == '('
			&& ultib[0][i + 2] == '(')
		{
			i = ft_remplissorpt1calchelper(i, ultib[0], ultib[0][i + 1]);
			i--;
		}
		if ((i > 0 && ultib[0][i] == '&' && ultib[0][i - 1] != '<'
			&& ultib[0][i - 1] != '>') || ultib[0][i] == ';'
			|| (ultib[0][i] == '|' && ultib[0][i + 1] == '|'))
		{
			i = ft_preultimain_mk2_core1(ultib, menv, lock, i);
			if (i == -10)
				return (1);
			if (i == -20)
				return (0);
		}
	}
	return (ft_preultimain_mk2_pt2(ultib, menv, lock));
}
