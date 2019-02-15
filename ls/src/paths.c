/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:37:38 by agissing          #+#    #+#             */
/*   Updated: 2019/02/08 13:25:34 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*join_path(char *path1, char *path2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

	if (!path1 || !path2)
		return (NULL);
	len1 = ft_strlen(path1);
	len2 = ft_strlen(path2);
	if (!(res = ft_strnew(len1 + len2 + 2 - !path1[0])))
		return (NULL);
	i = -1;
	while (i++ < len1)
		res[i] = path1[i];
	if (path1[0])
	{
		res[len1++] = '/';
		i = -1;
	}
	while (i++ < len2)
		res[len1 + i] = path2[i];
	res[len1 + i] = '\0';
	return (res);
}
