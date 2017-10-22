#include "fractol.h"

void    zoom_in(int mouse_x, int mouse_y, t_infos *infos)
{
    double  ecart;

    infos->zoom_scale *= 1.1;
    ecart = (infos->max_im - infos->min_im) - (HEIGHT / infos->zoom_scale);
    infos->min_re += (((double)mouse_x) / HEIGHT) * ecart;
    infos->max_re -= ((HEIGHT - ((double)mouse_x)) / HEIGHT) * ecart;
    infos->min_im += (((double)mouse_y) / HEIGHT) * ecart;
    infos->max_im -= ((WIDTH - ((double)mouse_y)) / WIDTH) * ecart;
}

void    zoom_out(int mouse_x, int mouse_y, t_infos *infos)
{
    double  ecart;

    infos->zoom_scale /= 1.1;
    ecart = (HEIGHT / infos->zoom_scale) + (-infos->max_re + infos->min_re);
    infos->min_re -= (((double)mouse_x) / HEIGHT) * ecart;
    infos->max_re += ((HEIGHT - ((double)mouse_x)) / HEIGHT) * ecart;
    infos->min_im -= (((double)mouse_y) / WIDTH) * ecart;
    infos->max_im += ((WIDTH - ((double)mouse_y)) / WIDTH) * ecart;
}