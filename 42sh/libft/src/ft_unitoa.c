/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:52:33 by hmoulher          #+#    #+#             */
/*   Updated: 2019/06/17 19:36:35 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static	int		nbr_digit(unsigned long long n)
{
	int nbr;

	nbr = 0;
	while (n)
	{
		n /= 10;
		nbr++;
	}
	return (nbr);
}

static	char	*reverse(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	if (str[0] == '-')
		i++;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

char			*ft_unitoa(unsigned long long n)
{
	int					i;
	int					len;
	unsigned long long	n_long;
	char				*str;

	i = 0;
	n_long = (unsigned long long)n;
	len = nbr_digit(n_long);
	if (len == 0)
		len = 1;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i++] = (n_long % 10) + '0';
		n_long /= 10;
	}
	str[i] = '\0';
	str = reverse(str);
	return (str);
}
