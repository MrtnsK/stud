/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elcalc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:26:04 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:06:07 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_errorzero(t_calctools *stock)
{
	int i;

	ft_printfd(2, "\e[93mMastershell\e[0m: division by zero\n");
	i = -1;
	while (stock->stuff[++i])
		free(stock->stuff[i]);
	free(stock->stuff[i]);
	free(stock->stuff);
	free(stock->digit);
	free(stock->flts);
	return (1);
}

int			ft_elcalcother_pt2(int i, t_calctools *stock, int bef, int aft)
{
	if ((long long)stock->flts[i] == 3)
	{
		stock->flts[bef] = stock->flts[bef] + stock->flts[aft];
		stock->digit[aft] = -1;
	}
	else if ((long long)stock->flts[i] == 2)
	{
		if (stock->stuff[i][0] == '*')
			stock->flts[bef] = stock->flts[bef] * stock->flts[aft];
		else if (stock->stuff[i][0] == '/')
		{
			if (stock->flts[aft] == 0)
				return (ft_errorzero(stock));
			stock->flts[bef] = stock->flts[bef] / stock->flts[aft];
		}
		else
		{
			if (stock->flts[aft] == 0)
				return (ft_errorzero(stock));
			stock->flts[bef] = (long long)stock->flts[bef]
			% (long long)stock->flts[aft];
		}
		stock->digit[aft] = -1;
	}
	return (0);
}

static int	ft_elcalcother(int i, t_calctools *stock)
{
	int			bef;
	int			aft;

	bef = i;
	aft = i;
	while (stock->digit[--bef] != 1)
		;
	while (stock->digit[++aft] != 1)
		;
	return (ft_elcalcother_pt2(i, stock, bef, aft));
}

int			ft_elcalcore(t_calctools *stock, int i, int mode)
{
	if (mode)
	{
		while (stock->stuff[++i])
			;
		while (--i > 0)
			if (stock->digit[i] == 0
				&& (long long)stock->flts[i] == stock->nb && i != 0)
				if (ft_elcalcpower(i, stock))
					return (1);
	}
	else
	{
		while (stock->stuff[++i])
			if (stock->digit[i] == 0
				&& (long long)stock->flts[i] == stock->nb && i != 0)
				if (ft_elcalcother(i, stock))
					return (1);
	}
	return (0);
}

int			ft_elcalc(t_calctools *stock)
{
	int			i;

	stock->nb = 1;
	while (stock->nb < 4)
	{
		i = -1;
		if (stock->nb == 1)
		{
			if (ft_elcalcore(stock, i, 1))
				return (1);
		}
		else
		{
			if (ft_elcalcore(stock, i, 0))
				return (1);
		}
		stock->nb += 1;
	}
	return (ft_elcalcender(stock, i));
}
