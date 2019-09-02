/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:42:49 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 15:10:54 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static void	ft_neg(long long *n, int *isneg)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*isneg = 1;
	}
}

char		*ft_itoa(long long n)
{
	char		*out;
	long long	cpn;
	int			len;
	int			isneg;

	cpn = n;
	len = 2;
	isneg = 0;
	ft_neg(&n, &isneg);
	if (cpn <= -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	while (cpn /= 10)
		len++;
	len = (len + isneg);
	if (!(out = (char *)malloc(sizeof(char) * len)))
		return (0);
	out[--len] = 0;
	while (len-- > 0)
	{
		out[len] = n % 10 + '0';
		n = n / 10;
	}
	if (isneg == 1)
		out[0] = '-';
	return (out);
}
