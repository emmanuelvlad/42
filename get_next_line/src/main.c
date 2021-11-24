/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 08:01:38 by evlad             #+#    #+#             */
/*   Updated: 2016/12/15 11:01:47 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	**line;
	int		i;

	i = 0;
	line = (char**)malloc(sizeof(char*) * 1);
	if (ac < 1)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	while (ft_atoi(av[2]) > i)
	{
		printf("%d: %s\n", get_next_line(fd, line), *line);
		free(*line);
		i++;
	}
	return (0);
}
