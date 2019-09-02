/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:17:51 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:47:22 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_basicmainloop(t_stock *stock, t_stockap *pac, t_basiks *tools,
	t_ijer *lol)
{
	if ((lol->i + (lol->j * tools->nbligne)) == stock->select)
		ft_printfd(0, "%s", pac->rv_cap);
	ft_printfd(0, "%s", stock->output[lol->i + (lol->j * tools->nbligne)]);
	ft_printfd(0, "%s", pac->me_cap);
}
