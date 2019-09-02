/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unary_suwxz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:07:35 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/15 12:38:35 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_tests(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (stat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !(st.st_size > 0));
}

int		ft_testu(t_masterenv *tenv, char *opt)
{
	struct stat	st;

	if (lstat(opt, &st) == -1)
		return (tenv->nruter = 1);
	else
		return (tenv->nruter = !(st.st_mode & S_ISUID));
}

int		ft_testw(t_masterenv *tenv, char *opt)
{
	if (access(opt, W_OK) == 0)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}

int		ft_testx(t_masterenv *tenv, char *opt)
{
	if (access(opt, X_OK) == 0)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}

int		ft_testz(t_masterenv *tenv, char *opt)
{
	if (!opt)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = ((!ft_strlen(opt)) ? 0 : 1));
}
