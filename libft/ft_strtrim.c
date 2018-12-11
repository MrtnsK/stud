/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:14:33 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/09 15:13:09 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int start;
	int len;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == '\n' || s[start] == '\t' || s[start] == ' ')
		start++;
	len = ft_strlen(s) - 1;
	while (s[len] == '\n' || s[len] == '\t' || s[len] == ' ')
		len--;
	len = len - start + 1;
	len = (len < 0) ? 0 : len;
	return (ft_strsub(s, start, len));
}
