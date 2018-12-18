/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:20:46 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/18 18:04:05 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define THREADS 8

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

#include <stdio.h>

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	int				width;
	int				height;
	void			*img;
	int				*str;
	double			zoom;
	int				fractal;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			movex;
	double			movey;
	double			cha;
	double			mult;
	int				iter_max;
	int				swi;
	int				oldmx;
	int				oldmy;
	int				color_r;
	int				color_g;
	int				color_b;
}					t_mlx;

typedef struct		s_calc
{
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	int				i;
	double			tmp;
}					t_calc;

typedef struct		s_thread
{
	int				id;
	t_mlx			*mlx;
	pthread_t		thr;
}					t_thread;

int					ft_choose_color(int alt, t_mlx *mlx);
int					ft_close(void);
int					ft_count_values(char *str);
int					ft_key(int key, t_mlx *mlx);
int					mouse_event(int x, int y, t_mlx *mlx);
void				ft_zoommouse(int key, t_mlx *mlx);
int					zoomwmouse(int key, int x, int y, t_mlx *mlx);
int					ft_usage(void);
int					main(int ac, char **av);
t_mlx				*ft_mlx_setup(char *title);
void				ft_fill_pixel(t_mlx *mlx, int x, int y, int color);
void				ft_move(int key, t_mlx *mlx);
void				ft_reset(int key, t_mlx *mlx);
void				ft_tutorial(t_mlx *mlx);
void				ft_fractal(t_mlx *mlx);
int					ft_rgb_color(t_mlx *mlx);
void				simple_multithread(t_mlx *mlx, void *function);
void				init_fractal(t_mlx *mlx);
void				*draw_burningship(void *thrv);
void				*draw_julia(void *thrv);
void				*draw_mandelbrot(void *thrv);
void				*draw_thunder(void *thrv);
void				*draw_tricorn(void *thrv);
void				*draw_bubble(void *thrv);
void				*draw_shell(void *thrv);
void				*draw_plume(void *thrv);

#endif
