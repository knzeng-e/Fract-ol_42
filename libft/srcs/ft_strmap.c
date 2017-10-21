/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 06:16:18 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/28 17:51:23 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*out;
	int		i;

	if (s && f)
	{
		i = 0;
		out = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (out)
		{
			while (s[i])
			{
				out[i] = f(s[i]);
				i++;
			}
			out[i] = '\0';
		}
		return (out);
	}
	return (NULL);
}
