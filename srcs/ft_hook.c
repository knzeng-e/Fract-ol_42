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


int		expose_hook(t_infos *infos)
{
    char    *display = "ZOOM : ";

    ft_bzero(infos->img_data, HEIGHT * infos->size_line);
    mlx_clear_window(infos->mlx, infos->win);
    run_functions(infos, infos->current_fract);
    mlx_put_image_to_window(infos->mlx, infos->win, infos->ptr_img, 0, 0);
    mlx_string_put(infos->mlx, infos->win, 4, 2, 0x00FFFF00, ft_strjoin(display, ft_itoa((infos->zoom_scale))));
    return (0);
}

int     mouse_hook(int button, int x, int y, t_infos *infos)
{
    x += infos->x_offset;
    y += infos->y_offset;
    infos->x = x;
    infos->y = y;
    run_functions(infos, button);
    expose_hook(infos);
    return (0);
}

int     key_hook(int keycode, t_infos *infos)
{
	printf("\n\nKey_pressed ==> %d", keycode);
    run_functions(infos, keycode);
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
