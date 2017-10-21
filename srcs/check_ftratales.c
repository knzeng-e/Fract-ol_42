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

   /* if (nb_iter  < infos->max_iter)
        infos->img_data[y * WIDTH + x] = mlx_get_color_value(infos->mlx, 0x000004FF << (nb_iter ^ 255));*/



void    mandel_fun(t_infos *infos)
{
    int     row;
    int     col;
    int     iteration;
    double  c_re;
    double  c_im;
    double  x;
    double  y;
    double  x_new;

    /*double x1 = -2.1;
    double x2 = 0.6;
    double y1 = -1.2;
    double y2 = 1.2;*/
    double image_x = WIDTH;
    double image_y = HEIGHT;

    infos->x_zoom = image_x / (infos->max_re - infos->min_re);
    infos->y_zoom = image_y / (infos->max_im - infos->min_im);
    //
    //double image_x = (infos->max_re - infos->min_re) * infos->zoom;
    //double image_y = (infos->max_im - infos->min_im) * infos->zoom;

    /*Pour x = 0 tant que x < image_x par pas de 1
    Pour y = 0 tant que y < image_y par pas de 1*/
    row = 0;
    while (row < image_y)
    {
        col = 0;
        while (col < image_x)
        {
            c_re = (col + infos->x_offset) / infos->x_zoom + infos->min_re;
            c_im = (row + infos->y_offset) / infos->y_zoom + infos->min_im;
            /*c_re = (col - WIDTH /  2.0) * 4.0 / WIDTH;
            c_im = (row - HEIGHT / 2.0) * 4.0 / WIDTH;*/
            //c_re = (col + infos->x_offset - WIDTH / 2.0) * (infos->zoom  * 4.0 / WIDTH);
            //c_im = (row + infos->y_offset - HEIGHT / 2.0) * (infos->zoom * 4.0 / HEIGHT);
            x = 0;
            y = 0;
            iteration = 0;
            while ((x * x + y * y) <= 4 && (iteration < infos->max_iter))
            {
                x_new = x * x - y * y + c_re;
                y = 2 * x * y + c_im;
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

/*void     mandel_fun(t_infos *infos)
{
    int     i;
    int     j;
    int     cpt;
    double  image_x;
    double  image_y;
    double  c_r;
    double  c_i;
    double  z_r;
    double  z_i;
    double  tmp;*/

    /*image_x = (infos->max_re - infos->min_re) * infos->zoom;
    image_y = (infos->max_im - infos->min_im) * infos->zoom;*/

 /*   image_x = WIDTH;
    image_y = HEIGHT;
    infos->x_zoom = image_x / (infos->max_re - infos->min_re);
    infos->y_zoom = image_y / (infos->max_im - infos->min_im);

    i = 0;
    while (i < image_x)
    {
        j = 0;
        while (j < image_y)
        {
            c_r = i / infos->x_zoom + infos->min_re;
            c_i = j / infos->y_zoom + infos->min_im;
            z_r = 0;
            z_i = 0;*/
            /*calcul recursif*/
           /* cpt = 0;
            while ((z_r * z_r + z_i * z_i) < 4 && (cpt < infos->max_iter))
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
                cpt++;
            }
            if (cpt != infos->max_iter)
                infos->img_data[j * WIDTH + i] = mlx_get_color_value(infos->mlx, 0x000004FF << (cpt ^ 255));
            j++;
        }
        i++;
    }*/

//}
