/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:28:29 by evlad             #+#    #+#             */
/*   Updated: 2021/12/03 18:31:19 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	**process(char **tab, char *s, char c, int i)
{
	int		j;
	int		k;

	j = 0;
	while (j < ft_countsword(s, c))
	{
		if (s[i] != c)
		{
			tab[j++] = (char *)malloc(sizeof(char)
					* (ft_countsletter(s + i, c) + 1));
			if (!tab[j - 1])
				return (NULL);
			k = 0;
			while (s[i])
			{
				if (s[i] == c)
					break ;
				tab[j - 1][k++] = s[i++];
			}
			tab[j - 1][k] = '\0';
		}
		else
			i++;
	}
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ft_countsword(s, c));
	if (!tab)
		return (NULL);
	return (process(tab, (char *)s, c, i));
}
