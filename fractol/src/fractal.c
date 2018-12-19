/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:54:54 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/19 16:09:48 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_julia(void *thrv)
{
	t_thread	*t;
	t_calc		c;
	int			min;
	int			max;
	int			y;

	t = (t_thread *)thrv;
	c.c_r = -0.75 + t->mlx->cha;
	c.c_i = -0.14 + t->mlx->cha;
	min = t->id * t->mlx->width / THREADS;
	max = (t->id + 1) * t->mlx->width / THREADS;
	while (min++ < max)
	{
		y = 0;
		while (y++ < t->mlx->height)
		{
			c.z_r = (min / t->mlx->zoom + t->mlx->x1) + t->mlx->movex;
			c.z_i = (y / t->mlx->zoom + t->mlx->y1) + t->mlx->movey;
			c.i = 0;
			btsjm_helper(c, t, min, y);
		}
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*draw_mandelbrot(void *thrv)
{
	t_thread	*t;
	t_calc		c;
	int			min;
	int			max;
	int			y;

	t = (t_thread *)thrv;
	min = t->id * t->mlx->width / THREADS;
	max = (t->id + 1) * t->mlx->width / THREADS;
	while (min++ < max)
	{
		y = 0;
		while (y++ < t->mlx->height)
		{
			c.c_r = (min / t->mlx->zoom + t->mlx->x1) + t->mlx->movex;
			c.c_i = (y / t->mlx->zoom + t->mlx->y1) + t->mlx->movey;
			c.z_r = 0;
			c.z_i = 0;
			c.i = 0;
			btsjm_helper(c, t, min, y);
		}
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*draw_burningship(void *thrv)
{
	t_thread	*t;
	t_calc		c;
	int			min;
	int			max;
	int			y;

	t = (t_thread *)thrv;
	min = t->id * t->mlx->width / THREADS;
	max = (t->id + 1) * t->mlx->width / THREADS;
	while (min++ < max)
	{
		y = 0;
		while (y++ < t->mlx->height)
		{
			c.c_r = (min / t->mlx->zoom + t->mlx->x1) + t->mlx->movex;
			c.c_i = (y / t->mlx->zoom + t->mlx->y1) + t->mlx->movey;
			c.z_r = 0;
			c.z_i = 0;
			c.i = 0;
			burningship_helper(c, t, min, y);
		}
	}
	pthread_exit(NULL);
	return (NULL);
}

void	ft_fractal(t_mlx *mlx)
{
	if (mlx->fractal == 1)
		simple_multithread(mlx, draw_julia);
	else if (mlx->fractal == 2)
		simple_multithread(mlx, draw_mandelbrot);
	else if (mlx->fractal == 3)
		simple_multithread(mlx, draw_burningship);
	else if (mlx->fractal == 4)
		simple_multithread(mlx, draw_thunder);
	else if (mlx->fractal == 5)
		simple_multithread(mlx, draw_tricorn);
	else if (mlx->fractal == 6)
		simple_multithread(mlx, draw_bubble);
	else if (mlx->fractal == 7)
		simple_multithread(mlx, draw_shell);
	else if (mlx->fractal == 8)
		simple_multithread(mlx, draw_plume);
}
