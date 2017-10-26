/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:04:51 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/10/26 23:08:39 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double	map_x(t_infos *infos)
{
	double	ecart;
	double	ecart_in;

	infos->in_min = 0;
	infos->in_max = WIDTH;
	infos->out_min = infos->min_re;
	infos->out_max = infos->max_re;
	ecart = infos->out_max - infos->out_min;
	ecart_in = infos->in_max - infos->in_min;
	return (infos->mouse_x - infos->in_min) * ecart / ecart_in + infos->out_min;
}

double	map_y(t_infos *infos)
{
	double	ecart;
	double	ecart_in;

	infos->in_min = 0;
	infos->in_max = HEIGHT;
	infos->out_min = infos->min_im;
	infos->out_max = infos->max_im;
	ecart = infos->out_max - infos->out_min;
	ecart_in = infos->in_max - infos->in_min;
	return (infos->mouse_y - infos->in_min) * ecart / ecart_in + infos->out_min;
}

int		pointer_motion(int x, int y, t_infos *infos)
{
	infos->mouse_x = x;
	infos->mouse_y = y;
	expose_hook(infos);
	return (0);
}

void	ft_init_tab(t_fun t[])
{
	t[0].fun = move_left;
	t[0].key = MOVE_LEFT;
	t[1].fun = move_right;
	t[1].key = MOVE_RIGHT;
	t[2].fun = move_up;
	t[2].key = MOVE_UP;
	t[3].fun = move_down;
	t[3].key = MOVE_DOWN;
	t[4].fun = mouse_right;
	t[4].key = RIGHT;
	t[5].fun = quit;
	t[5].key = ESC;
	t[6].fun = lock_julia;
	t[6].key = SPACE_KEY;
	t[7].fun = ft_zoom_in;
	t[7].key = ZOOM_IN;
	t[8].fun = ft_zoom_out;
	t[8].key = ZOOM_OUT;
	t[9].fun = mandel_fun;
	t[9].key = MANDEL_KEY;
	t[10].fun = julia_fun;
	t[10].key = JULIA_KEY;
	t[11].fun = burning_fun;
	t[11].key = BURNING_KEY;
}

void	run_functions(t_infos *infos, int current_key)
{
	t_fun	tab_functions[NB_FUNC];
	int		index;

	ft_init_tab(tab_functions);
	index = 0;
	while (index < NB_FUNC && tab_functions[index].key != current_key)
		index++;
	if (index < NB_FUNC)
		tab_functions[index].fun(infos);
}
