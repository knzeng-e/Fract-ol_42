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

double	getReal(int x, int width, double minR, double maxR)
{
	double	range = maxR - minR;

   // c_re = (x - width/2.0)*4.0/width;
   // pr = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
	return ((x * (range / width)) + minR);
}

double	getImagin(int y, int height, double minI, double maxI)
{
	double range = minI - maxI;

	//return (y * (range / height) + minI);
	return ((y * (range / height)) + maxI);
}

int	check_if_julia(t_infos *infos)
{
    int		cpt;
    double	x_temp;
    double	lim;

    cpt = 0;
    lim = 0.0;
    while ((cpt < infos->max_iter) && (lim < 4.0))
    {
        x_temp = to_square(infos->x) - to_square(infos->y) + infos->c.real;
        infos->y = (2.0 * infos->x * infos->y) + infos->c.imaginary;
        infos->x = x_temp;
        lim = to_square(infos->x) + to_square(infos->y);
        cpt++;
    }
    return (cpt);
}

int	run_julia(t_infos *infos, int x, int y)
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
}
