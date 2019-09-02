/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:03:03 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/15 12:54:31 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_test_gt(t_masterenv *tenv, char *str1, char *str2)
{
	long long int	nb1;
	long long int	nb2;

	if (ft_error_integer(&nb1, str1))
	{
		ft_printfd(2,
		"\e[93mMastershell\e[0m: test: %s: integer expression expected\n"
		, str1);
		return (tenv->nruter = 2);
	}
	if (ft_error_integer(&nb2, str2))
	{
		ft_printfd(2,
		"\e[93mMastershell\e[0m: test: %s: integer expression expected\n"
		, str2);
		return (tenv->nruter = 2);
	}
	if (nb1 > nb2)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}

static	int	ft_unary_pt2(t_masterenv *tenv, char **opt, int i, int op)
{
	if (op == 10)
		return (ft_test_s(tenv, opt[i + 1]));
	else if (op == 11)
		return (ft_tests(tenv, opt[i + 1]));
	else if (op == 12)
		return (ft_testu(tenv, opt[i + 1]));
	else if (op == 13)
		return (ft_testw(tenv, opt[i + 1]));
	else if (op == 14)
		return (ft_testx(tenv, opt[i + 1]));
	else
		return (ft_testz(tenv, opt[i + 1]));
}

int			ft_unary_test(t_masterenv *tenv, int size, char **opt, int op)
{
	int		i;

	i = (size == 2) ? 1 : 2;
	if (op == 1)
		return (ft_testb(tenv, opt[i + 1]));
	else if (op == 2)
		return (ft_testc(tenv, opt[i + 1]));
	else if (op == 3)
		return (ft_testd(tenv, opt[i + 1]));
	else if (op == 4)
		return (ft_teste(tenv, opt[i + 1]));
	else if (op == 5)
		return (ft_testf(tenv, opt[i + 1]));
	else if (op == 6)
		return (ft_testg(tenv, opt[i + 1]));
	else if (op == 7)
		return (ft_testl(tenv, opt[i + 1]));
	else if (op == 8)
		return (ft_testp(tenv, opt[i + 1]));
	else if (op == 9)
		return (ft_testr(tenv, opt[i + 1]));
	else
		return (ft_unary_pt2(tenv, opt, i, op));
}

int			ft_binary_test(t_masterenv *tenv, int size, char **opt, int op)
{
	int		i;

	i = (size == 3) ? 2 : 3;
	if (op == 16)
		return (tenv->nruter = (ft_strcmp(opt[i - 1], opt[i + 1]) == 0)
		? 0 : 1);
	else if (op == 17)
		return (tenv->nruter = (ft_strcmp(opt[i - 1], opt[i + 1]) != 0)
		? 0 : 1);
	else if (op == 18)
		return (ft_test_eq(tenv, opt[i - 1], opt[i + 1]));
	else if (op == 19)
		return (ft_test_ne(tenv, opt[i - 1], opt[i + 1]));
	else if (op == 20)
		return (ft_test_ge(tenv, opt[i - 1], opt[i + 1]));
	else if (op == 21)
		return (ft_test_lt(tenv, opt[i - 1], opt[i + 1]));
	else if (op == 22)
		return (ft_test_le(tenv, opt[i - 1], opt[i + 1]));
	else
		return (ft_test_gt(tenv, opt[i - 1], opt[i + 1]));
}
