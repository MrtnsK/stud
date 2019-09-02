/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unary_bcdef.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:27:28 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/06 12:04:43 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_testb(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (stat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !S_ISBLK(st.st_mode));
}

int		ft_testc(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (stat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !S_ISCHR(st.st_mode));
}

int		ft_testd(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (stat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !S_ISDIR(st.st_mode));
}

int		ft_teste(t_masterenv *tenv, char *opt)
{
	if (access(opt, F_OK) == 0)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}

int		ft_testf(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (stat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !S_ISREG(st.st_mode));
}
