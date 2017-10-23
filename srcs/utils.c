#include "fractol.h"
#include <stdio.h>

double   map(int x, double in_min, double in_max, double out_min, double out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int		pointerMotion(int x, int y, t_infos *infos)
{
    infos->mouse_x = x;
    infos->mouse_y = y;
    expose_hook(infos);
    return (0);
}

void    draw_fractal(t_infos *infos)
{
    t_fractal   fractal_tab[3];
    int         index;

    fractal_tab[0].name = "mandelbrot";
    fractal_tab[0].fractal_fun = mandel_fun;
    //fractal_tab[0].key = MANDEL_KEY;
    fractal_tab[1].name = "julia";
    fractal_tab[1].fractal_fun = julia_fun;
    //fractal_tab[1].key = JULIA_KEY;
    fractal_tab[2].name = "burningship";
    fractal_tab[2].fractal_fun = burning_fun;
    //fractal_tab[2].key = BURNING_KEY;
    index = 0;
    while ((index < NB_FRACTALS) && ft_strcmp(infos->fractal_name, fractal_tab[index].name) != 0)
        index++;
    fractal_tab[index].fractal_fun(infos);
}

void    ft_init_tab(t_fun t[])
{
    t[0].fun = move_left;
    t[0].key = MOVE_LEFT;
    t[1].fun = move_right;
    t[1].key = MOVE_RIGHT;
    t[2].fun = move_up;
    t[2].key = MOVE_UP;
    t[3].fun = move_down;
    t[3].key = MOVE_DOWN;
    t[4].fun = mouse_left;
    t[4].key = LEFT;
    t[5].fun = mouse_right;
    t[5].key = RIGHT;
    t[6].fun = quit;
    t[6].key = ESC;
    t[7].fun = lock_julia;
    t[7].key = SPACE_KEY;
    t[8].fun = ft_zoom_in;
    t[8].key = ZOOM_IN;
    t[9].fun = ft_zoom_out;
    t[9].key = ZOOM_OUT;
    t[10].fun = mandel_fun;
    t[10].key = MANDEL_KEY;
    t[11].fun = julia_fun;
    t[11].key = JULIA_KEY;
    t[12].fun = burning_fun;
    t[12].key = BURNING_KEY;
}

void    run_functions(t_infos *infos, int current_key)
{
    t_fun   tab_functions[NB_FUNC];
    int     index;

    ft_init_tab(tab_functions);
    index = 0;
    while (index < NB_FUNC && tab_functions[index].key != current_key)
        index++;
    if (index < NB_FUNC)
        tab_functions[index].fun(infos);
    printf("\nIndex = %d", index);
}
