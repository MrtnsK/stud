/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx->fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:05:12 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/11 17:45:55 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->x++ < mlx->width)
	{
		mlx->y = 0;
		while (mlx->y++ < mlx->height)
			{
				mlx->z_r = (mlx->x / mlx->zoom + mlx->x1) + mlx->movex;
				mlx->z_i = (mlx->y / mlx->zoom + mlx->y1) + mlx->movey;
				mlx->i = 0;
				while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4) && (mlx->i < mlx->iter_max))
				{
					mlx->tmp = mlx->z_r;
					mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i *	mlx->z_i + mlx->c_r;
					mlx->z_i = 2 * mlx->z_i * mlx->tmp + mlx->c_i;
					mlx->i++;
				}
				if (mlx->i == mlx->iter_max)
					ft_fill_pixel(mlx, mlx->x, mlx->y, 0xFFFFFF);
				else
					ft_fill_pixel(mlx, mlx->x, mlx->y, mlx->i * ft_rgb_color(mlx));
			}
	}
}

void	draw_mandelbrot(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->x++ < mlx->width)
	{
		mlx->y = 0;
		while (mlx->y++ < mlx->height)
			{
				mlx->c_r = (mlx->x / mlx->zoom + mlx->x1) + mlx->movex;
				mlx->c_i = (mlx->y / mlx->zoom + mlx->y1) + mlx->movey;
				mlx->z_r = 0;
				mlx->z_i = 0;
				mlx->i = 0;
				while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4) && (mlx->i < mlx->iter_max))
				{
					mlx->tmp = mlx->z_r;
					mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i *	mlx->z_i + mlx->c_r;
					mlx->z_i = 2 * mlx->z_i * mlx->tmp + mlx->c_i;
					mlx->i++;
				}
				if (mlx->i == mlx->iter_max)
					ft_fill_pixel(mlx, mlx->x, mlx->y, 0xFFFFFF);
				else
					ft_fill_pixel(mlx, mlx->x, mlx->y, mlx->i * ft_rgb_color(mlx));
			}
	}
}

void	ft_fractal(t_mlx *mlx)
{
	if (mlx->fractal == 1)
	{
		init_julia(mlx);
		draw_julia(mlx);
	}
	else if (mlx->fractal == 2)
	{
		init_mandelbrot(mlx);
		draw_mandelbrot(mlx);
	}
/*	else if (mlx->fractal == 3)
		draw_buddhabrot(mlx);*/
}
