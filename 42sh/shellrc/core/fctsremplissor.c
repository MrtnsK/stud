/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctsremplissor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:58:15 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/19 11:25:08 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_addfcts_pt3(t_masterenv *menv, char ***tmpfcts)
{
	char			**tmpfcts_pt2;

	if (!(tmpfcts_pt2 = (char**)malloc(sizeof(char*)
		* (ft_tablen(menv->fcts[0]) + 1))))
		return (1);
	ft_tabcpy(tmpfcts_pt2, menv->fcts[0]);
	lt_remove(menv->fcts[0]);
	if (!(menv->fcts[0] = (char**)lt_add(malloc(sizeof(char*)
		* (1 + ft_tablen(tmpfcts_pt2) + ft_tablen(tmpfcts[0]))))))
		return (1);
	ft_tabcpy(menv->fcts[0], tmpfcts_pt2);
	free(tmpfcts_pt2);
	ft_tabcat(menv->fcts[0], tmpfcts[0]);
	free(tmpfcts[0]);
	return (0);
}

static int	ft_addfcts_pt2(t_masterenv *menv, char *path, char ***tmpfcts)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	int				len;
	int				j;

	pdir = opendir(path);
	if (pdir == NULL)
		return (0);
	j = 0;
	while ((pdirent = readdir(pdir)) != NULL)
		if (pdirent->d_name[0] != '.' && ft_notbltin(pdirent->d_name))
		{
			len = ft_strlen(pdirent->d_name);
			if (!(tmpfcts[0][j] = (char*)malloc(sizeof(char)
			* (len + 1))))
			{
				closedir(pdir);
				return (1);
			}
			ft_strcpy(tmpfcts[0][j], pdirent->d_name);
			j++;
		}
	closedir(pdir);
	return (ft_addfcts_pt3(menv, tmpfcts));
}

static int	ft_addfcts(t_masterenv *menv, char *path)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	int				j;
	char			**tmpfcts;

	if (!is_truedir(path))
		return (0);
	pdir = opendir(path);
	if (pdir == NULL)
		return (0);
	j = 1;
	while ((pdirent = readdir(pdir)) != NULL)
	{
		if (pdirent->d_name[0] != '.' && ft_notbltin(pdirent->d_name))
			j++;
	}
	if (!(tmpfcts = (char**)malloc(sizeof(char*) * j)))
	{
		closedir(pdir);
		return (1);
	}
	tmpfcts[j - 1] = 0;
	closedir(pdir);
	return (ft_addfcts_pt2(menv, path, &tmpfcts));
}

static int	ft_fctsremplissorloop(t_masterenv *menv, int i)
{
	int		j;
	char	*path;

	j = i;
	i--;
	while (menv->internal_var[0][menv->rep[4]][++i]
		&& menv->internal_var[0][menv->rep[4]][i] != ':')
		;
	if (!(path = (char*)malloc(sizeof(char) * (i - j + 1))))
		return (-1);
	path[i - j] = 0;
	ft_strncpy(path, menv->internal_var[0][menv->rep[4]] + j, i - j);
	if (ft_addfcts(menv, path))
		return (-1);
	free(path);
	if (menv->internal_var[0][menv->rep[4]][i] == ':')
		i++;
	return (i);
}

int			ft_fctsremplissor(t_masterenv *menv)
{
	int		i;

	if (ft_refcts(menv))
		return (1);
	i = -1;
	while (menv->internal_var[0][menv->rep[4]][++i] != '=')
		;
	i++;
	while (menv->internal_var[0][menv->rep[4]][i])
	{
		i = ft_fctsremplissorloop(menv, i);
		if (i == -1)
			return (1);
	}
	return (0);
}
