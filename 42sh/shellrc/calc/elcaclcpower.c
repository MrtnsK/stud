/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elcaclcpower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:25:47 by pharatyk          #+#    #+#             */
/*   Updated: 2019/03/18 11:25:49 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_nofloats(t_calctools *stock)
{
	int i;

	ft_printfd(2, "\e[93mMastershell\e[0m: \"** floats\" not integrated\n");
	i = -1;
	while (stock->stuff[++i])
		free(stock->stuff[i]);
	free(stock->stuff[i]);
	free(stock->stuff);
	free(stock->digit);
	free(stock->flts);
	return (1);
}

static void	ft_elcalcpowerpos(t_calctools *stock, int aft, int bef)
{
	long long	nbpower;
	int			flag;

	flag = 0;
	if (bef != 0 && bef != 1 && stock->flts[bef] < 0)
	{
		stock->flts[bef] *= -1;
		flag = 1;
	}
	nbpower = stock->flts[bef];
	stock->flts[aft] -= 1;
	while ((long long)stock->flts[aft])
	{
		stock->flts[bef] = stock->flts[bef] * nbpower;
		stock->flts[aft] -= 1;
	}
	if (flag)
		stock->flts[bef] *= -1;
	stock->digit[aft] = -1;
}

static void	ft_elcalcpowerneg(t_calctools *stock, int aft, int bef)
{
	long long	nbpower;
	int			flag;

	flag = 0;
	if (bef != 0 && stock->flts[bef] < 0)
	{
		stock->flts[bef] *= -1;
		flag = 1;
	}
	stock->isflt = 1;
	stock->flts[aft] *= -1;
	nbpower = stock->flts[bef];
	stock->flts[aft] -= 1;
	while ((long long)stock->flts[aft])
	{
		stock->flts[bef] = stock->flts[bef] * nbpower;
		stock->flts[aft] -= 1;
	}
	stock->flts[bef] = 1.0 / stock->flts[bef];
	if (flag)
		stock->flts[bef] *= -1;
	stock->digit[aft] = -1;
}

int			ft_elcalcpower(int i, t_calctools *stock)
{
	int			bef;
	int			aft;

	bef = i;
	aft = i;
	while (stock->digit[--bef] != 1)
		;
	while (stock->digit[++aft] != 1)
		;
	if ((long long)stock->flts[i] == 1)
	{
		if ((long long)stock->flts[aft] != stock->flts[aft])
			return (ft_nofloats(stock));
		if (stock->flts[aft] > 0)
			ft_elcalcpowerpos(stock, aft, bef);
		else if (stock->flts[aft] < 0)
			ft_elcalcpowerneg(stock, aft, bef);
		else
		{
			stock->digit[aft] = -1;
			stock->flts[bef] = 1;
		}
	}
	return (0);
}

int			ft_elcalcender(t_calctools *stock, int i)
{
	char *tmp;

	i = -1;
	while (stock->digit[++i] != 1)
		;
	if (stock->isflt)
	{
		tmp = ft_ftoa(stock->flts[i], 18);
		if (!(stock->answ = (char*)malloc(sizeof(char)
			* (ft_strlen(tmp) + 1))))
			return (1);
		ft_strcpy(stock->answ, tmp);
		free(tmp);
	}
	else
	{
		tmp = ft_itoa((long long)stock->flts[i]);
		if (!(stock->answ = (char*)malloc(sizeof(char)
			* (ft_strlen(tmp) + 1))))
			return (1);
		ft_strcpy(stock->answ, tmp);
		free(tmp);
	}
	return (0);
}
