/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:47:28 by apsaint-          #+#    #+#             */
/*   Updated: 2019/07/30 10:25:18 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				ft_is_command(t_masterenv *menv, char *opt, char **pwd)
{
	char		*tmp;
	struct stat	fs;

	if (opt[0] == '/')
	{
		if (stat(opt, &fs) != -1)
		{
			if (fs.st_mode & S_IFREG)
				if (fs.st_mode & S_IXUSR)
				{
					pwd[0] = ft_strdup(opt);
					return (1);
				}
		}
		return (0);
	}
	else if (ft_findfct(menv, &tmp, opt))
		return (0);
	if (tmp)
	{
		pwd[0] = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

static	int		ft_is_alias(t_masterenv *menv, char *opt, char **pwd)
{
	t_alias		*als;

	als = menv->als;
	if (als)
		while (als && als->alias && als->name)
		{
			if (!ft_strcmp(opt, als->alias))
			{
				pwd[0] = ft_strdup(als->name);
				return (1);
			}
			als = als->next;
		}
	return (0);
}

static	int		ft_issou(t_masterenv *menv, char *opt)
{
	char		*pwd;

	if (!ft_notbltin(opt))
	{
		ft_printfd(1, "%s is a Mastershell builtin\n", opt);
		return (1);
	}
	else if (ft_is_command(menv, opt, &pwd))
	{
		ft_printfd(1, "%s is %s\n", opt, pwd);
		free(pwd);
		return (1);
	}
	else if (ft_is_alias(menv, opt, &pwd))
	{
		ft_printfd(1, "%s is aliased to %s\n", opt, pwd);
		free(pwd);
		return (1);
	}
	else
		return (0);
}

int				ft_typer(t_masterenv *menv, char **opt)
{
	int			i;
	int			ret;

	i = 0;
	ret = 1;
	if (ft_tablen(opt) == 1)
		return (0);
	while (opt[++i])
	{
		if (ft_issou(menv, opt[i]))
			ret = 0;
		else
			ft_printfd(2, "\e[93mMastershell\e[0m: type: %s: not found\n",
			opt[i]);
	}
	return (ret);
}
