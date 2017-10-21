/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 12:12:13 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/26 15:19:00 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_count_words(const char *s, char c)
{
	int		j;
	int		cpt;
	char	*str;

	str = (char *)s;
	cpt = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == c)
		{
			while (str[j] == c)
				j++;
		}
		else
		{
			cpt++;
			while (str[j] && str[j] != c)
				j++;
		}
	}
	return (cpt);
}
