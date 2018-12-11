/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:22:49 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/08 21:06:46 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long		nb;

	nb = (long)n;
	if (!(str = ft_strnew(ft_nblen(n))))
		return (NULL);
	if (nb < 0)
		nb *= -1;
	i = 0;
	while (nb != 0 || i == 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
