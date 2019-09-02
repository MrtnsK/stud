/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:05:22 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 13:16:57 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_checkredirfd(char *str)
{
	int	ind;
	int	size;

	size = ft_strlen(str);
	ind = ft_strchri(str, '>');
	if (ft_strcmp(str, ">") == 0)
		return (1);
	if (size > 1 && ind == (size - 1))
		return (1);
	return (0);
}

int		ft_checkcreate(t_masterenv *menv)
{
	int		i;

	i = -1;
	while (menv->cgv[++i])
	{
		if (menv->cgprio[i] == 21 || menv->cgprio[i] == 25)
		{
			if (ft_strstr(menv->cgv[i], ">>"))
			{
				if (ft_checkperm(menv, i, 0))
					return (1);
			}
			else if (((ft_strcmp(menv->cgv[i], ">&") == 0
			|| ft_strcmp(menv->cgv[i], "1>&") == 0)
			&& !ft_checkfd(menv->cgv[i + 1])) || ft_checkredirfd(menv->cgv[i]))
			{
				if (ft_checkperm(menv, i, 1))
					return (1);
			}
			else if (ft_checkredirinfile(menv, i))
				return (1);
		}
	}
	return (0);
}

int		ft_checkredirinfile(t_masterenv *menv, int i)
{
	struct stat st;

	if (ft_checkredirin(menv, i) && ft_strstr(menv->cgv[i], "<<") == 0)
	{
		if (stat(menv->cgv[i + 1], &st) == -1)
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: ");
			ft_printfd(2, "%s: No such file or directory\n", menv->cgv[i + 1]);
			return (i + 1);
		}
		if (!(st.st_mode & S_IRUSR))
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: %s: Permission Denied\n",
			menv->cgv[i + 1]);
			return (i + 1);
		}
	}
	return (0);
}

int		ft_checkredir(t_masterenv *menv, int start, int end)
{
	int	j;

	j = start;
	while (++j < end)
	{
		if (menv->cgprio[j] == 21 || menv->cgprio[j] == 25)
			return (j);
	}
	return (0);
}

int		ft_checkredirout(t_masterenv *menv, int j)
{
	int	ind;

	ind = ft_strchri(menv->cgv[j], '>');
	if (ft_strcmp(menv->cgv[j], ">") == 0 || ft_strstr(menv->cgv[j], ">>")
	|| (ft_strcmp(menv->cgv[j], ">&") == 0 && !ft_checkfd(menv->cgv[j + 1]))
	|| ft_checkredirfd(menv->cgv[j]))
		return (j);
	return (0);
}
