/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unary_glprs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:38:18 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/06 12:46:41 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_testg(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (stat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !(S_ISGID & st.st_gid));
}

int		ft_testl(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (lstat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !S_ISLNK(st.st_mode));
}

int		ft_testp(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (stat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !S_ISFIFO(st.st_mode));
}

int		ft_testr(t_masterenv *tenv, char *opt)
{
	if (access(opt, R_OK) == 0)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}

int		ft_test_s(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (stat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !S_ISSOCK(st.st_mode));
}
