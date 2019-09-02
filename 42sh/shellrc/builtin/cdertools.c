/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdertools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:20:13 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:47:30 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_dir(char *name)
{
	DIR	*pdir;
	int	flag;

	pdir = opendir(name);
	if (pdir == NULL)
		flag = 0;
	else
	{
		flag = 1;
		closedir(pdir);
	}
	return (flag);
}

int		is_file(char *name)
{
	struct stat	st;

	return ((stat(name, &st) < 0) ? 0 : 1);
}

int		is_truedir(char *test)
{
	struct stat	lol;

	stat(test, &lol);
	return ((S_ISDIR(lol.st_mode) ? 1 : 0));
}

int		ft_cdchecker(char **tmp)
{
	if (is_file(tmp[0]) && !is_truedir(tmp[0]))
	{
		ft_printfd(2, "\e[93mcd\e[0m: not a directory: %s\n", tmp[0]);
		free(tmp[0]);
		return (1);
	}
	if (!is_file(tmp[0]) && !is_dir(tmp[0]))
	{
		ft_printfd(2, "\e[93mcd\e[0m: no such file or directory: %s\n", tmp[0]);
		free(tmp[0]);
		return (1);
	}
	if (is_file(tmp[0]) && !is_dir(tmp[0]))
	{
		ft_printfd(2, "\e[93mcd\e[0m: permission denied: %s\n", tmp[0]);
		free(tmp[0]);
		return (1);
	}
	return (0);
}

int		ft_checktmp(char **tmp, t_masterenv *menv, char **opt, int i)
{
	struct stat ls;

	lstat(menv->stock[0][menv->repe[1]] + 4, &ls);
	if (S_ISLNK(ls.st_mode) && menv->cdopt != 2
	&& (ft_strcmp("..", opt[i]) == 0 || ft_strcmp("-", opt[i]) == 0))
	{
		tmp[0] = ft_strdup(menv->stock[0][menv->repe[1]] + 4);
		return (1);
	}
	return (0);
}
