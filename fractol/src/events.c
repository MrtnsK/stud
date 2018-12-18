/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:53 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/18 17:28:09 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_tutorial(t_mlx *mlx)
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
	mlx->width - 300, 125, 0xAFB6b9, "O / P            iteration");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 150, 0xAFB6b9, "ARROWS           move");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 175, 0xAFB6b9, "HOME / END       zoom");
	mlx_string_put(mlx->ptr, mlx->win,
	mlx->width - 300, 200, 0xAFB6b9, "l;',./           colors");
}

void	ft_resetorchange(int key, t_mlx *mlx)
{
	if (key == 15)
		init_fractal(mlx);
	if (key == 30 || key == 33)
	{
		if (key == 30 && mlx->fractal > 1)
			mlx->fractal -= 1;
		if (key == 33 && mlx->fractal < 8)
			mlx->fractal += 1;
	}
	if (key == 31 || key == 35)
	{
		if (key == 31 && mlx->iter_max > 2)
			mlx->iter_max -= 1;
		if (key == 35 && mlx->iter_max < 250)
			mlx->iter_max += 1;
	}
}

void	variation_color(int key, t_mlx *mlx)
{
	if (key == 37)
		mlx->color_r += 10;
	if (key == 43)
		mlx->color_r -= 10;
	if (key == 39)
		mlx->color_b += 10;
	if (key == 44)
		mlx->color_b -= 10;
	if (key == 41)
		mlx->color_g += 10;
	if (key == 47)
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
	if (key == 116 && mlx->mult < 100)
		mlx->mult += 0.25;
	if (key == 121 && mlx->mult > 1)
		mlx->mult -= 0.25;
}

int		ft_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	if (key == 34)
		mlx->swi = mlx->swi == 0 ? 1 : 0;
	ft_move(key, mlx);
	ft_zoommouse(key, mlx);
	variation_color(key, mlx);
	ft_resetorchange(key, mlx);
	ft_bzero(mlx->str, mlx->width * mlx->height * sizeof(int));
	ft_fractal(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	ft_tutorial(mlx);
	return (0);
}
