/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 02:39:23 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/28 18:54:31 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!(dest > src && src + n > dest))
		ft_memcpy(dest, src, n);
	else
		while (n--)
			*((char *)dest + n) = *((char *)src + n);
	return (dest);
}
