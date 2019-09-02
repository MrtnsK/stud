/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctsremplissor_pt2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:58:53 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/03 14:17:36 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_notbltin(char *test)
{
	if (ft_strcmp(test, "echo") && ft_strcmp(test, "cd")
		&& ft_strcmp(test, "exit") && ft_strcmp(test, "setenv")
		&& ft_strcmp(test, "unsetenv") && ft_strcmp(test, "type")
		&& ft_strcmp(test, "jobs") && ft_strcmp(test, "fg")
		&& ft_strcmp(test, "bg") && ft_strcmp(test, "fc")
		&& ft_strcmp(test, "set") && ft_strcmp(test, "unset")
		&& ft_strcmp(test, "alias") && ft_strcmp(test, "unset")
		&& ft_strcmp(test, "unalias"))
		return (1);
	return (0);
}

int			ft_bltinfcts(t_masterenv *menv)
{
	menv->fcts[0][0] = ft_strdup("echo");
	menv->fcts[0][1] = ft_strdup("cd");
	menv->fcts[0][2] = ft_strdup("exit");
	menv->fcts[0][3] = ft_strdup("setenv");
	menv->fcts[0][4] = ft_strdup("unsetenv");
	menv->fcts[0][5] = ft_strdup("type");
	menv->fcts[0][6] = ft_strdup("jobs");
	menv->fcts[0][7] = ft_strdup("fg");
	menv->fcts[0][8] = ft_strdup("bg");
	menv->fcts[0][9] = ft_strdup("fc");
	menv->fcts[0][10] = ft_strdup("set");
	menv->fcts[0][11] = ft_strdup("unset");
	menv->fcts[0][12] = ft_strdup("unalias");
	menv->fcts[0][13] = ft_strdup("alias");
	menv->fcts[0][14] = ft_strdup("test");
	return (0);
}

int			ft_refcts(t_masterenv *menv)
{
	int i;

	i = -1;
	while (menv->fcts[0][++i])
		free(menv->fcts[0][i]);
	lt_remove(menv->fcts[0]);
	if (!(menv->fcts[0] = (char**)lt_add(malloc(sizeof(char*) * 16))))
	{
		menv->fcts[0] = 0;
		return (1);
	}
	if (ft_bltinfcts(menv))
	{
		menv->fcts[0] = 0;
		return (1);
	}
	menv->fcts[0][15] = 0;
	return (0);
}
