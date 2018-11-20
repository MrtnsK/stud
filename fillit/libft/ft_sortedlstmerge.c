/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortedlstmerge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:29:54 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/09 15:36:45 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortedlstmerge(t_list **list1, t_list *list2)
{
	ft_lstmerge(list1, list2);
	ft_lstsort(list1);
}
