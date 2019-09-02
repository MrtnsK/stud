/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatorresultor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:40:35 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:05:39 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_openparen(t_calctools *stock, int j, int i, char **calc)
{
	calc[0][j] = 0;
	if (!(stock->tmp = (char*)malloc(sizeof(char) *
		(ft_strlen(calc[0]) + ft_strlen(calc[0] + i)
			+ ft_strlen(stock->answ)))))
		return (1);
	ft_strcpy(stock->tmp, calc[0]);
	ft_strcat(stock->tmp, stock->answ);
	ft_strcat(stock->tmp, calc[0] + i + 1);
	free(calc[0]);
	if (!(calc[0] = (char*)malloc(sizeof(char)
		* (ft_strlen(stock->tmp) + 1))))
		return (1);
	ft_strcpy(calc[0], stock->tmp);
	free(stock->tmp);
	return (0);
}

static int	ft_resultorelse(char **calc, t_calctools *stock)
{
	free(calc[0]);
	if (!(calc[0] = (char*)malloc(sizeof(char)
		* (ft_strlen(stock->answ) + 1))))
		return (1);
	ft_strcpy(calc[0], stock->answ);
	return (0);
}

static void	ft_freestuff(t_calctools *stock)
{
	int i;

	i = -1;
	while (stock->stuff[++i])
		free(stock->stuff[i]);
	free(stock->stuff[i]);
	free(stock->answ);
	free(stock->stuff);
	free(stock->flts);
	free(stock->digit);
}

static int	ft_resultorstuff(int *a, int *b, char **calc, t_calctools *stock)
{
	int k;
	int i;
	int j;

	i = -1;
	j = -1;
	while (calc[0][++i])
	{
		if (calc[0][i] == '(')
			j = i;
		if (calc[0][i] == ')')
			break ;
	}
	k = j;
	if (ft_nbopnbrs(calc, stock, k, i))
		return (1);
	if (ft_inistuff(stock))
		return (1);
	if (ft_stockremplissor(calc, stock, k) || ft_answ(stock))
		return (1);
	if (j == -1)
		j = 0;
	*a = i;
	*b = j;
	return (0);
}

int			ft_resultor(char **calc)
{
	int			i;
	int			j;
	t_calctools	stock;

	if (ft_checkcalc(calc))
		return (1);
	if (ft_resultorstuff(&i, &j, calc, &stock))
		return (1);
	if (calc[0][j] == '(')
	{
		if (ft_openparen(&stock, j, i, calc))
			return (1);
		ft_freestuff(&stock);
		return (ft_resultor(calc));
	}
	else
	{
		if (ft_resultorelse(calc, &stock))
			return (1);
	}
	ft_freestuff(&stock);
	return (0);
}
