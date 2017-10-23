#include "fractol.h"

void    move_left(t_infos *infos)
{
    infos->x_offset -=12;
    expose_hook(infos);
}

void    move_right(t_infos *infos)
{
    infos->x_offset += 12;
    expose_hook(infos);
}
void    move_up(t_infos *infos)
{
    infos->y_offset -= 12;
    expose_hook(infos);
}

void    move_down(t_infos *infos)
{
    infos->y_offset += 12;
    expose_hook(infos);
}

void    mouse_left(t_infos *infos)
{
    infos->x_offset -= 12;
    expose_hook(infos);
}

void    mouse_right(t_infos *infos)
{
    infos->x_offset += 12;
    expose_hook(infos);
}

void    quit(t_infos *infos)
{
    mlx_destroy_image(infos->mlx, infos->ptr_img);
    free(infos);
    exit(0);
}

void    lock_julia(t_infos *infos)
{
    infos->is_lock = !infos->is_lock;
}

void    ft_zoom_in(t_infos *infos)
{
    if ((int)infos->zoom_scale % 10 == 0)
        infos->max_iter += 10;
    zoom_in(infos->x, infos->y, infos);
}

void    ft_zoom_out(t_infos *infos)
{
    zoom_out(infos->x, infos->y, infos);
}
