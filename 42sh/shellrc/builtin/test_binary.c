/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:19:26 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/06 12:03:59 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_test_eq(t_masterenv *tenv, char *str1, char *str2)
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
	if (nb1 == nb2)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}

int		ft_test_ne(t_masterenv *tenv, char *str1, char *str2)
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
	if (nb1 != nb2)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}

int		ft_test_ge(t_masterenv *tenv, char *str1, char *str2)
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
	if (nb1 >= nb2)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}

int		ft_test_lt(t_masterenv *tenv, char *str1, char *str2)
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
	if (nb1 < nb2)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}

int		ft_test_le(t_masterenv *tenv, char *str1, char *str2)
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
	if (nb1 <= nb2)
		return (tenv->nruter = 0);
	else
		return (tenv->nruter = 1);
}
