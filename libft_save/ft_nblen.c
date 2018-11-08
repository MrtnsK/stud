/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:37:43 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/08 20:38:46 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nblen(long nb)
{
	int len_nb;

	len_nb = 0;
	if (nb == 0)
		return (1);
	if (nb < 0 && len_nb++)
		nb *= -1;
	while (nb != 0 && len_nb++)
		nb /= 10;
	return (len_nb);
}
