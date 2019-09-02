/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcomparator_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:05:18 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:05:19 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_corecalcomparator_badend(char **avant)
{
	ft_printfd(2, "calc error\n");
	free(avant[0]);
	return (1);
}
