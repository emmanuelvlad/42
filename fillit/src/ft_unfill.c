/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:36:29 by evlad             #+#    #+#             */
/*   Updated: 2016/11/30 15:24:20 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_unfill(t_coord crd, char **tab, char **tetri, int i)
{
	int		x;
	int		y;
	int		x2;
	int		y2;

	x2 = 0;
	y2 = 0;
	x = crd.pos[i] / crd.sqr_size;
	y = crd.pos[i] % crd.sqr_size;
	while (x2 < 4)
	{
		y2 = 0;
		while (y2 < 4)
		{
			if (tetri[x2][y2] == '#')
				tab[x + x2][y + y2] = '.';
			y2++;
		}
		x2++;
	}
}
