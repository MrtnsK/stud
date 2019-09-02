/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatortools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:22 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:05:45 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_nbopnbrs(char **calc, t_calctools *stock, int k, int i)
{
	if (k == i - 1)
	{
		ft_printfd(2, "manque quelque chose\n");
		return (1);
	}
	stock->flag = 1;
	stock->nb = 0;
	while (++k < i)
	{
		if ((calc[0][k] == '+' || calc[0][k] == '-' || calc[0][k] == '*'
			|| calc[0][k] == '%' || calc[0][k] == '/') && stock->flag)
		{
			stock->nb += 1;
			stock->flag = 0;
		}
		if (ft_isalnumflt(calc[0][k]) && stock->flag)
		{
			stock->nb += 1;
			stock->flag = 0;
		}
		if ((ft_isalnumflt(calc[0][k]) && !ft_isalnumflt(calc[0][k + 1]))
			|| (!ft_isalnumflt(calc[0][k]) && ft_isalnumflt(calc[0][k + 1])))
			stock->flag = 1;
	}
	return (0);
}

void	ft_stockremplissorer(char **calc, t_calctools *stock, int *k)
{
	if (ft_isalnumflt(calc[0][*k]))
	{
		stock->digit[stock->inc] = 1;
		while (ft_isalnumflt(calc[0][*k]))
			*k += 1;
	}
	else
	{
		stock->digit[stock->inc] = 0;
		while (!ft_isalnumflt(calc[0][*k]))
			*k += 1;
	}
}

int		ft_errorder(t_calctools *stock)
{
	int	i;

	i = 0;
	while (stock->stuff[++i])
		if (stock->digit[i - 1] == stock->digit[i])
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: operator problem\n");
			i = -1;
			while (stock->stuff[++i])
				free(stock->stuff[i]);
			free(stock->stuff[i]);
			free(stock->stuff);
			free(stock->digit);
			return (1);
		}
	return (0);
}

int		ft_stockremplissor(char **calc, t_calctools *stock, int k)
{
	while (stock->inc < stock->nb)
	{
		while (ft_isspace(calc[0][++k]))
			;
		stock->tobegin = k;
		ft_stockremplissorer(calc, stock, &k);
		if (!(stock->stuff[stock->inc] = (char*)malloc(sizeof(char)
			* (k - stock->tobegin + 1))))
			return (1);
		stock->stuff[stock->inc][k - stock->tobegin] = 0;
		ft_strncpy(stock->stuff[stock->inc],
			calc[0] + stock->tobegin, k - stock->tobegin);
		if (stock->digit[stock->inc])
			ft_trunkator(stock, stock->inc);
		k--;
		stock->inc += 1;
	}
	if (ft_errorder(stock))
		return (1);
	return (0);
}

int		ft_inistuff(t_calctools *stock)
{
	if (!(stock->stuff = (char**)malloc(sizeof(char*)
		* (stock->nb + 1))))
		return (1);
	if (!(stock->digit = (int*)malloc(sizeof(int) * stock->nb)))
		return (1);
	stock->stuff[stock->nb] = 0;
	stock->inc = 0;
	return (0);
}
