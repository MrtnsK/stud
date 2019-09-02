/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:26:49 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 11:41:56 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_shlvl2(t_masterenv *menv, int i, int j, char **tmp)
{
	char	*number;

	number = ft_itoa(ft_mastoi(tmp[0] + j) + 1);
	tmp[0][j] = 0;
	if (!(menv->stock[0][i] = (char*)malloc(sizeof(char)
		* (1 + ft_strlen(tmp[0]) + ft_strlen(number)))))
	{
		free(number);
		return (1);
	}
	ft_strcpy(menv->stock[0][i], tmp[0]);
	ft_strcat(menv->stock[0][i], number);
	free(number);
	return (0);
}

static int	ft_shlvl(t_masterenv *menv, int i)
{
	char	*tmp;
	int		j;

	if (!(tmp = (char*)malloc(sizeof(char)
	* (ft_strlen(menv->stock[0][i]) + 1))))
		return (1);
	ft_strcpy(tmp, menv->stock[0][i]);
	free(menv->stock[0][i]);
	j = ft_strchri(tmp, '=');
	if (tmp[++j])
	{
		if (ft_shlvl2(menv, i, j, &tmp))
			return (1);
	}
	else
	{
		if (!(menv->stock[0][i] = (char*)malloc(sizeof(char)
			* (2 + ft_strlen(tmp)))))
			return (1);
		ft_strcpy(menv->stock[0][i], tmp);
		ft_strcat(menv->stock[0][i], "1");
	}
	free(tmp);
	return (0);
}

static int	ft_newshell(t_masterenv *menv)
{
	int		i;
	char	*pwd;

	i = -1;
	while (menv->stock[0][++i])
	{
		if (ft_strcmp("SHELL", menv->stock[0][i]) == -61)
		{
			if (!(pwd = getcwd(NULL, 0)))
				return (1);
			free(menv->stock[0][i]);
			if (!(menv->stock[0][i] = (char*)malloc(sizeof(char)
				* (ft_strlen(pwd) + 19))))
				return (1);
			ft_strcpy(menv->stock[0][i], "SHELL=");
			ft_strcat(menv->stock[0][i], pwd);
			free(pwd);
			ft_strcat(menv->stock[0][i], "/mastershell");
		}
		if (ft_strcmp("SHLVL", menv->stock[0][i]) == -61)
			if (ft_shlvl(menv, i))
				return (1);
	}
	return (0);
}

void		ft_inirep(t_masterenv *menv, int option)
{
	int			i;
	int			k;
	static char	*save;

	if (option == 1)
	{
		if (!(save = (char*)lt_add(malloc(sizeof(char)))))
			save = 0;
		save[0] = 0;
	}
	k = -1;
	while (menv->internal_var[0][++k])
		;
	i = 5;
	while (--i >= 0)
		menv->rep[i] = k;
	ft_stock(menv, i);
	ft_stock2(menv);
	save = ft_inirep_pt2(option, menv, save);
	if (save[0] == 'a')
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: Failed inirep\n");
		lt_delet();
		exit(EXIT_FAILURE);
	}
}

int			ft_inienv(t_masterenv *menv, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (env[++i])
		;
	if (!(menv->stock = (char***)malloc(sizeof(char**))))
		return (1);
	if (!(menv->stock[0] = (char**)malloc(sizeof(char*) * ++i)))
		return (1);
	menv->stock[0][--i] = 0;
	i = -1;
	while (env[++i] && (j = -1) < 0)
	{
		j = ft_strchri(env[i], '\0');
		if (!(menv->stock[0][i] = (char*)malloc(sizeof(char) * ++j)))
			return (1);
		menv->stock[0][i][--j] = 0;
		ft_strcpy(menv->stock[0][i], env[i]);
	}
	if (ft_newshell(menv))
		return (1);
	menv->nruter = 0;
	return (0);
}
