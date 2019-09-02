/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:03:38 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/09 11:03:39 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;

	i = 0;
	if (haystack == needle)
		return ((char *)haystack);
	if (!(ft_strlen(needle)))
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack && len)
	{
		if (*haystack == needle[0])
		{
			while (haystack[i] == needle[i] && (len - i) > 0)
			{
				i++;
				if (needle[i] == 0)
					return ((char *)haystack);
			}
		}
		haystack++;
		len--;
		i = 0;
	}
	return (0);
}
