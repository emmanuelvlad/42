/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:28:29 by evlad             #+#    #+#             */
/*   Updated: 2016/11/30 14:29:46 by evlad            ###   ########.fr       */
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
			if (!(tab[j++] = (char*)malloc(sizeof(char) *
							(ft_countsletter(s + i, c) + 1))))
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

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * ft_countsword(s, c))))
		return (NULL);
	return (process(tab, (char*)s, c, i));
}
