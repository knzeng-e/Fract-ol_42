/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:08:21 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/09/25 16:39:28 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_infos *infos)
{
    infos->max_iter = 100;
    infos->x = 0.0;
    infos->y = 0.0;
    infos->x_deb = 0;
    infos->y_deb = 0;
    infos->max_re = 2;
    infos->min_re = -2;
    infos->max_im = 2;
    infos->min_im = -2;
    infos->h = 0.1;
    infos->zoom = 1;
    infos->x_zoom = WIDTH / (infos->max_re - infos->min_re);
    infos->y_zoom = HEIGHT / (infos->max_im - infos->min_im);
    infos->x_offset = 0;
    infos->y_offset = 0;
    infos->mlx = mlx_init();
    ft_putendl(infos->fractal_name);
    infos->ptr_img = mlx_new_image(infos->mlx, WIDTH, HEIGHT);
    infos->img_data = (int *)mlx_get_data_addr(infos->ptr_img, &(infos->bpp), \
            &(infos->size_line), &(infos->endian));
}

int     check_args(char *av)
{
    if ((ft_strcmp(av, "Mandelbrot") != 0) && (ft_strcmp(av, "Julia") != 0))
        return (ERREUR_ARGS);
    return (ARGS_OK);
}

void    print_usage(void)
{
    ft_putendl("Usage: ./fractol fractol_name");
}

int		main(int ac, char ** av)
{
    t_infos	*infos;

    if (ac == 2)
    {
        if (check_args(av[1]) == ERREUR_ARGS)
        {
            ft_putendl("Fractale inexistante ou non definie..");
            return (ERREUR_ARGS);
        }
        if ((infos = (t_infos *)malloc(sizeof(t_infos))) == NULL)
            return (ERROR_MALLOC);
        infos->fractal_name = av[1];
        ft_init(infos);
        mlx_draw(infos);
        free(infos);
    }
    else
        print_usage();
    return (0);
}
