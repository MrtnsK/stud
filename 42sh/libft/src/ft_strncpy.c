/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:16:11 by pharatyk          #+#    #+#             */
/*   Updated: 2019/06/27 09:09:14 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *cpdest;

	cpdest = dest;
	while (n > 0 && *src)
	{
		*cpdest++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*cpdest++ = 0;
		--n;
	}
	return (dest);
}

int		*ft_tabintncpy(int *dest, int *src, size_t n)
{
	int *cpdest;

	cpdest = dest;
	while (n > 0)
	{
		*cpdest++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*cpdest++ = 0;
		--n;
	}
	return (dest);
}

char	**ft_tabncpy(char **dest, char **src, size_t n)
{
	char **cpdest;

	cpdest = dest;
	while (n > 0 && *src)
	{
		*cpdest++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*cpdest++ = 0;
		--n;
	}
	return (dest);
}
