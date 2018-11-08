/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:25:56 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/08 21:55:38 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nod;

	if (!(nod = (t_list *)malloc(sizeof(*nod))))
		return (NULL);
	if (content == NULL)
	{
		nod->content = NULL;
		nod->content_size = 0;
	}
	else
	{
		if (!(nod->content = (malloc(content_size))))
			return (NULL);
		nod->content = ft_memcpy(nod->content, content, content_size);
		nod->content_size = content_size;
	}
	nod->next = NULL;
	return (nod);
}
