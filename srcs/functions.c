/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:04:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/10/26 18:47:24 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_left(t_infos *infos)
{
	infos->x_offset -= 12;
	expose_hook(infos);
}

void	move_right(t_infos *infos)
{
	infos->x_offset += 12;
	expose_hook(infos);
}

void	move_up(t_infos *infos)
{
	infos->y_offset -= 12;
	expose_hook(infos);
}

void	move_down(t_infos *infos)
{
	infos->y_offset += 12;
	expose_hook(infos);
}

void	mouse_left(t_infos *infos)
{
	infos->x_offset -= 12;
	expose_hook(infos);
}
