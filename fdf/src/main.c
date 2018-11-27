/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:42:51 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/27 15:12:07 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	t_mlx	*mlx;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx = ft_mlx_setup(800, 600);
	ft_img_setup(mlx);
	while (i <= 799)
	{
		j = 0;
		while (j <= 599)
		{
			if (j % 20 < 10)
				ft_fill_pxl(mlx, i, j, 0xFFFFFF);
			else
				ft_fill_pxl(mlx, i, j, 0xCD5C5C);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->ptr);
	return (0);
}
