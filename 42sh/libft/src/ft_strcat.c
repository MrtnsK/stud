/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:14:06 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/09 13:14:07 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;

	i = -1;
	while (dest[++i])
		;
	while (*src)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest);
}

char	**ft_tabcat(char **dest, char **src)
{
	int	i;

	i = -1;
	while (dest[++i])
		;
	while (*src)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest);
}

int		*ft_tabintcat(int *dest, int *src)
{
	int	i;

	i = -1;
	while (dest[++i])
		;
	while (*src)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest);
}

char	**ft_tabcator(char **dest, char **src)
{
	int	i;
	int j;

	i = -1;
	while (dest[++i])
		;
	j = 0;
	while (*src)
	{
		dest[i] = *src;
		*src = 0;
		i++;
		src++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strcator(char *dest, char *src)
{
	int	i;
	int j;

	i = -1;
	while (dest[++i])
		;
	j = 0;
	while (*src)
	{
		dest[i] = *src;
		*src = 0;
		i++;
		src++;
	}
	dest[i] = 0;
	return (dest);
}
