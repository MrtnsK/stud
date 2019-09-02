/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classortools_pt3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:03:17 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 10:03:18 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_endit(char **toretouch, char **calc, int i, int j)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char)
		* (ft_strlen(toretouch[0]) - (j - i) + ft_strlen(calc[0])))))
		return (1);
	toretouch[0][i] = 0;
	ft_strcpy(tmp, toretouch[0]);
	ft_strcat(tmp, calc[0]);
	ft_strcat(tmp, toretouch[0] + j + 1);
	free(toretouch[0]);
	if (!(toretouch[0] = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
		return (1);
	ft_strcpy(toretouch[0], tmp);
	free(tmp);
	return (0);
}

static int	ft_destroy_mk2_core_retouch(char **dest, t_masterenv *menv, int i
	, int j)
{
	char	*newer;

	if (!(newer = (char*)malloc(sizeof(char) * (i - j + 2))))
		return (-10);
	ft_strncpy(newer, dest[0] + j, i - j + 1);
	newer[i - j + 1] = 0;
	if (ft_retoucheur(&newer, menv))
	{
		free(newer);
		return (-10);
	}
	if (!ft_strncmp(newer, dest[0] + j, i - j + 1))
	{
		free(newer);
	}
	else
	{
		if (ft_endit(dest, &newer, j, i))
			return (-10);
		i = j + ft_strlen(newer) - 1;
		free(newer);
	}
	return (i);
}

int			ft_destroy_mk2_core_noquote(char **dest, t_masterenv *menv, int i)
{
	int		j;

	j = i;
	while (dest[0][++i] && ((dest[0][i] != '"' && dest[0][i] != '\'')
		|| ((dest[0][i] == '"' || dest[0][i] == '\'')
		&& dest[0][i - 1] == '\\')))
		;
	i--;
	return (ft_destroy_mk2_core_retouch(dest, menv, i, j));
}

int			ft_destroy_mk2_core_quote(char **dest, t_masterenv *menv
	, t_nbtool *koul, int i)
{
	int		j;
	char	save;

	j = i;
	save = dest[0][i];
	menv->cgtype[koul->j] = 9;
	dest[0][i] = 0;
	ft_strcator(dest[0], dest[0] + i + 1);
	i--;
	while (dest[0][++i] && (dest[0][i] != save || dest[0][i - 1] == '\\'))
		;
	if (dest[0][i])
	{
		dest[0][i] = 0;
		ft_strcator(dest[0], dest[0] + i + 1);
	}
	i--;
	if (save == '"')
		return (ft_destroy_mk2_core_retouch(dest, menv, i, j));
	return (i);
}
