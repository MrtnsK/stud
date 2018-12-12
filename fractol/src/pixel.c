/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:28 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/12 13:54:26 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
/*
	mlx->panel[4][0] = 0x393E46;
	mlx->panel[4][1] = 0x00ADB5;
	mlx->panel[4][2] = 0xFFF4E0;
	mlx->panel[4][3] = 0xF8B500;
	mlx->panel[4][4] = 0xFC3C3C;
*/

int		ft_rgb_color(t_mlx *mlx)
{
	if (mlx->color_r > 255)
		mlx->color_r = 55;
	if (mlx->color_g > 255)
		mlx->color_g = 55;
	if (mlx->color_b > 255)
		mlx->color_b = 55;
	if (mlx->color_r < 0)
		mlx->color_r = 0;
	if (mlx->color_g < 0)
		mlx->color_g = 0;
	if (mlx->color_b < 0)
		mlx->color_b = 0;
	return (((mlx->color_r & 0xff) << 16) + ((mlx->color_g & 0xff) << 8)
	+ (mlx->color_b & 0xff));
}

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
		mlx->str[x + mlx->width * y] = color;
}

