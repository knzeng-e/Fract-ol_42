/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ftratales.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:03:18 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/10/26 20:11:01 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	to_square(double nb)
{
	return (nb * nb);
}

void	put_pixel(t_infos *infos)
{
	int	color;

	color = mlx_get_color_value(infos->mlx, 0x000004FF << (infos->iter & 255));
	infos->img_data[infos->row * WIDTH + infos->col] = color;
}

void	check_pixel(t_infos *infos)
{
	int	calc;

	infos->c.real = (infos->col + infos->x_offset) / infos->x_zoom\
		+ infos->min_re;
	infos->c.imaginary = (infos->row + infos->y_offset) / infos->y_zoom\
		+ infos->min_im;
	infos->x = 0;
	infos->y = 0;
	infos->iter = 0;
	calc = (infos->x * infos->x + infos->y * infos->y);
	while (calc <= 4 && (infos->iter < infos->max_iter))
	{
		infos->x_tmp = to_square(infos->x) - to_square(infos->y)\
			+ infos->c.real;
		infos->y = 2 * infos->x * infos->y + infos->c.imaginary;
		infos->x = infos->x_tmp;
		infos->iter++;
		calc = (infos->x * infos->x + infos->y * infos->y);
	}
	if (infos->iter < infos->max_iter)
		put_pixel(infos);
	infos->col++;
}

void	mandel_fun(t_infos *infos)
{
	infos->current_fract = MANDEL_KEY;
	infos->x_zoom = WIDTH / (infos->max_re - infos->min_re);
	infos->y_zoom = HEIGHT / (infos->max_im - infos->min_im);
	infos->row = 0;
	while (infos->row < HEIGHT)
	{
		infos->col = 0;
		while (infos->col < WIDTH)
			check_pixel(infos);
		infos->row++;
	}
}
