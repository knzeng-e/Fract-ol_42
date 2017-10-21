/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 04:41:27 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/26 11:29:56 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(char *base)
{
	int	i;
	int	current;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		current = i + 1;
		while ((base[current] != base[i]) && (base[current] != '\0'))
			current++;
		if (base[current] == base[i])
			return (0);
		i++;
	}
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	unsigned int n;

	if (ft_check_base(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		n = (unsigned int)nbr;
		if (n == 2147483648)
			ft_putstr("2147483648");
		else
		{
			if (n >= (unsigned int)ft_strlen(base))
			{
				ft_putnbr_base(n / (unsigned int)ft_strlen(base), base);
				ft_putnbr_base(n % (unsigned int)ft_strlen(base), base);
			}
			else
				ft_putchar(base[n]);
		}
	}
}
