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

int     run_julia(t_infos *infos, int mouse_x, int mouse_y)
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

    infos->x_zoom = image_x / (infos->max_re - infos->min_re);
    infos->y_zoom = image_y / (infos->max_im - infos->min_im);
    c_re = map(mouse_x, 0, WIDTH, infos->min_re, infos->max_re);
    c_im = map(mouse_y, 0, HEIGHT, infos->min_im, infos->max_im);
    row = 0;
    while (row < image_y)
    {
        col = 0;
        while (col < image_x)
        {
            x = (col + infos->x_offset) / infos->x_zoom + infos->min_re;
            y = (row + infos->y_offset) / infos->y_zoom + infos->min_im;
            iteration = 0;
            while ((x * x + y * y) <= 4 && (iteration < infos->max_iter))
            {
                x_new = x * x - y * y + c_re;
                y = 2 * x * y + c_im;
                x = x_new;
                iteration++;
            }
            if (iteration < infos->max_iter)
                infos->img_data[row * WIDTH + col] = mlx_get_color_value(infos->mlx, 0x000004FF << (iteration ^ 255));
            col++;
        }
        row++;
    }
    return (0);
}



/*int	run_julia(t_infos *infos, int x, int y)
{
    int i;
    int j;
    int	px_color;

    infos->c.real = getReal(x + infos->x_offset, WIDTH, infos->min_re, infos->max_re);
    infos->c.imaginary = getImagin(y + infos->y_offset, HEIGHT, infos->min_im, infos->max_im);
    j = 0;
    while (j < HEIGHT)
    {
        i = 0;
        while (i < WIDTH)
        {
            infos->x = getReal(i, WIDTH, infos->min_re, infos->max_re);
            infos->y = getImagin(j, HEIGHT, infos->min_im, infos->max_re);

            px_color = check_if_julia(infos);
            if (px_color < infos->max_iter)
            {
                infos->img_data[j * WIDTH + i] = mlx_get_color_value(infos->mlx, 0x000004FF << (px_color ^ 255));
            }
            i++;
        }
        j++;
    }
    return (0);
}*/
