/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:54:54 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/12 19:59:48 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_mlx *mlx)
{
	while (mlx->x++ < mlx->width)
	{
		mlx->y = 0;
		while (mlx->y++ < mlx->height)
		{
			mlx->z_r = (mlx->x / mlx->zoom + mlx->x1) + mlx->movex;
			mlx->z_i = (mlx->y / mlx->zoom + mlx->y1) + mlx->movey;
			mlx->i = 0;
			while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < mlx->mult)
			&& (mlx->i < mlx->iter_max))
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i
				* mlx->z_i + mlx->c_r;
				mlx->z_i = 2 * mlx->z_i * mlx->tmp + mlx->c_i;
				mlx->i++;
			}
			if (mlx->i == mlx->iter_max)
				ft_fill_pixel(mlx, mlx->x, mlx->y, 0xFFFFFF);
			else
				ft_fill_pixel(mlx, mlx->x, mlx->y, mlx->i
				* ft_rgb_color(mlx));
		}
	}
}

void	draw_mandelbrot(t_mlx *mlx)
{
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
			while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < mlx->mult)
			&& (mlx->i < mlx->iter_max))
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
				mlx->z_i = 2 * mlx->z_i * mlx->tmp + mlx->c_i;
				mlx->i++;
			}
			if (mlx->i == mlx->iter_max)
				ft_fill_pixel(mlx, mlx->x, mlx->y, 0xFFFFFF);
			else
				ft_fill_pixel(mlx, mlx->x, mlx->y, mlx->i
				* ft_rgb_color(mlx));
		}
	}
}

void	ft_fractal(t_mlx *mlx)
{
	if (mlx->fractal == 1)
	{
		mlx->c_r = -0.75 + mlx->cha;
		mlx->c_i = -0.14 + mlx->cha;
		mlx->x = 0;
		draw_julia(mlx);
	}
	else if (mlx->fractal == 2)
	{
		mlx->x = 0;
		draw_mandelbrot(mlx);
	}
	else if (mlx->fractal == 3)
		return ;
}
