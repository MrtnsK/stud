/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:33 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/11 19:50:43 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_usage(void)
{
	ft_putendl("usage: ./fractol <fractal_name>");
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
	t_comp	*comp;
	t_stc	*stc;

	if (ac != 2)
		return (ft_usage());
	if (!(mlx = ft_mlx_setup(av[1])))
		return (0);
	if (!(stc = (t_stc*)malloc(sizeof(t_stc*))))
		return (0);
	if (!(comp = (t_comp*)malloc(sizeof(t_comp*))))
		return (0);
	stc->mlx = mlx;
	stc->comp = comp;
	ft_fractal(stc);
	printf("fin fractal\n");
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	printf("fin imgtowdw\n");
	mlx_hook(mlx->win, 2, (1L << 0), &ft_key, stc);
	mlx_hook(mlx->win, 17, (1L << 17), &ft_close, NULL);
	ft_tutorial(stc);
	mlx_loop(mlx->ptr);
	return (0);
}
