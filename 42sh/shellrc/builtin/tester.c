/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:16:11 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/14 13:52:38 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_test_errors(t_masterenv *tenv, char **opt, int size, int *op)
{
	if ((size == 2 && !(*op = ft_check_opt1(opt[1]))))
	{
		if (ft_strcmp(opt[1], "!") == 0)
			return (0);
		ft_printfd(2,
		"\e[93mMastershell\e[0m: test: %s: unary operator expected\n", opt[1]);
		return (tenv->nruter = 2);
	}
	else if (size == 3 && (!(*op = ft_check_opt1(opt[2]))))
	{
		if ((*op = ft_check_opt2(opt[2])))
			return (0);
		ft_printfd(2,
		"\e[93mMastershell\e[0m: test: %s: unary operator expected\n"
		, opt[2]);
		return (tenv->nruter = 2);
	}
	else if (size == 4 && !(*op = ft_check_opt2(opt[3])))
	{
		ft_printfd(2,
		"\e[93mMastershell\e[0m: test: %s: unary operator expected\n", opt[2]);
		return (tenv->nruter = 2);
	}
	return (0);
}

int		ft_test_opt1(t_masterenv *tenv, int size, char **opt, int op)
{
	int		ret;

	if (size == 2)
	{
		if (!ft_strcmp(opt[1], "!"))
			return (tenv->nruter = (opt[2]) ? 1 : 0);
		else
			return (ft_unary_test(tenv, size, opt, op));
	}
	else if (size == 3)
	{
		ret = ft_unary_test(tenv, size, opt, op);
		if (!ft_strcmp(opt[1], "!"))
			return (tenv->nruter = (ret) ? 0 : 1);
		else
			return (tenv->nruter = ret);
	}
	return (tenv->nruter = 2);
}

int		ft_test_opt2(t_masterenv *tenv, int size, char **opt, int op)
{
	int	ret;

	if (size == 3)
		return (ft_binary_test(tenv, size, opt, op));
	else if (size == 4)
	{
		ret = ft_binary_test(tenv, size, opt, op);
		if (!ft_strcmp(opt[1], "!"))
			return (tenv->nruter = (ret) ? 0 : 1);
		else
			return (tenv->nruter = ret);
	}
	return (tenv->nruter = 2);
}

int		ft_tester(t_masterenv *tenv, char **opt)
{
	int		size;
	int		op;

	if (ft_strcmp("[", opt[0]) == 0)
		size = ft_tablen(opt) - 2;
	else
		size = ft_tablen(opt) - 1;
	if (size > 4)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: %s: too many arguments\n",
		opt[0]);
		return (tenv->nruter = 2);
	}
	if (size == 0)
		return (tenv->nruter = 1);
	if (ft_test_errors(tenv, opt, size, &op))
		return (1);
	if (size == 1)
		return (tenv->nruter = (opt[1]) ? 0 : 1);
	if (size == 2 || op < 16)
		return (ft_test_opt1(tenv, size, opt, op));
	else
		return (ft_test_opt2(tenv, size, opt, op));
	return (0);
}
