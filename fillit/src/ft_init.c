/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:38:46 by fpipart           #+#    #+#             */
/*   Updated: 2016/12/03 10:20:08 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_coord	*ft_init(char *str)
{
	t_coord	*crd;

	if (!(crd = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	crd->open = ft_open(str);
	crd->total_tetri = ft_checkfile(crd->open);
	if (crd->total_tetri == -1)
		return (NULL);
	crd->sqr_size = ft_sqrt_mod(crd->total_tetri);
	if (!(crd->pos = (int*)malloc(sizeof(int) * (crd->total_tetri + 1))))
		return (NULL);
	crd->pos = ft_memset(crd->pos, 0,
		sizeof(*crd->pos) * (crd->total_tetri + 1));
	return (crd);
}

char	**ft_init_tab(t_coord crd)
{
	int		x;
	int		y;
	char	**result;

	x = 0;
	if (!(result = (char**)malloc(sizeof(char*) * (crd.sqr_size + 1))))
		return (NULL);
	while (x++ < crd.sqr_size)
		if (!(result[x - 1] = ft_strnew(crd.sqr_size)))
			return (NULL);
	x = 0;
	y = 0;
	while (x++ < crd.sqr_size)
	{
		y = 0;
		while (y++ < crd.sqr_size)
			result[x - 1][y - 1] = '.';
	}
	return (result);
}
