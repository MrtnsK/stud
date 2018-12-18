/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extfractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:17:05 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/18 18:03:57 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_thunder(void *thrv)
{
	t_thread	*t;
	t_calc		c;
	int			min;
	int			max;
	int			y;

	t = (t_thread *)thrv;
	c.c_r = 0;
	c.c_i = 1;
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
			while ((c.z_r * c.z_r + c.z_i * c.z_i < t->mlx->mult)
			&& (c.i < t->mlx->iter_max))
			{
				c.tmp = c.z_r;
				c.z_r = c.z_r * c.z_r - c.z_i
				* c.z_i + c.c_r;
				c.z_i = 2 * c.z_i * c.tmp + c.c_i;
				c.i++;
			}
			if (c.i == t->mlx->iter_max)
				ft_fill_pixel(t->mlx, min, y, 0x000000);
			else
				ft_fill_pixel(t->mlx, min, y, c.i
				* ft_rgb_color(t->mlx));
		}
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*draw_tricorn(void *thrv)
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
			while ((c.z_r * c.z_r + c.z_i * c.z_i < t->mlx->mult)
			&& (c.i < t->mlx->iter_max))
			{
				c.tmp = c.z_r;
				c.z_r = c.z_r * c.z_r - c.z_i * c.z_i + c.c_r;
				c.z_i = -2 * c.z_i * c.tmp + c.c_i;
				c.i++;
			}
			if (c.i == t->mlx->iter_max)
				ft_fill_pixel(t->mlx, min, y, 0x000000);
			else
				ft_fill_pixel(t->mlx, min, y, c.i
				* ft_rgb_color(t->mlx));
		}
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*draw_bubble(void *thrv)
{
	t_thread	*t;
	t_calc		c;
	int			min;
	int			max;
	int			y;

	t = (t_thread *)thrv;
	c.c_r = -1.25 + t->mlx->cha;
	c.c_i = 0 + t->mlx->cha;
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
			while ((c.z_r * c.z_r + c.z_i * c.z_i < t->mlx->mult)
			&& (c.i < t->mlx->iter_max))
			{
				c.tmp = c.z_r;
				c.z_r = c.z_r * c.z_r - c.z_i
				* c.z_i + c.c_r;
				c.z_i = 2 * c.z_i * c.tmp + c.c_i;
				c.i++;
			}
			if (c.i == t->mlx->iter_max)
				ft_fill_pixel(t->mlx, min, y, 0x000000);
			else
				ft_fill_pixel(t->mlx, min, y, c.i
				* ft_rgb_color(t->mlx));
		}
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*draw_shell(void *thrv)
{
	t_thread	*t;
	t_calc		c;
	int			min;
	int			max;
	int			y;

	t = (t_thread *)thrv;
	c.c_r = 0.45;
	c.c_i = 0.1428;
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
			while ((c.z_r * c.z_r + c.z_i * c.z_i < t->mlx->mult)
			&& (c.i < t->mlx->iter_max))
			{
				c.tmp = c.z_r;
				c.z_r = c.z_r * c.z_r - c.z_i
				* c.z_i + c.c_r;
				c.z_i = 2 * c.z_i * c.tmp + c.c_i;
				c.i++;
			}
			if (c.i == t->mlx->iter_max)
				ft_fill_pixel(t->mlx, min, y, 0x000000);
			else
				ft_fill_pixel(t->mlx, min, y, c.i
				* ft_rgb_color(t->mlx));
		}
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*draw_plume(void *thrv)
{
	t_thread	*t;
	t_calc		c;
	int			min;
	int			max;
	int			y;

	t = (t_thread *)thrv;
	c.c_r = -0.1011;
	c.c_i = 0.9563;
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
			while ((c.z_r * c.z_r + c.z_i * c.z_i < t->mlx->mult)
			&& (c.i < t->mlx->iter_max))
			{
				c.tmp = c.z_r;
				c.z_r = c.z_r * c.z_r - c.z_i
				* c.z_i + c.c_r;
				c.z_i = 1 * c.z_i * c.tmp + c.c_i;
				c.i++;
			}
			if (c.i == t->mlx->iter_max)
				ft_fill_pixel(t->mlx, min, y, 0x000000);
			else
				ft_fill_pixel(t->mlx, min, y, c.i
				* ft_rgb_color(t->mlx));
		}
	}
	pthread_exit(NULL);
	return (NULL);
	}
