/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:22:17 by pharatyk          #+#    #+#             */
/*   Updated: 2019/01/15 12:22:19 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void		ft_arrondisorsuite(t_parameters *stock, int *i)
{
	if (!(stock->arg = ft_strjoin_eerf("1", stock->arg)))
		return ;
	*i += 1;
}

static void	ft_mastersign(t_parameters *stock)
{
	if (stock->sign)
	{
		if (!(stock->arg = ft_strjoin_eerf("-", stock->arg)))
			return ;
	}
	else if (stock->masterflag[0] == 1 && !stock->sign)
	{
		if (!(stock->arg = ft_strjoin_eerf(" ", stock->arg)))
			return ;
	}
	else if (stock->masterflag[0] == 2 && !stock->sign)
	{
		if (!(stock->arg = ft_strjoin_eerf("+", stock->arg)))
			return ;
	}
}

static void	ft_hashtago(t_parameters *stock)
{
	if (stock->arg[0] != '0')
	{
		if (!(stock->arg = ft_strjoin_eerf("0", stock->arg)))
			return ;
	}
}

static void	ft_hashtagueul(t_parameters *stock)
{
	if (stock->specifier == 'o')
		ft_hashtago(stock);
	if (stock->specifier == 'x' || stock->specifier == 'X')
	{
		if (stock->maj && stock->arg[0] != 0 && ft_strcmp("0", stock->arg))
		{
			if (!(stock->arg = ft_strjoin_eerf("0X", stock->arg)))
				return ;
		}
		else if (stock->maj == 0
			&& ((stock->arg[0] != 0 && ft_strcmp("0", stock->arg))
			|| ((stock->isp == 1
				&& (!ft_strcmp("0", stock->arg) || stock->arg[0] == 0)))))
		{
			if (!(stock->arg = ft_strjoin_eerf("0x", stock->arg)))
				return ;
		}
	}
	if (stock->specifier == 'f' && stock->prexist && stock->precision == 0)
		if (!(stock->arg = ft_strjoin_free(stock->arg, ".")))
			return ;
}

void		ft_printsign(t_parameters *stock)
{
	int		i;

	i = -1;
	while (++i < 3)
		stock->masterflag[i] = 0;
	i = -1;
	if (stock->flags)
		while (stock->flags[++i])
		{
			if (stock->flags[i] == '+')
				stock->masterflag[0] = 2;
			if (stock->flags[i] == ' ')
				stock->masterflag[0] = 1;
			if (stock->flags[i] == '-')
				stock->masterflag[1] = 2;
			if (stock->flags[i] == '0')
				stock->masterflag[1] = 1;
			if (stock->flags[i] == '#')
				stock->masterflag[2] = 1;
		}
	if ((stock->masterflag[0] || stock->sign) && (stock->specifier == 'f'
		|| stock->specifier == 'd' || stock->specifier == 'i'))
		ft_mastersign(stock);
	if (stock->masterflag[2])
		ft_hashtagueul(stock);
}
