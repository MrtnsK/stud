/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cderpathclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:58 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:44:42 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_printnewpwd(t_masterenv *menv, char **tmp)
{
	if (!is_file(tmp[0]) || !is_dir(tmp[0]))
		return ;
	if (menv->stock[0][menv->repe[3]])
	{
		if (ft_strchrstr(tmp[0], menv->stock[0][menv->repe[3]] + 5))
			ft_printf("~%s\n", tmp[0]
				+ ft_strlen(menv->stock[0][menv->repe[3]]) - 5);
		else
			ft_printf("%s\n", tmp[0]);
	}
	else
		ft_printf("%s\n", tmp[0]);
}

int			ft_cd2op_pt2(t_masterenv *menv, char *tmp)
{
	char	*pwd;

	if (!(pwd = getcwd(NULL, 0)))
		return (1);
	if (!(menv->stock[0][menv->repe[1]] = (char*)malloc(sizeof(char)
		* (ft_strlen((menv->cdopt == 2) ? pwd : tmp) + 5))))
	{
		free(pwd);
		return (1);
	}
	menv->stock[0][menv->repe[1]][0] = 0;
	ft_strcat(menv->stock[0][menv->repe[1]], "PWD=");
	if ((menv->cdopt == 1 || menv->cdopt == 3
	|| (menv->cdopt == 0 && ft_strstr(tmp, "..") == 0)))
		ft_strcat(menv->stock[0][menv->repe[1]], tmp);
	else
		ft_strcat(menv->stock[0][menv->repe[1]], pwd);
	if (menv->cdpath == 1)
		ft_printfd(1, "%s\n", menv->stock[0][menv->repe[1]] + 4);
	free(pwd);
	free(tmp);
	return (0);
}

void		ft_microcd(char **tmp)
{
	chdir(tmp[0]);
	free(tmp[0]);
}

int			ft_getopt(char **opt, t_masterenv *menv)
{
	if (ft_tablen(opt) == 1)
		menv->cdopt = 0;
	else if ((ft_strcmp("-", opt[1]) == 0 && !opt[2]))
		menv->cdopt = 1;
	else if (opt[1][0] == '-' && opt[1][ft_strlen(opt[1]) - 1] == 'P')
		menv->cdopt = (ft_strcmp(opt[2], "-") == 0) ? 1 : 2;
	else if (opt[1][0] == '-' && opt[1][ft_strlen(opt[1]) - 1] == 'L')
		menv->cdopt = (ft_strcmp(opt[2], "-") == 0) ? 1 : 3;
	else if (opt[1][0] == '-' && ft_strlen(opt[1]) > 1)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: cd: %s: invalid option\n",
		opt[1]);
		ft_printfd(2, "\e[93mcd\e[0m: usage: [-L|-P] [dir]\n");
		return (1);
	}
	else
		menv->cdopt = 0;
	return (0);
}

int			ft_is_logical(char *pwd, char **tmp, t_masterenv *menv, char **opt)
{
	int			i;
	struct stat	ls;

	i = (menv->cdopt == 0) ? 1 : 2;
	lstat(pwd, &ls);
	if (S_ISLNK(ls.st_mode) && menv->cdopt != 2
	&& (ft_strcmp(opt[i], "..") == 0 || ft_strcmp(opt[i], "-") == 0))
	{
		i = ft_strrchri(pwd, '/');
		if (i == 0)
			tmp[0] = ft_strdup("/");
		else
			tmp[0] = ft_strsub(pwd, 0, i);
		return (1);
	}
	return (0);
}
