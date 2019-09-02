/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selekbasics_pt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:47:14 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:47:16 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_basicimpossible(t_stock *stock, t_basiks *tools)
{
	tools->nbligne = 1;
	ft_printfd(0, "\e[93mimpossible to print options\e[0m\n");
	ft_reboot(stock);
	return (0);
}

int		ft_basic_end(t_stock *stock, t_stockap *pac, t_basiks *tools)
{
	int		i;
	int		j;
	t_ijer	lol;

	i = -1;
	while (++i < tools->nbligne)
	{
		j = -1;
		while (++j < tools->lignemax
			&& (i + (j * tools->nbligne)) < tools->nbobj)
		{
			lol.i = i;
			lol.j = j;
			ft_basicmainloop(stock, pac, tools, &lol);
		}
		ft_printfd(0, "\n");
	}
	ft_reboot(stock);
	return (0);
}
