/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:35:34 by etheodor          #+#    #+#             */
/*   Updated: 2015/02/04 13:00:36 by etheodor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL
# include "mlx.h"
# include "key.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# define DEFAUT_X 400
# define DEFAUT_Y 300
# define DEFAUT_CRE -0.70176
# define DEFAUT_CIM -0.3842
# define SPEED_TRANSLATE 0.05
# define WHITE 0xFFFFFF

typedef	struct 	s_ctr
{
	int			x;
	int			y;
}				t_ctr;

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
    long double		zoom;
    double		moveX;
    double		moveY;
	double		cRe;
	double		cIm;
	int			how_window;
    int			maxIterations;
	int 		x;
	int 		y;
	int			i;
	int			k;
	t_ctr		ctr;
}				t_env;

void	ft_put_pixel_to_image(t_env *ret, int x, int y, int color);
int		ft_update_img(t_env *ret, void f(t_env *ret));
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

#endif
