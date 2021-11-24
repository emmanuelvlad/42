/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:36:06 by evlad             #+#    #+#             */
/*   Updated: 2016/11/30 14:16:08 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_open(char *av)
{
	int		fd;
	int		ret;
	char	buffer[2];
	char	*str;
	char	*tmp;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	if (!(str = ft_strnew(1)))
		return (0);
	while ((ret = read(fd, buffer, 1)))
	{
		buffer[1] = '\0';
		if (str[0] == '\0')
			str[0] = buffer[0];
		else
		{
			tmp = str;
			str = ft_strjoin(tmp, buffer);
			free(tmp);
		}
	}
	return (str);
}
