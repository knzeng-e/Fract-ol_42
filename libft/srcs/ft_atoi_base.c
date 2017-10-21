/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 05:28:52 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/26 11:55:24 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_size(char *base)
{
	if (*base == '\0')
		return (0);
	return (1 + ft_get_size(++base));
}

static int		ft_get_sign(char *nbr)
{
	return (-1 + 2 * (nbr[0] != '-'));
}

static int		ft_get_pos(char *base, char digit)
{
	int	pos;

	pos = 0;
	while (*base)
	{
		if (*base++ == digit)
			return (pos);
		pos++;
	}
	if (digit == '+' || digit == '-')
		return (-2);
	return (-1);
}

static int		ft_check_base(char *base)
{
	int	current;

	if (ft_get_size(base) <= 1)
		return (0);
	while (*base)
	{
		current = 1;
		while (base[current] != '\0')
		{
			if (*base == base[current] || (base[current] == '-' \
						|| base[current] == '+'))
				return (0);
			current++;
		}
		base++;
	}
	return (1);
}

int				ft_atoi_base(char *str, char *base)
{
	int	output;
	int	sign;
	int	pos;
	int	last_pos;

	sign = ft_get_sign(str);
	if (!ft_check_base(base))
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	output = 0;
	last_pos = 0;
	while (*str)
	{
		pos = ft_get_pos(base, *str++);
		if (pos == -2)
			return (last_pos);
		if (pos == -1)
			return (0);
		last_pos = pos;
		output = output * (ft_get_size(base)) + (pos);
	}
	return (sign * output);
}
