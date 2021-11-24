/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 08:56:04 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/24 19:41:03 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static char	**free_tab(char **tab)
{
	int w;

	w = 0;
	while (tab[w])
	{
		ft_strdel((tab + w));
		w++;
	}
	free(tab);
	return (NULL);
}

static char	**split(char **tab, char c, char const *s, int w_m)
{
	int w;
	int i;
	int counter;

	w = 0;
	i = 0;
	while (w < w_m)
	{
		counter = 1;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (counter == 1)
			{
				counter = 0;
				tab[w] = ft_strsub(s, i, ft_wordlen((s + i), c));
				if (tab[w] == NULL)
					return (free_tab(tab));
			}
			i++;
		}
		w++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word_max;

	if (s)
	{
		word_max = ft_wordcount(s, c);
		tab = (char**)malloc(sizeof(char*) * word_max + 1);
		if (tab)
		{
			tab = split(tab, c, s, word_max);
			tab[word_max] = NULL;
		}
		return (tab);
	}
	return (NULL);
}
