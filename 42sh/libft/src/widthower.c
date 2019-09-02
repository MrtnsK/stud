/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widthower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:22:36 by pharatyk          #+#    #+#             */
/*   Updated: 2019/01/15 12:22:40 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static void	ft_widthpos(t_parameters *stock, char **zero)
{
	char	*switcher;

	if (ft_strlen(stock->arg) < stock->width)
	{
		if (!(*zero = ft_crea0(stock->width - ft_strlen(stock->arg), ' ')))
			return ;
		if (!(switcher = ft_strjoin(*zero, stock->arg)))
			return ;
		free(*zero);
		ft_switchmaster(&switcher, stock);
	}
}

static void	ft_widthzertwo(t_parameters *stock, char **zero, int lol)
{
	char	*save;
	char	*switcher;

	if (!(save = (char*)malloc(sizeof(char) * (lol + 1))))
		return ;
	save[lol] = 0;
	save = ft_strncpy(save, stock->arg, lol);
	if (!(*zero = ft_crea0(stock->width - ft_strlen(stock->arg), '0')))
		return ;
	if (!(*zero = ft_strjoin_eerf(save, *zero)))
		return ;
	free(save);
	if (!(switcher = ft_strjoin(*zero, stock->arg + lol)))
		return ;
	free(*zero);
	ft_switchmaster(&switcher, stock);
}

static void	ft_ultiwidthzero(t_parameters *stock, char **zero)
{
	char	*switcher;

	if (!(*zero = ft_crea0(stock->width - ft_strlen(stock->arg), '0')))
		return ;
	if (!(switcher = ft_strjoin(*zero, stock->arg)))
		return ;
	free(*zero);
	ft_switchmaster(&switcher, stock);
}

static void	ft_widthneg(t_parameters *stock, char **zero)
{
	char	*switcher;

	if (ft_strlen(stock->arg) < stock->width)
	{
		if (!(*zero = ft_crea0(stock->width
			- ft_strlen(stock->arg), ' ')))
			return ;
		if (!(switcher = ft_strjoin(stock->arg, *zero)))
			return ;
		free(*zero);
		ft_switchmaster(&switcher, stock);
	}
}

void		ft_widthower(t_parameters *stock)
{
	char	*zero;
	int		i;

	i = -1;
	if (!stock->widist)
		return ;
	if (!stock->masterflag[1])
		ft_widthpos(stock, &zero);
	else if (stock->masterflag[1] == 1)
	{
		if (ft_strlen(stock->arg) < stock->width
			&& stock->prexist && stock->specifier != 'f'
			&& stock->specifier != 's')
			ft_widthpos(stock, &zero);
		else if (ft_strlen(stock->arg) < stock->width
			&& (stock->masterflag[0] || stock->sign))
			ft_widthzertwo(stock, &zero, 1);
		else if (ft_strlen(stock->arg) < stock->width && stock->masterflag[2]
			&& (stock->specifier == 'x' || stock->specifier == 'X'))
			ft_widthzertwo(stock, &zero, 2);
		else
			ft_ultiwidthzero(stock, &zero);
	}
	else if (stock->masterflag[1] == 2)
		ft_widthneg(stock, &zero);
}
