/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:36:44 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/18 11:05:15 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_noequal(char **opt)
{
	if (ft_strrchr(opt[1], '='))
	{
		ft_printfd(2, "\e[93msetenv\e[0m : invalid input in variable : '='\n");
		return (1);
	}
	return (0);
}

int			ft_setenvcgc2(t_masterenv *menv, char **opt)
{
	int i;

	if (ft_noequal(opt))
		return (1);
	i = -1;
	while (menv->stock[0][++i]\
	&& ft_strcmp(opt[1], menv->stock[0][i]) != -61)
		;
	if (menv->stock[0][i])
	{
		if (ft_setenvcgc2xist(menv, i))
			return (1);
	}
	else
	{
		if (ft_setenvcgc2xistpo(menv, i, opt))
			return (1);
	}
	return (0);
}

int			ft_setenvcgc3(t_masterenv *menv, char **opt)
{
	int		i;
	char	**tenv;

	if (ft_noequal(opt))
		return (1);
	i = -1;
	tenv = NULL;
	while (menv->stock[0][++i]\
	&& ft_strcmp(opt[1], menv->stock[0][i]) != -61)
		;
	if (menv->stock[0][i])
	{
		if (ft_setenvcgc3xist(menv, i, opt))
			return (1);
	}
	else
	{
		if (ft_setenvcgc3xistpo(menv, i, tenv, opt))
			return (1);
	}
	return (0);
}

int			ft_setenv(t_masterenv *menv, char **opt)
{
	int		i;

	if (ft_tablen(opt) == 1)
	{
		i = -1;
		while (menv->stock[0][++i])
			ft_printf("%s\n", menv->stock[0][i]);
	}
	else if (ft_tablen(opt) == 2)
	{
		if (ft_setenvcgc2(menv, opt))
			return (1);
	}
	else if (ft_tablen(opt) == 3)
	{
		if (ft_setenvcgc3(menv, opt))
			return (1);
	}
	else
	{
		ft_printfd(2, "\e[93msetenv\e[0m : Too many arguments.\n");
		return (1);
	}
	ft_inirep(menv, 0);
	return (0);
}
