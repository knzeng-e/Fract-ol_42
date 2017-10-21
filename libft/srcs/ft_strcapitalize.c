/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 12:26:01 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/26 12:31:38 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_alpha(char c)
{
	return (ft_is_low(c) || ft_is_upper(c) || (c > '0' && c < '9'));
}

static int	ft_is_space(char c)
{
	return (!(ft_is_alpha(c)));
}

char		*ft_strcapitalize(char *str)
{
	int i;

	((ft_is_low(str[0])) ? str[0] -= 32 : str[0]);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_is_alpha(str[i]))
		{
			if (ft_is_low(str[i]) && (ft_is_space(str[i - 1])))
				str[i] -= ('a' - 'A');
			else
			{
				if (ft_is_upper(str[i]) && !(ft_is_space(str[i - 1])))
					str[i] += ('a' - 'A');
			}
		}
		i++;
	}
	return (str);
}
