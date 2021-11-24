/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:08:29 by evlad             #+#    #+#             */
/*   Updated: 2016/12/03 10:49:54 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_backtrack(char ***tetris, char **result, t_coord *crd, int i)
{
	while (i < crd->total_tetri)
	{
		if (ft_overlap(*crd, result, tetris[i], i))
		{
			ft_fill(*crd, result, tetris[i], i);
			i++;
		}
		else if (crd->pos[i] < crd->sqr_size * crd->sqr_size)
			crd->pos[i]++;
		else if (crd->pos[i] >= crd->sqr_size * crd->sqr_size && i != 0)
		{
			crd->pos[i--] = 0;
			ft_unfill(*crd, result, tetris[i], i);
			crd->pos[i]++;
		}
		else if (i == 0 && crd->pos[i] >= crd->sqr_size * crd->sqr_size)
		{
			crd->sqr_size += 1;
			free(result);
			result = ft_init_tab(*crd);
			crd->pos[i] = 0;
		}
	}
	return (result);
}
