/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:57:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/10/26 23:14:09 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	carre(double nb)
{
	return (nb * nb);
}

void	put_pixel2(t_infos *infos)
{
	int	color;

	color = mlx_get_color_value(infos->mlx, 0x000004FF << (infos->iter & 255));
	if (infos->iter < infos->max_iter)
		infos->img_data[infos->row * WIDTH + infos->col] = color;
}

void	check_julia(t_infos *infos)
{
	infos->x = (infos->col + infos->x_offset) / infos->x_zoom + infos->min_re;
	infos->y = (infos->row + infos->y_offset) / infos->y_zoom + infos->min_im;
	infos->iter = 0;
	while ((carre(infos->x) + carre(infos->y)) <= 4\
			&& (infos->iter < infos->max_iter))
	{
		infos->x_tmp = carre(infos->x) - carre(infos->y) + infos->c.real;
		infos->y = 2 * infos->x * infos->y + infos->c.imaginary;
		infos->x = infos->x_tmp;
		infos->iter++;
	}
	put_pixel2(infos);
	infos->col++;
}

void	julia_fun(t_infos *infos)
{
	infos->current_fract = JULIA_KEY;
	infos->x_zoom = WIDTH / (infos->max_re - infos->min_re);
	infos->y_zoom = HEIGHT / (infos->max_im - infos->min_im);
	if (!infos->is_lock)
	{
		infos->c.real = map_x(infos);
		infos->c.imaginary = map_y(infos);
	}
	infos->row = 0;
	while (infos->row < HEIGHT)
	{
		infos->col = 0;
		while (infos->col < WIDTH)
			check_julia(infos);
		infos->row++;
	}
}
