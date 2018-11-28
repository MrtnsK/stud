/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:41 by flklein           #+#    #+#             */
/*   Updated: 2018/11/28 15:31:08 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int key, void *mlx)
{
	ft_putstr("pressed: ");
	ft_putnbr(key);
	ft_putchar('\n');
	(void)mlx;
	if (key == ECHAP)
		exit(0);
	return (0);
}