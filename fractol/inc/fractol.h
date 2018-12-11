/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:20:46 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/11 19:12:38 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_comp
{
	int		x;
	int		y;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;
	int		iter_max;
	int		color_r;
	int		color_g;
	int		color_b;
}				t_comp;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		width;
	int		height;
	void	*img;
	int		*str;
	double	zoom;
	int		fractal;
	int		panel_choice;
}				t_mlx;

typedef struct 	s_stc
{
	t_mlx	*mlx;
	t_comp	*comp;
}				t_stc;

int				ft_choose_color(int alt, t_mlx *mlx);
int				ft_close(void);
int				ft_count_values(char *str);
int				ft_key(int key, t_stc *stc);
int				ft_usage(void);
int				main(int ac, char **av);
t_mlx			*ft_mlx_setup(char *title);
void			ft_fill_pixel(t_mlx *mlx, int x, int y, int color);
void			ft_move(int key, t_stc *stc);
void			ft_reset(t_stc *stc);
void			ft_tutorial(t_stc *stc);
void			ft_fractal(t_stc *stc);
int				ft_rgb_color(t_stc *stc);
void			init_julia(t_stc *stc);
void			init_mandelbrot(t_stc *stc);

#endif
