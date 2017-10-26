/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:33:40 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/10/27 00:15:42 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define WIDTH 1200
# define HEIGHT 800
# define MAX_ITER 255
# define NB_FRACTALS 3
# define NB_FUNC 12
# define ERREUR_FRACTALE 0
# define CORRECT_FRACTALE 1
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define MOVE_LEFT 123
# define RIGHT 6
# define MOVE_RIGHT 124
# define MOVE_UP 126
# define MOVE_DOWN 125
# define BURNING_KEY 11
# define JULIA_KEY 38
# define MANDEL_KEY 46
# define SPACE_KEY 49
# define ESC 53
# define MOTION_NOTIFY 6
# define PTR_MOTION_MASK (1L<<6)
# define INIT_OK 2
# define ARGS_OK 3
# define ERROR_MALLOC -1
# define ERREUR_ARGS -2
# include <libft.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

typedef struct	s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct	s_infos
{
	char		*fractal_name;
	int			current_fract;
	int			max_iter;
	int			iter;
	int			*ptr_img;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			x_offset;
	int			y_offset;
	int			mouse_x;
	int			mouse_y;
	int			row;
	int			col;
	int			is_lock;
	double		x;
	double		y;
	double		x_zoom;
	double		y_zoom;
	double		x_tmp;
	double		in_max;
	double		in_min;
	double		out_min;
	double		out_max;
	double		zoom_scale;
	double		max_re;
	double		min_re;
	double		max_im;
	double		min_im;
	t_complex	c;
	void		*mlx;
	void		*win;
}				t_infos;

typedef struct	s_func
{
	void		(*fun)(t_infos *);
	int			key;
}				t_fun;

void			burning_fun(t_infos *infos);
int				draw(t_infos *infos, int *x, int *y);
void			draw_mandel(t_infos *infos);
int				expose_hook(t_infos *infos);
void			ft_init(t_infos *infos);
void			ft_zoom_in(t_infos *infos);
void			ft_zoom_out(t_infos *infos);
void			julia_fun(t_infos *infos);
void			lock_julia(t_infos *infos);
void			mandel_fun(t_infos *infos);
double			map_x(t_infos *infos);
double			map_y(t_infos *infos);
void			mlx_draw(t_infos *infos);
void			move_left(t_infos *infos);
void			move_right(t_infos *infos);
void			move_up(t_infos *infos);
void			move_down(t_infos *infos);
void			mouse_right(t_infos *infos);
int				pointer_motion(int x, int y, t_infos *infos);
void			quit(t_infos *infos);
void			run_functions(t_infos *infos, int current_key);
void			zoom_in(int x, int y, t_infos *infos);
void			zoom_out(int x, int y, t_infos *infos);
#endif
