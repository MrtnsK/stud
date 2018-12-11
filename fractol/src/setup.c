/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:42 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/11 18:54:03 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_stc *stc)
{
	stc->comp->x1 = -1;
	stc->comp->x2 = 1;
	stc->comp->y1 = -1.2;
	stc->comp->y2 = 1.2;
	stc->comp->c_r = 0.285;
	stc->comp->c_i = 0.01;
	stc->comp->iter_max = 150;
	stc->comp->color_r = 30;
	stc->comp->color_g = 15;
	stc->comp->color_b = 60;
}

void	init_mandelbrot(t_stc *stc)
{
	stc->comp->x1 = -2.1;
	stc->comp->x2 = 0.6;
	stc->comp->y1 = -1.2;
	stc->comp->y2 = 1.2;
	stc->comp->iter_max = 50;
	stc->comp->color_r = 252;
	stc->comp->color_g = 60;
	stc->comp->color_b = 60;
}

int		who(char *title)
{
	if(ft_strequ(title, "julia"))
		return (1);
	else if(ft_strequ(title, "mandelbrot"))
		return (2);
	else if(ft_strequ(title, "buddhabrot"))
		return(3);
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
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
	mlx->width = 1280;
	mlx->height = 720;
	mlx->zoom = 1;
	mlx->fractal = who(title);
	mlx->panel_choice = 0;
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, title);
	return (mlx);
}
