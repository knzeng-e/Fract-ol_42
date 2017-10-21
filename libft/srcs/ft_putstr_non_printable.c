/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 11:26:53 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/26 11:59:46 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_hexa(char non_printable)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if ((unsigned int)non_printable > 16)
	{
		ft_print_hexa(non_printable / 10);
		ft_print_hexa(non_printable % 10);
	}
	else
		ft_putchar(hexa[(unsigned int)non_printable]);
}

void		ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if ((*str < 32 && *str >= 0) || *str == 127)
		{
			ft_putchar('\\');
			if ((unsigned int)(*str) < 16)
				ft_putchar('0');
			ft_print_hexa(*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
