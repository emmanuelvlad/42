/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:41:00 by evlad             #+#    #+#             */
/*   Updated: 2016/12/15 12:26:27 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		readit(int fd, char **line, t_struct *data)
{
	data->ret = read(fd, data->buffer, BUFF_SIZE);
	if (data->ret == 0 && !ft_strchr(data->tmp, '\n'))
	{
		*line = data->tmp;
		return (0);
	}
	if (data->ret == -1)
		return (-1);
	data->buffer[data->ret] = '\0';
	data->free = data->tmp;
	data->tmp = ft_strjoin(data->tmp, data->buffer);
	free(data->free);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	t_struct	data;
	static char	*str = NULL;

	if (!line)
		return (-1);
	*line = NULL;
	if (str)
	{
		data.tmp = ft_strdup(str);
		ft_strdel(&str);
	}
	else
		data.tmp = ft_strnew(0);
	while (!ft_strchr(data.tmp, '\n'))
	{
		if (readit(fd, line, &data) == 0 || data.ret == -1)
			return ((ft_strlen(data.tmp) > 0) + data.ret);
	}
	str = ft_strdup(ft_strchr(data.tmp, '\n') + 1);
	data.len = ft_strlen(data.tmp) - ft_strlen(str);
	*line = ft_strsub(data.tmp, 0, data.len - 1);
	free(data.tmp);
	return (1);
}
