/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:58:27 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/24 18:59:45 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		clean(t_gnl *gnl, int j)
{
	char *tmp;

	tmp = gnl->str;
	gnl->str = ft_strsub(gnl->str, gnl->i, ft_strlen(gnl->str + gnl->i));
	ft_strdel(&tmp);
	gnl->i = j - gnl->i;
}

static char		*join_free(char **s1, char *s2, int ret)
{
	char	*tmp;

	s2[ret] = '\0';
	tmp = *s1;
	*s1 = ft_strjoin(*s1, s2);
	free(tmp);
	return (*s1);
}

static int		fillstr(int fd, char **str, int *j, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*s;

	if ((s = ft_strchr(*str + *j, '\n')))
	{
		*line = ft_strsub(*str, *j, s - (*str + *j));
		*j = *j + ft_strlen(*line) + 1;
		return (1);
	}
	if ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (ret);
		*str = join_free(str, buf, ret);
		fillstr(fd, str, j, line);
	}
	if (ret == 0)
	{
		*line = ft_strsub(*str, *j, ft_strlen(*str + *j));
		*j = *j + ft_strlen(*line);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				j;
	static t_gnl	gnl = (t_gnl){.str = NULL, .i = 0};

	if (fd < 0 || !line)
		return (-1);
	if (gnl.str == NULL)
		gnl.str = ft_strnew(1);
	*line = NULL;
	j = gnl.i;
	if (fillstr(fd, &(gnl.str), &j, line) < 0)
		return (-1);
	else if (j > gnl.i)
	{
		clean(&gnl, j);
		return (1);
	}
	return (0);
}
