/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:35:34 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/12 11:14:52 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL
# include "mlx.h"
# include "key.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# define DEFAUT_MAXITER 60.0
# define C_ECH 2.0
# define SPEED_TRANSLATE 0.05
# define WHITE 0xFFFFFF

typedef	struct 	s_ctr
{
	int			x;
	int			y;
}				t_ctr;

typedef struct 	s_rgb
{
	float 		r;
	float		g;
	float 		b;
}				t_rgb;

typedef struct 	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pimg;
	int			bpp;
	int			endian;
	int			size_line;
    double 		pr;
    double		pi;
    double		newRe;
    double		newIm;
    double		oldRe;
    double		oldIm;
    double		bigoldRe;
    double		bigoldIm;
    long double		zoom;
    double		moveX;
    double		moveY;
	double		cRe;
	double		cIm;
	double 		freq;
	float  		l;
	int			how_window;
    int			iters;
	int 		x;
	int 		y;
	int			i;
	int			k;
	int 		keycode;
	int 		color;
	double		tmpre;
	double 		default_x;
	double 		default_y;
	t_rgb		rgb;
	t_ctr		ctr;
}				t_env;

void	ft_put_pixel_to_image(t_env *ret, int x, int y, int color);
int		ft_update_img(t_env *ret);
void	ft_map_error3(t_env *ret, int width);
void	ft_close(int fd);
void	ft_map_error2(char **value);
int		ft_error_arg(int ac);
int		ft_open(char *file);
void	ft_map_error(void);
void	ft_error(char *str);
void	ft_mallerr(void);
void	draw_julia(t_env *e);
void	draw_mandelbrot(t_env *e);
void	draw_sierpinski(t_env *e);
void	draw_ship(t_env *e);
void	draw_phoenix(t_env *e);
int		key_hook(int keycode, t_env *e);
void	ft_init_value(t_env *e);
int		button_hook(int button, int x, int y, t_env *e);
void	ft_frct(t_env *e);
int		expose_hook(t_env *e);
void	draw_multi(t_env *e);
int		ft_color(t_env *e);
int		ft_error_win(t_env *e, char **av);
void	ft_init_value2(t_env *e);
int     motion_hook(int x, int y, t_env *e);
void	ft_frct(t_env *e);
int		expose_hook(t_env *e);

#endif
