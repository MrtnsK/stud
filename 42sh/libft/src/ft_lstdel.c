/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:56:42 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/13 10:56:44 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *actu;

	actu = *alst;
	while (actu)
	{
		next = actu->next;
		del(actu->content, actu->content_size);
		free(actu);
		actu = next;
	}
	*alst = NULL;
}
