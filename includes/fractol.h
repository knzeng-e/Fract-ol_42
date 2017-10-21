/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 00:51:52 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/09/25 16:38:49 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH 1500
# define HEIGHT 1200
# define MAX_ITER 255
# define MAX_Re 2.0
# define MIN_Re -2.0
# define MAX_Im 2.0
# define MIN_Im -2.0
# define NB_FRACTALS 2
# define ERREUR_FRACTALE 0
# define CORRECT_FRACTALE 1
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define MOVE_LEFT 123
# define MOVE_RIGHT 124
# define MOTION_NOTIFY 6
# define PTR_MOTION_MASK (1L<<6)
# define INIT_OK 2
# define ARGS_OK 3
# define ERROR_MALLOC -1
# define ERREUR_ARGS -2
# include <libft.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct	s_infos
{
	char		*fractal_name;
	int			max_iter;
	int			*ptr_img;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
    int         x_offset;
    int         y_offset;
	int			x_deb;
	int			y_deb;
    double      x_zoom;
    double      y_zoom;
	double		x;
    double      zoom;
	double		y;
    double      h;
	double		max_re;
	double		min_re;
	double		max_im;
	double		min_im;
	t_complex	c;
	void		*mlx;
	void		*win;
}				t_infos;

typedef struct  s_fractal
{
    char        *name;
    void        (*fractal_fun)(t_infos *);
}               t_fractal;

int		get_mandelbrot(t_infos *infos);
int		run_julia(t_infos *infos, int x, int y);
int		draw(t_infos *infos, int *x, int *y);
void    draw_fractal(t_infos *infos);
void	ft_init(t_infos *infos);
void    mandel_fun(t_infos *infos);
void	draw_mandelbrot(int x, int y, t_infos *infos);
void	draw_mandel(t_infos *infos);
void	mlx_draw(t_infos *infos);
double	to_square(double nb);
double	getReal(int x, int width, double minR, double maxR);
double	getImagin(int y, int height, double minI, double maxI);

#endif

