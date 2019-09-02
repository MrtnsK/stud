/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:01:27 by pharatyk          #+#    #+#             */
/*   Updated: 2019/06/18 14:23:16 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_crea0(int size, char g)
{
	char	*out;
	int		i;

	i = -1;
	if (!(out = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (++i < size)
		out[i] = g;
	out[i] = 0;
	return (out);
}

void	ft_switchmaster(char **switcher, t_parameters *stock)
{
	free(stock->arg);
	if (!(stock->arg = (char*)malloc(sizeof(char)
		* (ft_strlen(*switcher) + 1))))
		return ;
	ft_strcpy(stock->arg, *switcher);
	free(*switcher);
}

char	*ft_convbin(unsigned long long in)
{
	char				*out;
	unsigned long long	tmp;
	int					i;

	tmp = in;
	i = 0;
	while (in)
	{
		i++;
		in /= 2;
	}
	if (!(out = (char*)malloc(sizeof(char) * (++i))))
		return (0);
	out[--i] = 0;
	in = tmp;
	while (--i > -1)
	{
		out[i] = ((in % 2) + '0');
		in /= 2;
	}
	return (out);
}

char	*ft_convhex(unsigned long long in, char x)
{
	char				*out;
	unsigned long long	tmp;
	int					i;

	tmp = in;
	i = 0;
	if (in == 0)
		return (ft_convhsuite());
	while (in && (++i > 0))
		in /= 16;
	if (!(out = (char*)malloc(sizeof(char) * (++i))))
		return (0);
	out[--i] = 0;
	in = tmp;
	while (--i > -1)
	{
		if ((in % 16) <= 9)
			out[i] = ((in % 16) + '0');
		else
			out[i] = ((in % 16) + x - 33);
		in /= 16;
	}
	return (out);
}

void	ft_masterprec(t_parameters *stock)
{
	if (!stock->prexist && stock->specifier == 'f')
		stock->precision = 6;
}
