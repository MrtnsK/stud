/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:30:29 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/12 19:55:14 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoommouse(int key, t_mlx *mlx)
{
	if (key == 115 && mlx->zoom < 1000000000)
	{
		mlx->zoom *= 1.2;
		mlx->x1 = mlx->x1 + (mlx->oldmx - ((double)mlx->width) / 2) \
		/ mlx->zoom;
		mlx->y1 = mlx->y1 + (mlx->oldmy - ((double)mlx->height) / 2) \
		/ mlx->zoom;
	}
	if (key == 119 && mlx->zoom > 2)
	{
		mlx->zoom *= 0.8;
		mlx->x1 = mlx->x1 + (mlx->oldmx - ((double)mlx->width) / 2) \
		/ mlx->zoom;
		mlx->y1 = mlx->y1 + (mlx->oldmy - ((double)mlx->height) / 2) \
		/ mlx->zoom;
	}
	ft_putnbr(mlx->zoom);
	ft_putchar('\n');
}

void	julia_move(int x, int y, t_mlx *mlx)
{
	if (mlx->swi == 1)
	{
		mlx->cha += (x - mlx->oldmx) * 0.00009;
		mlx->cha += (y - mlx->oldmy) * 0.00009;
	}
}

int		mouse_event(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x <= mlx->width && y >= 0 && y <= mlx->height)
	{
		julia_move(x, y, mlx);
		mlx->oldmx = x;
		mlx->oldmy = y;
	}
	ft_bzero(mlx->str, mlx->width * mlx->height * sizeof(int));
	ft_fractal(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	ft_tutorial(mlx);
	return (0);
}
