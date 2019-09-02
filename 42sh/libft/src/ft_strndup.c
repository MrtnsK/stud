/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:55:48 by hmoulher          #+#    #+#             */
/*   Updated: 2019/01/17 12:02:46 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = (char*)malloc(sizeof(char) * (n + 1))))
		return (0);
	while (s[++i] && n > 0)
	{
		str[i] = s[i];
		n--;
	}
	str[i] = '\0';
	return (str);
}
