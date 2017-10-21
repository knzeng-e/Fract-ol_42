/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:21:57 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/31 17:07:57 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*output;
	int		i;
	int		start;
	int		cpt;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (!(s[i]))
		return (ft_strdup(""));
	start = i;
	while (s[i])
		i++;
	while (ft_isspace(s[i - 1]))
		i--;
	if ((output = (char *)malloc(sizeof(char) * (i - start) + 1)))
	{
		cpt = 0;
		while (start < i)
			output[cpt++] = s[start++];
		output[cpt] = '\0';
	}
	return (output);
}
