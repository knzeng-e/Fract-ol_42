/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 23:46:14 by knzeng-e          #+#    #+#             */
/*   Updated: 2017/09/15 10:01:27 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new_line(char **tab, char **line)
{
	char	*i;

	if ((i = ft_memchr(*tab, '\n', ft_strlen(*tab))) != NULL)
	{
		*i = '\0';
		*line = ft_strdup(*tab);
		*tab += ft_strlen(*line) + 1;
		return (1);
	}
	return (0);
}

int	get_next_line(int const fd, char **line)
{
	static char	*save = "";
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || (line == NULL) || (line && (*line = NULL)))
		return (-1);
	ret = -1;
	*line = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) || *save)
	{
		if (ret == -1)
			return (ret);
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
		if (check_new_line(&save, line))
			return (READ_OK);
		if (!ret)
		{
			*line = ft_strdup(save);
			*save = '\0';
			return (READ_OK);
		}
	}
	return (END_OF_READ);
}
