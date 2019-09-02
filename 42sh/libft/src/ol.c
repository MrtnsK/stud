/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ol.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:22:50 by pharatyk          #+#    #+#             */
/*   Updated: 2019/06/27 11:16:55 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static void		ft_moins_ou_plus(char *acheker,
	int *flagmoins, int *flagplus, char **out)
{
	int i;

	i = -1;
	while (acheker[++i])
	{
		if (acheker[i] == '-')
			*flagmoins = 2;
		if (acheker[i] == '0' && *flagmoins != 2)
			*flagmoins = 1;
		if (acheker[i] == '+')
			*flagplus = 2;
		if (acheker[i] == ' ' && *flagplus != 2)
			*flagplus = 1;
		if (acheker[i] == '#')
			*out[0] = '#';
	}
	free(acheker);
}

char			*ft_plus_ou_moins(char *acheker)
{
	int		flagplus;
	int		flagmoins;
	int		i;
	int		j;
	char	*out;

	i = -1;
	j = -1;
	flagplus = 0;
	flagmoins = 0;
	if (!(out = (char *)ft_memalloc(sizeof(char) * 4)))
		return (0);
	ft_moins_ou_plus(acheker, &flagmoins, &flagplus, &out);
	if (out[0] == '#')
		j++;
	if (flagplus == 1)
		out[++j] = ' ';
	if (flagplus == 2)
		out[++j] = '+';
	if (flagmoins == 1)
		out[++j] = '0';
	if (flagmoins == 2)
		out[++j] = '-';
	out[++j] = 0;
	return (out);
}

char			*ft_convhsuite(void)
{
	char *out;

	if (!(out = (char*)malloc(sizeof(char) * 2)))
		return (0);
	ft_strcpy(out, "0");
	return (out);
}

char			*ft_convhoc(unsigned long long in)
{
	char				*out;
	unsigned long long	tmp;
	int					i;

	tmp = in;
	i = 0;
	if (in == 0)
		return (ft_convhsuite());
	while (in)
	{
		i++;
		in /= 8;
	}
	if (!(out = (char*)malloc(sizeof(char) * (++i))))
		return (0);
	out[--i] = 0;
	in = tmp;
	while (--i > -1)
	{
		out[i] = ((in % 8) + '0');
		in /= 8;
	}
	return (out);
}
