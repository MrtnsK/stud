/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:42 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/12 19:56:29 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_mlx *mlx)
{
	mlx->x1 = -2.1;
	mlx->x2 = 0.6;
	mlx->y1 = -1.2;
	mlx->y2 = 1.2;
	mlx->zoom = 200;
	mlx->movex = -1.50;
	mlx->movey = -0.70;
	mlx->color_r = 0;
	mlx->color_g = 0;
	mlx->color_b = 0;
	mlx->cha = 0;
	mlx->swi = 0;
	mlx->mult = 4;
	mlx->iter_max = 100;
}

int		who(char *title)
{
	if (ft_strequ(title, "julia"))
		return (1);
	else if (ft_strequ(title, "mandelbrot"))
		return (2);
	else if (ft_strequ(title, "buddhabrot"))
		return (3);
	return (0);
}

t_mlx	*ft_mlx_setup(char *title)
{
	t_mlx	*mlx;
	int		bpp;
	int		s_l;
	int		endian;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!ft_strequ(title, "mandelbrot") && !ft_strequ(title, "julia")
	&& !ft_strequ(title, "buddhabrot"))
		return (0);
	mlx->ptr = mlx_init();
	mlx->width = 1280;
	mlx->height = 720;
	mlx->fractal = who(title);
	init_fractal(mlx);
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, title);
	return (mlx);
}
