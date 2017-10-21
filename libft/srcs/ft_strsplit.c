/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:23:13 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/01 03:26:59 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		nb_words;
	int		j;
	char	**output;
	char	*str;

	if (!(s))
		return (NULL);
	str = (char *)s;
	nb_words = ft_count_words(s, c);
	if (!(output = (char **)malloc(sizeof(char *) * nb_words + 1)))
		return (NULL);
	j = 0;
	while (*str && *str == c)
		str++;
	while (j < nb_words)
	{
		ft_get_word(str, j, c, output);
		j++;
	}
	output[j] = 0;
	return (output);
}
