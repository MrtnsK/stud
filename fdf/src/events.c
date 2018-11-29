/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:41 by flklein           #+#    #+#             */
/*   Updated: 2018/11/29 18:42:04 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int key, void *mlx)
{
	ft_putstr("pressed: ");
	ft_putnbr(key);
	ft_putchar('\n');
	(void)mlx;
	if (key == 53)
		exit(0);
	return (0);
}

void	show_usage(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win, 20, 10, 0x50FFFF, "Exit:");
	mlx_string_put(mlx->ptr, mlx->win, 80, 10, 0xFFFF00, "ESC");
	mlx_string_put(mlx->ptr, mlx->win, 20, 30, 0x50FFFF, "Move:");
	mlx_string_put(mlx->ptr, mlx->win, 80, 30, 0xFFFF00, "Arrow");
}
