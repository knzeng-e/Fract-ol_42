/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 20:25:20 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/09/25 16:43:24 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    julia_fun(t_infos *infos)
{
    int     row;
    int     col;
    int     iteration;
    double  x;
    double  y;
    double  x_new;

    infos->x_zoom = WIDTH / (infos->max_re - infos->min_re);
    infos->y_zoom = HEIGHT / (infos->max_im - infos->min_im);
    if (!infos->is_lock)
    {
        infos->c.real = map(infos->mouse_x, 0, WIDTH, infos->min_re, infos->max_re);
        infos->c.imaginary = map(infos->mouse_y, 0, HEIGHT, infos->min_im, infos->max_im);
    }
    row = 0;
    while (row < HEIGHT)
    {
        col = 0;
        while (col < WIDTH)
        {
            x = (col + infos->x_offset) / infos->x_zoom + infos->min_re;
            y = (row + infos->y_offset) / infos->y_zoom + infos->min_im;
            iteration = 0;
            while ((x * x + y * y) <= 4 && (iteration < infos->max_iter))
            {
                x_new = x * x - y * y + infos->c.real;
                y = 2 * x * y + infos->c.imaginary;
                x = x_new;
                iteration++;
            }
            if (iteration < infos->max_iter)
                infos->img_data[row * WIDTH + col] = mlx_get_color_value(infos->mlx, 0x000004FF << (iteration ^ 255));
            col++;
        }
        row++;
    }
}
