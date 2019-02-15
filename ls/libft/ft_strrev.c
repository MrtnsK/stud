/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:27:48 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/08 20:57:01 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		rev;
	char	tmp;

	i = 0;
	rev = 0;
	while (str[i])
		i++;
	i--;
	while (rev <= i)
	{
		tmp = str[rev];
		str[rev] = str[i];
		str[i] = tmp;
		rev++;
		i--;
	}
	return (str);
}
