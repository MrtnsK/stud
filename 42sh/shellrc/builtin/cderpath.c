/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cderpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:06:52 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/18 10:22:48 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*ft_getvalue_cd(t_masterenv *menv, char *name)
{
	char	*value;

	if (!name)
		return (NULL);
	if ((value = browse_tab(menv->stock[0], name)))
		return (value);
	else if ((value = browse_tab(menv->internal_var[0], name)))
		return (value);
	else
	{
		free(name);
		return (NULL);
	}
}

int			ft_cdpathchecker(char *tmp)
{
	if (is_file(tmp) && !is_truedir(tmp))
		return (1);
	if (!is_file(tmp) && !is_dir(tmp))
		return (1);
	if (is_file(tmp) && !is_dir(tmp))
		return (1);
	return (0);
}

int			ft_pwdcdpath(char *path, char *opt, char *tmp, char **pwd)
{
	char	*name;

	free(tmp);
	if (path[ft_strlen(path) - 1] == '/')
		tmp = ft_strjoin(path, opt);
	else
	{
		name = ft_strjoin(path, "/");
		tmp = ft_strjoin(name, opt);
		free(name);
	}
	if (!ft_cdpathchecker(tmp))
	{
		pwd[0] = ft_strdup(path);
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int			ft_checkcdpath(char **pwd, t_masterenv *menv, char **opt, int i)
{
	char	*tmp;
	char	*name;
	char	**paths;
	int		j;

	j = -1;
	name = ft_strdup("CDPATH=");
	if ((!(tmp = ft_getvalue_cd(menv, name))) || ft_strcmp(opt[i], "..") == 0
	|| !(paths = ft_strsplit(tmp, ':')))
	{
		if (tmp)
			free(tmp);
		return (menv->cdpath);
	}
	while (paths[++j])
	{
		if (ft_pwdcdpath(paths[j], opt[i], tmp, pwd))
		{
			ft_freetabc(paths);
			return (menv->cdpath = 1);
		}
	}
	ft_freetabc(paths);
	return (0);
}
