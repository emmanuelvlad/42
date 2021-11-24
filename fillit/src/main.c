/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:58:41 by evlad             #+#    #+#             */
/*   Updated: 2016/12/03 10:28:50 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	char	***tetris;
	char	**result;
	int		i;
	t_coord	*crd;

	i = 0;
	crd = ft_init(av[1]);
	if (ft_errors(ac, crd) == -1)
		return (-1);
	result = NULL;
	tetris = ft_stock(crd->open, crd->total_tetri);
	result = ft_init_tab(*crd);
	result = ft_backtrack(tetris, result, crd, 0);
	while (i++ < crd->sqr_size)
	{
		if (COLOR)
			ft_colorit(result[i - 1]);
		else
			ft_putstr(result[i - 1]);
		ft_putchar('\n');
	}
	ft_clean(tetris, result, crd);
	return (0);
}
