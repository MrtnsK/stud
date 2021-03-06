/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:33 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/19 15:00:51 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_usage(void)
{
	ft_putstr("usage: ./fractol < julia | mandelbrot | burningship");
	ft_putendl("| thunder | tricorn | bubble | shell | plume >");
	return (0);
}

int		ft_close(void)
{
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
		return (ft_usage());
	if (!(mlx = ft_mlx_setup(av[1])))
		return (0);
	ft_fractal(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, (1L << 0), &ft_key, mlx);
	mlx_hook(mlx->win, 6, (1L << 6), &mouse_event, mlx);
	mlx_hook(mlx->win, 4, (1L << 2), &zoomwmouse, mlx);
	mlx_hook(mlx->win, 17, (1L << 17), &ft_close, NULL);
	ft_tutorial(mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
