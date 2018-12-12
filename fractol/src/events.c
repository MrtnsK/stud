/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:53 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/12 17:49:06 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_tutorial(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 25, 0xAFB6b9, "        How to?");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 50, 0xAFB6b9, "ESC              quit");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 75, 0xAFB6b9, "R                reset");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 100, 0xAFB6b9, "[ or ]           fractal");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 125, 0xAFB6b9, "PAGE UP / DOWN   iteration");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 150, 0xAFB6b9, "ARROWS           move");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 175, 0xAFB6b9, "HOME / END       zoom");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 200, 0xAFB6b9, "NUMBERS          colors");
}

void ft_resetorchange(int key, t_mlx *mlx)
{
	if (key == 15)
	{
		mlx->zoom = 200;
		mlx->movex = -1.50;
		mlx->movey = -0.70;
		mlx->color_r = 0;
		mlx->color_g = 0;
		mlx->color_b = 0;
		mlx->cha = 0;
		mlx->swi = 0;
	}
	if (key == 30 || key == 33)
	{
		if (key == 30 && mlx->fractal > 1)
			mlx->fractal -= 1;
		if (key == 33 && mlx->fractal < 2)
			mlx->fractal += 1;
	}
}

void	variation_color(int key, t_mlx *mlx)
{
	if (key == 37)
		mlx->color_r += 10;
	if (key == 43)
		mlx->color_r -= 10;
	if (key == 41)
		mlx->color_b += 10;
	if (key == 47)
		mlx->color_b -= 10;
	if (key == 39)
		mlx->color_g += 10;
	if (key == 44)
		mlx->color_g -= 10;
}

void	ft_move(int key, t_mlx *mlx)
{
	double	value;

	value = 10 / mlx->zoom;
	if (key == 124)
		mlx->movex -= value;
	if (key == 123)
		mlx->movex += value;
	if (key == 125)
		mlx->movey -= value;
	if (key == 126)
		mlx->movey += value;
	if (key == 115)
		mlx->zoom += 50 * 1.5;
	if (key == 119)
		mlx->zoom -= 50 * 1.5;
	if (key == 116)
		mlx->iter_max += 10;
	if (key == 121)
		mlx->iter_max -= 10;
}

int ft_key(int key, t_mlx *mlx)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	if (key == 34)
		mlx->swi = mlx->swi == 0 ? 1 : 0;
	ft_move(key, mlx);
	variation_color(key, mlx);
	ft_resetorchange(key, mlx);
	ft_bzero(mlx->str, mlx->width * mlx->height * sizeof(int));
	ft_fractal(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	ft_tutorial(mlx);
	return (0);
}
