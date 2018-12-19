/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:01:41 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/19 16:10:47 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	btsjm_helper(t_calc c, t_thread *t, int min, int y)
{
	while ((c.z_r * c.z_r + c.z_i * c.z_i < t->mlx->mult)
	&& (c.i < t->mlx->iter_max))
	{
		c.tmp = c.z_r;
		c.z_r = c.z_r * c.z_r - c.z_i * c.z_i + c.c_r;
		c.z_i = 2 * c.z_i * c.tmp + c.c_i;
		c.i++;
	}
	c.i == t->mlx->iter_max ? ft_fill_pixel(t->mlx, min, y, 0x000000) :
	ft_fill_pixel(t->mlx, min, y, c.i * ft_rgb_color(t->mlx));
}

void	burningship_helper(t_calc c, t_thread *t, int min, int y)
{
	while ((c.z_r * c.z_r + c.z_i * c.z_i < t->mlx->mult)
	&& (c.i < t->mlx->iter_max))
	{
		c.tmp = c.z_r;
		c.z_r = c.z_r * c.z_r - c.z_i * c.z_i + c.c_r;
		c.z_i = 2 * fabs(c.z_i * c.tmp) + c.c_i;
		c.i++;
	}
	c.i == t->mlx->iter_max ? ft_fill_pixel(t->mlx, min, y, 0x000000) :
	ft_fill_pixel(t->mlx, min, y, c.i * ft_rgb_color(t->mlx));
}

void	plume_helper(t_calc c, t_thread *t, int min, int y)
{
	while ((c.z_r * c.z_r + c.z_i * c.z_i < t->mlx->mult)
	&& (c.i < t->mlx->iter_max))
	{
		c.tmp = c.z_r;
		c.z_r = c.z_r * c.z_r - c.z_i * c.z_i + c.c_r;
		c.z_i = 1 * c.z_i * c.tmp + c.c_i;
		c.i++;
	}
	c.i == t->mlx->iter_max ? ft_fill_pixel(t->mlx, min, y, 0x000000) :
	ft_fill_pixel(t->mlx, min, y, c.i * ft_rgb_color(t->mlx));
}

void	tricorn_helper(t_calc c, t_thread *t, int min, int y)
{
	while ((c.z_r * c.z_r + c.z_i * c.z_i < t->mlx->mult)
	&& (c.i < t->mlx->iter_max))
	{
		c.tmp = c.z_r;
		c.z_r = c.z_r * c.z_r - c.z_i * c.z_i + c.c_r;
		c.z_i = -2 * c.z_i * c.tmp + c.c_i;
		c.i++;
	}
	c.i == t->mlx->iter_max ? ft_fill_pixel(t->mlx, min, y, 0x000000) :
	ft_fill_pixel(t->mlx, min, y, c.i * ft_rgb_color(t->mlx));
}
