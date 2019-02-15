/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:28:51 by agissing          #+#    #+#             */
/*   Updated: 2019/01/25 12:46:46 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putbuff(t_buf *i)
{
	write(1, &i->buf, i->id);
	ft_bzero(i, sizeof(t_buf));
}

void	ft_addchar(t_buf *i, char c)
{
	if (i->id == BUFSIZE_LS - 1)
		ft_putbuff(i);
	i->buf[i->id++] = c;
}

void	ft_addstr(t_buf *i, char *str)
{
	if (i->id + ft_strlen(str) + 1 >= BUFSIZE_LS)
		ft_putbuff(i);
	while (*str)
		i->buf[i->id++] = *str++;
}

void	ft_addtwostr(t_buf *i, char *str, char *str2)
{
	if (i->id + ft_strlen(str) + ft_strlen(str2) + 1 >= BUFSIZE_LS)
		ft_putbuff(i);
	while (*str)
		i->buf[i->id++] = *str++;
	while (*str2)
		i->buf[i->id++] = *str2++;
}

void	ft_addnbr(t_buf *i, int n)
{
	long		nbr;
	unsigned	cpy;
	unsigned	size;

	nbr = (long)n;
	size = 0;
	cpy = n < 0 ? -n : n;
	if (nbr < 0)
	{
		ft_addchar(i, '-');
		nbr = -nbr;
	}
	while ((cpy /= 10) > 0)
		size++;
	(i->id + size >= BUFSIZE_LS) ? ft_putbuff(i) : 0;
	if (nbr >= 10)
		ft_addnbr(i, nbr / 10);
	ft_addchar(i, nbr % 10 + '0');
}
