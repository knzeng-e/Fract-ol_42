/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 15:57:57 by knzeng-e          #+#    #+#             */
/*   Updated: 2015/10/26 16:37:28 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned	int	cpt;

	cpt = 0;
	while ((cpt < size - 1) && (src[cpt] != '\0'))
	{
		dest[cpt] = src[cpt];
		cpt++;
	}
	dest[cpt] = '\0';
	while (src[cpt] != '\0')
		cpt++;
	return (cpt);
}
