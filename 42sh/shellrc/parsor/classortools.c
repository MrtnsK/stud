/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classortools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:20:48 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 14:08:45 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_destroy_mk2(char **dest, t_masterenv *menv, t_nbtool *koul)
{
	int		i;

	i = -1;
	while (dest[0][++i])
	{
		if (dest[0][i] != '"' && dest[0][i] != '\'')
		{
			if ((i = ft_destroy_mk2_core_noquote(dest, menv, i)) == -10)
				return (1);
		}
		else if ((dest[0][i] == '"' || dest[0][i] == '\'')
			&& (i == 0 || dest[0][i - 1] != '\\'))
		{
			if ((i = ft_destroy_mk2_core_quote(dest, menv, koul, i)) == -10)
				return (1);
		}
	}
	return (0);
}

static int	ft_remplissorpt1helper(int i, char quote, char *buf)
{
	while (buf[++i])
		if (buf[i] == quote && buf[i - 1] != '\\')
		{
			i++;
			break ;
		}
	return (i);
}

static int	ft_remplissorpt2(t_nbtool *koul, int i,
	char *buf, t_masterenv *menv)
{
	if (!(menv->cgv[koul->j] = (char*)malloc(sizeof(char)
		* (i - koul->nb + 1))))
		return (-10);
	ft_strncpy(menv->cgv[koul->j], buf + koul->nb, i - koul->nb);
	menv->cgv[koul->j][i - koul->nb] = 0;
	if (ft_destroy_mk2(&menv->cgv[koul->j], menv, koul))
		return (freethatshit(menv, koul->j, buf));
	return (i);
}

static int	ft_remplissorpt1(t_nbtool *koul, int i,
	char *buf, t_masterenv *menv)
{
	if ((buf[i] == '"' || buf[i] == '\'') && (i == 0 || buf[i - 1] != '\\'))
		i = ft_remplissorpt1helper(i, buf[i], buf);
	else if (buf[i] == '$' && (i == 0 || buf[i - 1] != '\\')
		&& (buf[i + 1] == '(' || buf[i + 1] == '{'))
		i = ft_remplissorpt1calchelper(i, buf, buf[i + 1]);
	else if (buf[i] == '$')
		i++;
	else
		while ((!ft_isspace(buf[i]) || (i > 0 && ft_isspace(buf[i])
			&& buf[i - 1] == '\\')) && buf[i] && ((buf[i] != '\''
			&& buf[i] != '"' && buf[i] != '$')
			|| (i == 0 || buf[i - 1] == '\\')))
			i++;
	if (buf[i] && !ft_isspace(buf[i]))
		return (ft_remplissorpt1(koul, i, buf, menv));
	return (ft_remplissorpt2(koul, i, buf, menv));
}

int			ft_remplissor(t_masterenv *menv, int nb, char *buf)
{
	int			i;
	t_nbtool	koul;

	i = 0;
	koul.j = 0;
	while (koul.j < nb)
	{
		while (ft_isspace(buf[i]) && buf[i])
			i++;
		koul.nb = i;
		if ((i = ft_remplissorpt1(&koul, i, buf, menv)) == -10)
			return (1);
		koul.j += 1;
	}
	return (0);
}
