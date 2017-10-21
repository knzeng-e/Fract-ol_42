/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 07:38:18 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/09/25 16:41:34 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void    draw_fractal(t_infos *infos)
{
    t_fractal   fractal_tab[2];
    int         index;

    fractal_tab[0].name = "Mandelbrot";
    fractal_tab[0].fractal_fun = mandel_fun;
    fractal_tab[1].name = "Julia";
    fractal_tab[1].fractal_fun = julia_fun;
    index = 0;
    while ((index < NB_FRACTALS) && ft_strcmp(infos->fractal_name, fractal_tab[index].name) != 0)
        index++;
    fractal_tab[index].fractal_fun(infos);
}

int		expose_hook(t_infos *infos)
{
    ft_bzero(infos->img_data, HEIGHT * infos->size_line);
    mlx_clear_window(infos->mlx, infos->win);
    draw_fractal(infos);
    mlx_put_image_to_window(infos->mlx, infos->win, infos->ptr_img, 0, 0);
    return (0);
}

int		pointerMotion(int x, int y, t_infos *infos)
{
    infos->mouse_x = x;
    infos->mouse_y = y;
    expose_hook(infos);
    return (0);
}


double   map(int x, double in_min, double in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int     mouse_hook(int button, int x, int y, t_infos *infos)
{
    double  x1;
    double  y1;

    x1 = map(x, 0, WIDTH, infos->min_re, infos->max_re);
    y1 = map(y, 0, HEIGHT, infos->min_im, infos->max_im);
    if (button == 4)
    {
        infos->h /= 0.1;
        infos->min_re = x1 - infos->h;
        infos->max_re = x1 + infos->h;
        infos->min_im = y1 - infos->h;
        infos->max_im = y1 + infos->h;
        infos->max_iter /= 1.5;
    }
    if (button == 5)
    {
        infos->h *= 0.1;

        infos->min_re = x1 - infos->h;
        infos->max_re = x1 + infos->h;
        infos->min_im = y1 - infos->h;
        infos->max_im = y1 + infos->h;
        infos->max_iter *= 1.5;
    }
    expose_hook(infos);
    return (0);
}

int     key_hook(int keycode, t_infos *infos)
{
    if (keycode == 53)
    {
        mlx_destroy_image(infos->mlx, infos->ptr_img);
        free(infos);
        exit (0);
    }
    if (keycode == ZOOM_OUT)
    {
        if (infos->zoom > 1)
        {
            infos->zoom -= 0.5;
            infos->max_iter -= 1;
        }
        expose_hook(infos);
    }
    if (keycode == ZOOM_IN)
    {
        infos->zoom += 0.5;
        infos->max_iter += 1;
        expose_hook(infos);
    }
    if (keycode == MOVE_LEFT) /*LEFT*/
    {
        infos->x_offset -= 12;
        expose_hook(infos);
    }
    if (keycode == MOVE_RIGHT) /*RIGHT*/
    {
        infos->x_offset += 12;
        expose_hook(infos);
    }
    return (keycode);
}

void	mlx_draw(t_infos *infos)
{
    infos->win = mlx_new_window(infos->mlx, WIDTH, HEIGHT, infos->fractal_name);
    mlx_put_image_to_window(infos->mlx, infos->win, infos->ptr_img, 0, 0);
    mlx_key_hook(infos->win, key_hook, infos);
    mlx_mouse_hook(infos->win, mouse_hook, infos);
    mlx_expose_hook(infos->win, expose_hook, infos);
    mlx_hook(infos->win, MOTION_NOTIFY, PTR_MOTION_MASK, pointerMotion, infos);
    mlx_loop(infos->mlx);
}
