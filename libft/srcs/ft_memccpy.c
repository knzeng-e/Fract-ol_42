/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:29:38 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/31 19:32:03 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;

	i = -1;
	while (++i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		if (*(char *)(dst + i) == c)
			return (char *)(dst + (i + 1));
	}
	return (NULL);
}
