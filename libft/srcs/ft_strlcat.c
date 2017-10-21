/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:50:13 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/26 11:49:49 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	int		i;

	size_dest = (size_t)ft_strlen(dest);
	size_src = (size_t)ft_strlen(src);
	if (size_dest > size)
		return (size + size_src);
	i = 0;
	while ((src[i] != '\0') && (i + size_dest < size - 1))
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_dest + size_src);
}
