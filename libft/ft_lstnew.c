/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:25:56 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/09 14:19:57 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nod;

	if ((nod = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		nod->content = NULL;
		nod->content_size = 0;
	}
	else
	{
		nod->content = ft_memalloc(content_size);
		nod->content = ft_memcpy(nod->content, content, content_size);
		nod->content_size = content_size;
	}
	nod->next = NULL;
	return (nod);
}
