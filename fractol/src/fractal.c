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

void	make_operation(t_stc *stc)
{
	stc->comp->c_r = stc->comp->x / stc->mlx->zoom + stc->comp->x1;
	stc->comp->c_i = stc->comp->x / stc->mlx->zoom + stc->comp->y1;
	stc->comp->z_r = 0;
	stc->comp->z_i = 0;
	while ((stc->comp->z_r * stc->comp->z_r
	+ stc->comp->z_i * stc->comp->z_i) < 4
	&& stc->comp->i < stc->comp->iter_max)
	{
		stc->comp->tmp = stc->comp->z_r;
		stc->comp->z_r = stc->comp->z_r * stc->comp->z_r
		- stc->comp->z_i * stc->comp->z_i + stc->comp->c_r;
		stc->comp->z_i = 2 * stc->comp->z_i * stc->comp->tmp + stc->comp->c_i;
		stc->comp->i++;
	}
}

void	draw_fractal(t_stc *stc)
{
	stc->comp->x = 0;
	stc->comp->i = 0;
	while (stc->comp->x < stc->mlx->height)
	{
		stc->comp->y = 0;
		while (stc->comp->y < stc->mlx->width)
		{
			make_operation(stc);
	printf("ok\n");
			if (stc->comp->i == stc->comp->iter_max)
			{
				ft_fill_pixel(stc->mlx, stc->comp->x, stc->comp->y, 0xFFF4E0);
				printf("itermax\n");
			}
			else
			{
				ft_fill_pixel(stc->mlx, stc->comp->x, stc->comp->y,
				stc->comp->i * ft_rgb_color(stc));
				printf("iterpasmax\n");
			}
			printf("y = %d\n", stc->comp->y);
			printf("x = %d\n", stc->comp->x);
			stc->comp->y++;
			stc->comp->i = 0;
		}
		stc->comp->x++;
	}
}

void	ft_fractal(t_stc *stc)
{
	if (stc->mlx->fractal == 1 || stc->mlx->fractal == 2)
	{
		stc->mlx->fractal == 1 ? init_julia(stc) : init_mandelbrot(stc);
		draw_fractal(stc);
	}
/*	else if (stc->mlx->fractal == 3)
		draw_buddhabrot(stc);*/
}
