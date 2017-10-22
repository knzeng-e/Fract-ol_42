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
    mlx_string_put(infos->mlx, infos->win, 4, 2, 0x00FFFF00, ft_itoa((infos->zoom_scale)));
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
    x += infos->x_offset;
    y += infos->y_offset;
    if (button == LEFT)
        infos->x_offset -= 12;
    if (button == RIGHT)
        infos->x_offset += 12;
    if (button == 5)
        zoom_in(x, y, infos);
    if (button == 4)
        zoom_out(x, y, infos);
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
    if (keycode == MOVE_LEFT || keycode == LEFT) /*LEFT*/
    {
        infos->x_offset -= 12;
        expose_hook(infos);
    }
    if (keycode == MOVE_RIGHT) /*RIGHT*/
    {
        infos->x_offset += 12;
        expose_hook(infos);
    }
    if (keycode == MOVE_UP) /*RIGHT*/
    {
        infos->y_offset -= 12;
        expose_hook(infos);
    }
    if (keycode == MOVE_DOWN) /*RIGHT*/
    {
        infos->y_offset += 12;
        expose_hook(infos);
    }
    return (keycode);
}

void	mlx_draw(t_infos *infos)
{
        printf("\n\t\t*\t[%f , %f] x [%f, %f]", infos->min_re, infos->max_re, infos->min_im, infos->max_im);
    infos->win = mlx_new_window(infos->mlx, WIDTH, HEIGHT, infos->fractal_name);
    mlx_put_image_to_window(infos->mlx, infos->win, infos->ptr_img, 0, 0);
    mlx_key_hook(infos->win, key_hook, infos);
    mlx_mouse_hook(infos->win, mouse_hook, infos);
    mlx_expose_hook(infos->win, expose_hook, infos);
    mlx_hook(infos->win, MOTION_NOTIFY, PTR_MOTION_MASK, pointerMotion, infos);
    mlx_loop(infos->mlx);
}
