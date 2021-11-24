/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:33:34 by evlad             #+#    #+#             */
/*   Updated: 2016/11/30 15:27:56 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_connexion(char *str, int i)
{
	int		index_connexion;

	index_connexion = 0;
	if (i - 5 >= 0 && str[i - 5] == '#')
		index_connexion++;
	if (i - 1 >= 0 && str[i - 1] == '#')
		index_connexion++;
	if (i + 1 <= 20 && str[i + 1] == '#')
		index_connexion++;
	if (i + 5 <= 20 && str[i + 5] == '#')
		index_connexion++;
	return (index_connexion);
}

static int		ft_checktetri(char *str)
{
	int		i;
	int		index_diese;
	int		index_connexion;

	i = 0;
	index_diese = 0;
	index_connexion = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			index_diese++;
			index_connexion += ft_connexion(str, i);
		}
		if ((i == 0 || (i + 1) % 5 != 0) && str[i] != '.' && str[i] != '#')
			break ;
		if (i != 0 && (i + 1) % 5 == 0 && str[i] != '\n')
			break ;
		i++;
	}
	if (i != 20 || index_diese != 4 || index_connexion < 6)
		return (-1);
	return (0);
}

int				ft_checkfile(char *str)
{
	size_t	i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (str == NULL || str[0] == '\0')
		return (-1);
	while (str[i] && i < ft_strlen(str))
	{
		tmp = ft_strsub(str, i, 20);
		if (ft_checktetri(tmp) == -1)
		{
			ft_strdel(&tmp);
			return (-1);
		}
		ft_strdel(&tmp);
		i += 21;
		j++;
	}
	if (j > 26)
		return (-1);
	if (str[i - 1] == '\n')
		return (-1);
	return (j);
}
