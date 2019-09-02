/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatoransw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:18:58 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:05:32 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_showpb(int i, t_calctools *stock, int j)
{
	if (stock->flts[i] == 1 || stock->flts[i] == 3)
	{
		j = 1;
		while (stock->stuff[i][++j])
			if (stock->stuff[i][j] == '*' || stock->stuff[i][j] == '/'
				|| stock->stuff[i][j] == '%')
			{
				ft_printfd(2, "\e[93mMastershell\e[0m: multiple operator");
				ft_printfd(2, ", first one used\n");
				break ;
			}
	}
	if (stock->flts[i] == 2)
	{
		j = 0;
		while (stock->stuff[i][++j])
			if (stock->stuff[i][j] == '*' || stock->stuff[i][j] == '/'
				|| stock->stuff[i][j] == '%')
			{
				ft_printfd(2, "\e[93mMastershell\e[0m: multiple operator");
				ft_printfd(2, ", first one used\n");
				break ;
			}
	}
}

static void	ft_whileansw(int i, t_calctools *stock)
{
	int j;

	stock->pos = 1;
	j = -1;
	if (stock->digit[i] == 0)
	{
		while (stock->stuff[i][++j])
			if (stock->stuff[i][j] == '-')
				stock->pos *= -1;
		if (stock->pos == -1)
			stock->flts[i + 1] *= -1;
		if (stock->stuff[i][0] == '*' || stock->stuff[i][0] == '/'
			|| stock->stuff[i][0] == '%')
			stock->flts[i] = 2;
		if (stock->stuff[i][0] == '*' && stock->stuff[i][0]
			&& stock->stuff[i][1] == '*')
			stock->flts[i] = 1;
		if (stock->stuff[i][0] == '+' || stock->stuff[i][0] == '-')
		{
			stock->stuff[i][0] = '+';
			stock->flts[i] = 3;
		}
		ft_showpb(i, stock, j);
	}
}

static int	ft_smallwhileansw(int i, t_calctools *stock)
{
	if (stock->digit[i])
		stock->flts[i] = ft_atof(stock->stuff[i]);
	else
	{
		if (!stock->stuff[i + 1])
		{
			i = -1;
			while (stock->stuff[++i])
				free(stock->stuff[i]);
			free(stock->stuff);
			free(stock->flts);
			free(stock->digit);
			ft_printfd(2, "lonely operator\n");
			return (1);
		}
	}
	return (0);
}

static void	ft_firstwhileansw(int i, t_calctools *stock)
{
	int j;

	if (stock->digit[i])
	{
		j = -1;
		while (stock->stuff[i][++j])
			if (stock->stuff[i][j] == '.')
				stock->isflt = 1;
	}
}

int			ft_answ(t_calctools *stock)
{
	int i;

	i = -1;
	stock->isflt = 0;
	while (stock->stuff[++i])
		ft_firstwhileansw(i, stock);
	if (!(stock->flts = (double*)malloc(sizeof(double) * i)))
		return (1);
	i = -1;
	while (stock->stuff[++i])
	{
		if (ft_smallwhileansw(i, stock))
			return (1);
	}
	i = -1;
	while (stock->stuff[++i])
		ft_whileansw(i, stock);
	if (ft_elcalc(stock))
		return (1);
	return (0);
}
