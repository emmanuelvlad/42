/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_with_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 14:45:19 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/19 17:04:27 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_quote(char *tab, int start)
{
	int		i;

	i = start;
	while ((tab[i]) && (tab[i] == ' ' || tab[i] == '\t' || tab[i] == '\v' || tab[i] == '\n'))
		i++;
	if (tab[i] != '"')
		return (0);
	else
	{
		if (tab[++i] == '"')
			return (0);
		while (tab[i] != '"')
		{
			if (!tab[i])
				return (0);
			i++;
		}
		i++;
	}
	while ((tab[i]) && (tab[i] == ' ' || tab[i] == '\t' || tab[i] == '\v' || tab[i] == '\n'))
		i++;
	if (tab[i] != '\0')
		return (0);
	return (1);
}

int			idx_start(char *tab, char *str)
{
	int		idx;

	idx = 0;
	while (tab[idx] == str[idx])
		idx++;
	while (tab[idx] == ' ' || tab[idx] == '\t' || tab[idx] == '\v')
		idx++;
	return (idx + 1);
}
