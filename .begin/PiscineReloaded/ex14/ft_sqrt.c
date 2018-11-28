/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:54:21 by kemartin          #+#    #+#             */
/*   Updated: 2018/08/29 13:57:29 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb != 2147483647)
		while (i * i != nb && i * i <= nb)
			i++;
	return (i * i == nb ? i : 0);
}
