/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:42:11 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/12 19:46:28 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfind(t_list *node, void *data_ref)
{
	if (!node)
		return (NULL);
	else if (ft_strcmp(node->content_size, data_ref) == 0)
		return (node);
	else
		return (ft_lstfind(node->next, data_ref));
}
