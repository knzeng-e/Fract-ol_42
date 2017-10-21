/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 04:42:42 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/23 00:47:06 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	int		i;

	out = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = -1;
	if (out == NULL || s1 == NULL)
		return (NULL);
	while (s1[++i])
		out[i] = s1[i];
	out[i] = '\0';
	return (out);
}
