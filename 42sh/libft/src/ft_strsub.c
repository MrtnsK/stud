/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:48:29 by pharatyk          #+#    #+#             */
/*   Updated: 2019/06/17 19:23:51 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = -1;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (0);
	if (!(out = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (++i < len && s[start])
		out[i] = s[start++];
	out[i] = '\0';
	return (out);
}
