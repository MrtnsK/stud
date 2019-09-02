/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hereshlag_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:50:21 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/02 13:41:41 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_herror(t_keymaster *lock)
{
	free(lock->sep);
	lock->sep = NULL;
	ft_printfd(2, "\e[93mMastershell\e[0m: parse error\n");
	return (-10);
}
