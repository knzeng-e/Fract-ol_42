#include "fractol.h"

void    draw_burningship(t_infos *infos)
{
    double  calc;
    int     color;

    infos->c.real = (infos->col + infos->x_offset) \
                    / (WIDTH / (infos->max_re - infos->min_re)) + infos->min_re;
    infos->c.imaginary = (infos->row + infos->y_offset) / (HEIGHT / \
            (infos->max_im - infos->min_im)) + infos->min_im;
    infos->x = 0;
    infos->y = 0;
    infos->iter = 0;
    calc = (fabs(infos->x) * fabs(infos->x) + fabs(infos->y) * fabs(infos->y));
    while (calc <= 4 && (infos->iter < infos->max_iter))
    {
        infos->x_tmp = fabs(infos->x) * fabs(infos->x) - fabs(infos->y) * \
                       fabs(infos->y) + infos->c.real;
        infos->y = 2 * fabs(infos->x) * fabs(infos->y) + infos->c.imaginary;
        infos->x = infos->x_tmp;
        infos->iter++;
        calc = (fabs(infos->x) * fabs(infos->x) + fabs(infos->y) * fabs(infos->y));
    }
    color = mlx_get_color_value(infos->mlx, 0x000004FF << (infos->iter & 255));
    if (infos->iter < infos->max_iter)
        infos->img_data[infos->row * WIDTH + infos->col] = color;
}

void    burning_fun(t_infos *infos)
{
    infos->current_fract = BURNING_KEY;
    infos->row = 0;
    while (infos->row < HEIGHT)
    {
        infos->col = 0;
        while (infos->col < WIDTH)
        {
            draw_burningship(infos);
            infos->col++;
        }
        infos->row++;
    }
}
