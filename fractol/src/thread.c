/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:28:50 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/19 14:59:09 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	simple_multithread(t_mlx *mlx, void *function)
{
	t_thread	tab[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		tab[i].id = i;
		tab[i].mlx = mlx;
		pthread_create(&tab[i].thr, NULL, function, &(tab[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(tab[i++].thr, NULL);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
