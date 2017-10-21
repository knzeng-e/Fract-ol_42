/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 01:05:00 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/01 05:09:49 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*out;

	i = ft_len(str);
	out = (char *)malloc(sizeof(char) * i);
	if (out)
	{
		j = 0;
		out[i] = '\0';
		while (--i >= 0)
			out[i] = str[j++];
	}
	return (out);
}
