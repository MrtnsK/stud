/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:28 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/11 18:26:21 by kemartin         ###   ########.fr       */
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

int		ft_rgb_color(t_stc *stc)
{
	if (stc->comp->color_r > 255)
		stc->comp->color_r = 55;
	if (stc->comp->color_g > 255)
		stc->comp->color_g = 55;
	if (stc->comp->color_b > 255)
		stc->comp->color_b = 55;
	if (stc->comp->color_r < 0)
		stc->comp->color_r = 0;
	if (stc->comp->color_g < 0)
		stc->comp->color_g = 0;
	if (stc->comp->color_b < 0)
		stc->comp->color_b = 0;
	return (((stc->comp->color_r & 0xff) << 16) + ((stc->comp->color_g & 0xff) << 8)
	+ (stc->comp->color_b & 0xff));
}

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
		mlx->str[x + mlx->width * y] = color;
}

