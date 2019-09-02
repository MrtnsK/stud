/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:52:46 by hmoulher          #+#    #+#             */
/*   Updated: 2019/06/27 16:01:57 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static int		ft_dissekator(unsigned int *a)
{
	unsigned int	tab[32];
	int				bittab[32];
	unsigned int	multideux;
	unsigned int	resultat;
	int				i;

	multideux = 1;
	i = -1;
	while (++i < 32)
	{
		tab[i] = multideux;
		multideux = multideux * 2;
	}
	i = -1;
	while (++i < 32)
	{
		resultat = *a & tab[i];
		if (resultat == tab[i])
			bittab[i] = 1;
		else
			bittab[i] = 0;
	}
	return (bittab[31]);
}

static int		ft_balancetonsign(long double f)
{
	long double		lol;
	unsigned int	*a;
	float			dj;

	lol = f / 2;
	if (lol < 0)
		return (1);
	else if (lol > 0)
		return (0);
	dj = (float)f;
	a = (unsigned int*)(&dj);
	return (ft_dissekator(a));
}

static char		*ft_nan_inf(float f)
{
	char *out;

	out = NULL;
	if (!(f == f))
	{
		if (!(out = (char*)malloc(sizeof(char) * 4)))
			return (0);
		ft_strcpy(out, "nan");
	}
	else if (f == INF)
	{
		if (!(out = (char*)malloc(sizeof(char) * 4)))
			return (0);
		ft_strcpy(out, "inf");
	}
	else if (f == LINF)
	{
		if (!(out = (char*)malloc(sizeof(char) * 5)))
			return (0);
		ft_strcpy(out, "-inf");
	}
	return (out);
}

char			*ft_ftoa(long double f, size_t prec)
{
	long long	exposant;
	long double	mantisse;
	char		*str;
	int			flag;
	size_t		i;

	i = -1;
	if (!(f == f) || f == INF || f == LINF)
		return (ft_nan_inf(f));
	flag = ft_balancetonsign(f);
	exposant = (long long)f;
	mantisse = f - exposant;
	if (!(str = ft_itoa(exposant)))
		return (0);
	str = ft_strjoin_free(str, ".");
	if (flag)
		mantisse *= -1;
	while (++i < (prec + 10) && mantisse)
	{
		str = ft_strjoin_ufree(str, ft_itoa((long long)(mantisse * 10)));
		mantisse = (mantisse * 10) - (long long)(mantisse * 10);
	}
	if (flag && str[0] != '-')
		str = ft_strjoin("-", str);
	return (str);
}
