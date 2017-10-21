/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 21:43:37 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/26 21:47:19 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_word(char const *str, int index, char c, char **out)
{
	int	i;
	int	cpt;
	int	deb;

	i = 0;
	cpt = 0;
	while (cpt != index)
	{
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
		cpt = cpt + 1;
	}
	while (str[i] && str[i] == c)
		i++;
	deb = i;
	cpt = 0;
	while (str[i] && str[i] != c)
		i++;
	out[index] = (char *)malloc(sizeof(char) * (i - deb) + 1);
	while (deb < i)
		out[index][cpt++] = str[deb++];
	out[index][cpt] = '\0';
}
