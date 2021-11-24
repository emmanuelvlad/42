/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:29:13 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/30 15:24:30 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_fill(t_coord crd, char **tab, char **tetri, int i)
{
	int		x2;
	int		y2;
	int		x;
	int		y;

	x2 = 0;
	x = crd.pos[i] / crd.sqr_size;
	y = crd.pos[i] % crd.sqr_size;
	while (x2 < 4)
	{
		y2 = 0;
		while (y2 < 4)
		{
			if (tetri[x2][y2] == '#')
				tab[x + x2][y + y2] = i + 65;
			y2++;
		}
		x2++;
	}
}
