/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:52:59 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/31 17:08:22 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*out;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	out = (char *)malloc(sizeof(char) * len + 1);
	if (out)
	{
		i = 0;
		while (len--)
		{
			out[i] = s[start + i];
			i++;
		}
		out[i] = '\0';
	}
	return (out);
}
