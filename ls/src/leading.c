/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:58:47 by agissing          #+#    #+#             */
/*   Updated: 2019/02/07 20:46:59 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	leading(int size, char *str, t_buf *i)
{
	int		j;

	j = 0;
	while (str[j++])
		size--;
	ft_addstr(i, str);
	while (size-- > 0)
		ft_addchar(i, ' ');
}

void	leading_nbr(int size, int nbr, t_buf *i)
{
	unsigned	cpy;

	cpy = nbr < 0 ? -nbr : nbr;
	while ((cpy /= 10) > 0)
		size--;
	size--;
	while (size-- >= 0)
		ft_addchar(i, ' ');
	ft_addnbr(i, nbr);
	ft_addchar(i, ' ');
}

void	leading_nbr2(int size, int nbr, t_buf *i)
{
	unsigned	cpy;

	cpy = nbr < 0 ? -nbr : nbr;
	while ((cpy /= 10) > 0)
		size--;
	size--;
	ft_addnbr(i, nbr);
	while (size-- >= 0)
		ft_addchar(i, ' ');
	ft_addchar(i, ' ');
}
