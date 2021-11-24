/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:06:38 by evlad             #+#    #+#             */
/*   Updated: 2016/12/03 10:06:39 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_clean(char ***tetris, char **result, t_coord *crd)
{
	int i;
	int j;

	i = 0;
	while (i < crd->sqr_size)
		ft_strdel(result + i++);
	free(result);
	i = 0;
	j = 0;
	while (i < crd->total_tetri)
	{
		j = 0;
		while (j < 4)
		{
			ft_strdel(tetris[i] + j);
			j++;
		}
		free(tetris[i]);
		i++;
	}
	free(tetris);
	free(crd->pos);
	free(crd->open);
	free(crd);
}
