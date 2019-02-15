/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:13:43 by agissing          #+#    #+#             */
/*   Updated: 2018/11/08 14:29:09 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
	}
	if (*s1 || *s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
