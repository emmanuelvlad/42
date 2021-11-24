/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:01:27 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/30 18:01:32 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*ft_topleft(char *str)
{
	int		i;
	char	*tmp;

	while (str[0] == '.' && str[1] == '.' && str[2] == '.' && str[3] == '.')
	{
		tmp = ft_strsub(str, 5, 15);
		ft_strdel(&str);
		str = ft_strjoin(tmp, "....\n");
		ft_strdel(&tmp);
	}
	while (str[0] == '.' && str[5] == '.' && str[10] == '.' && str[15] == '.')
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '#')
				ft_swap(str + i, str + (i - 1));
			i++;
		}
	}
	return (str);
}

char		***ft_stock(char *str, int total_tetri)
{
	char	***tab;
	char	*tmp;
	char	*tmp2;
	size_t	i;
	int		j;

	if (!(tab = (char***)malloc(sizeof(char**) * (total_tetri))))
		return (NULL);
	i = 0;
	j = 0;
	tmp = NULL;
	while (j < total_tetri)
	{
		tmp = ft_strsub(str, i, 20);
		tmp2 = ft_topleft(tmp);
		tab[j] = ft_strsplit(tmp2, '\n');
		if (ft_strncmp(tmp2, tmp, 4) != 0)
			ft_strdel(&tmp2);
		if (tmp)
			ft_strdel(&tmp);
		j++;
		i += 21;
	}
	i = 0;
	return (tab);
}
