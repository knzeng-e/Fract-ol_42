/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:40:18 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/29 15:57:28 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	j = 0;
	while (dest[j])
		j++;
	i = -1;
	while (src[++i])
	{
		dest[j++] = src[i];
	}
	dest[j] = '\0';
	return (dest);
}
