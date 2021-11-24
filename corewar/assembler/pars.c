/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:31:27 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/20 14:19:55 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		empty_file(t_main **main, char **tab)
{
	int		i;

	ft_putstr("\x1b[31mError: empty file\x1b[0m\n");
	if (*main)
		free(*main);
	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	return (0);
}

char	*get_lines(char *argv)
{
	int		fd;
	char	*str;
	int		ret;
	char	buffer[2];
	char	*tmp;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if (!(str = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buffer, 1)))
	{
		buffer[1] = '\0';
		tmp = str;
		str = ft_strjoin(str, buffer);
		ft_strdel(&tmp);
	}
	if (close(fd) == -1)
		return (NULL);
	return (str);
}
