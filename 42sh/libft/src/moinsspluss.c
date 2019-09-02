/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moinsspluss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:22:06 by pharatyk          #+#    #+#             */
/*   Updated: 2019/06/17 19:44:23 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static void	ft_arrondisor(t_parameters *stock, int *i)
{
	int		j;
	int		flag;

	j = stock->precision + *i;
	if (stock->arg[j] >= '0' && stock->arg[j] <= '9')
	{
		if (stock->arg[j] >= '5' && (flag = 0) < 1)
		{
			while (flag == 0 && j >= 0)
			{
				j--;
				if (stock->arg[j] == '9')
					stock->arg[j] = '0';
				else if (stock->arg[j] <= '8' && stock->arg[j] >= '0')
				{
					stock->arg[j] += 1;
					flag = 1;
				}
			}
			if (flag == 0)
				ft_arrondisorsuite(stock, i);
		}
	}
}

static void	ft_printprecfsuite(t_parameters *stock, int i)
{
	char *switcher;

	if (stock->arg[i + 1] == 0 && ((stock->arg[i - 2] - '0') % 2) != 0)
		ft_arrondisor(stock, &i);
	else if (stock->arg[i + 1])
		ft_arrondisor(stock, &i);
	if (stock->arg[i + 1] == 0 && ((stock->arg[i - 2] - '0') % 2)
		&& stock->arg[i] != '5')
		ft_arrondisor(stock, &i);
	if (!(switcher = (char*)malloc(sizeof(char) * (--i))))
		return ;
	switcher[i] = 0;
	switcher = ft_strncpy(switcher, stock->arg, i);
	ft_switchmaster(&switcher, stock);
}

static void	ft_printprecftwo(t_parameters *stock, int i)
{
	char *switcher;

	if (stock->precision)
	{
		if (!(switcher = (char*)malloc(sizeof(char)
			* (i + stock->precision + 1))))
			return ;
		switcher[i + stock->precision] = 0;
		if (stock->arg[stock->precision + i])
			ft_arrondisor(stock, &i);
		switcher = ft_strncpy(switcher, stock->arg, i + stock->precision);
		ft_switchmaster(&switcher, stock);
	}
	else
		ft_printprecfsuite(stock, i);
}

static void	ft_printprecd(t_parameters *stock, char **zero)
{
	char *switcher;

	if (stock->specifier == 'N')
		return ;
	if (*stock->arg == '0' && stock->prexist && stock->precision == 0)
	{
		if (!(switcher = (char*)malloc(sizeof(char))))
			return ;
		switcher[0] = 0;
		ft_switchmaster(&switcher, stock);
	}
	else if (stock->specifier == 's' && stock->prexist)
		stock->arg[stock->precision] = 0;
	else if (ft_strlen(stock->arg) < stock->precision)
	{
		if (!(*zero = ft_crea0(stock->precision - ft_strlen(stock->arg), '0')))
			return ;
		if (!(stock->arg = ft_strjoin_eerf(*zero, stock->arg)))
			return ;
		free(*zero);
	}
}

void		ft_printprec(t_parameters *stock)
{
	int		i;
	char	*zero;

	i = -1;
	if (stock->specifier == 'f')
	{
		ft_masterprec(stock);
		while (stock->arg[i++] != '.' && stock->arg[i])
			;
		if (ft_strlen(stock->arg + i) < stock->precision)
		{
			if (!(zero = ft_crea0(stock->precision
				- ft_strlen(stock->arg + i), '0')))
				return ;
			if (!(stock->arg = ft_strjoin_free(stock->arg, zero)))
				return ;
			free(zero);
		}
		else
			ft_printprecftwo(stock, i);
	}
	else
		ft_printprecd(stock, &zero);
}
