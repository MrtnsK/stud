/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:15:33 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/09 14:59:33 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nod;

	if (!lst)
		return (NULL);
	if (!(nod = (t_list *)malloc(sizeof(f(lst)))))
		return (NULL);
	nod = f(lst);
	nod->next = ft_lstmap(lst->next, f);
	return (nod);
}
