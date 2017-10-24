/*                                                        :::      ::::::::   */
/*   check_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 22:00:37 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/09/25 01:45:32 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void    burning_fun(t_infos *infos)
{
    int     row;
    int     col;
    int     iteration;
    double  c_re;
    double  c_im;
    double  x;
    double  y;
    double  x_new;

    double image_x = WIDTH;
    double image_y = HEIGHT;

	infos->current_fract = BURNING_KEY;
    infos->x_zoom = image_x / (infos->max_re - infos->min_re);
    infos->y_zoom = image_y / (infos->max_im - infos->min_im);
    row = 0;
    while (row < image_y)
    {
        col = 0;
        while (col < image_x)
        {
            c_re = (col + infos->x_offset) / infos->x_zoom + infos->min_re;
            c_im = (row + infos->y_offset) / infos->y_zoom + infos->min_im;
            x = 0;
            y = 0;
            iteration = 0;
            while ((fabs(x) * fabs(x) + fabs(y) * fabs(y)) <= 4 && (iteration < infos->max_iter))
            {
                x_new = fabs(x) * fabs(x) - fabs(y) * fabs(y) + c_re;
                y = 2 * fabs(x) * fabs(y) + c_im;
                x = x_new;
                iteration++;
            }
            if (iteration < infos->max_iter)
            {
                infos->img_data[row * WIDTH + col] = mlx_get_color_value(infos->mlx, 0x000004FF << (iteration ^ 255));
            }
            col++;
        }
        row++;
    }
}

