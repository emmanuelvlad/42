/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overlap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 09:36:00 by fpipart           #+#    #+#             */
/*   Updated: 2016/12/03 10:08:13 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_overlap(t_coord crd, char **result, char **tetri, int i)
{
	int x;
	int y;
	int	x2;
	int y2;

	x = 0;
	x2 = crd.pos[i] / crd.sqr_size;
	y2 = crd.pos[i] % crd.sqr_size;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if ((x2 + x >= crd.sqr_size || y2 + y >= crd.sqr_size)
			&& tetri[x][y] == '#')
				return (0);
			if (tetri[x][y] == '#')
				if (result[x2 + x][y2 + y] > 64 && result[x2 + x][y2 + y] < 91)
					return (0);
			y++;
		}
		x++;
	}
	return (1);
}
