/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 04:53:20 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/21 05:01:59 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = -1;
	while (s[++i])
	{
		if (s[i] == (unsigned char)c)
			return (str + i);
	}
	if (s[i] == (unsigned char)c)
		return (str + i);
	return (NULL);
}
