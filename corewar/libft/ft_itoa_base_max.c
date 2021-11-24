/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:39:24 by fpipart           #+#    #+#             */
/*   Updated: 2016/12/31 13:07:03 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	nbr_size(uintmax_t value, int base)
{
	int i;

	i = 0;
	if (value == 0)
		i++;
	while (value != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

static char	*inverse(char *nbr, int size)
{
	int i;
	int tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = nbr[i];
		nbr[i] = nbr[size - 1 - i];
		nbr[size - 1 - i] = tmp;
		i++;
	}
	return (nbr);
}

static char	*ft_i_b(uintmax_t value, int base, char *nbr, char tab[])
{
	int			i;
	uintmax_t	tmp;
	int			size;

	i = 0;
	size = nbr_size(value, base);
	nbr[size] = '\0';
	while (value != 0)
	{
		tmp = value;
		tmp = tmp % base;
		nbr[i] = tab[tmp % base];
		value = value / base;
		i++;
	}
	return (inverse(nbr, size));
}

char		*ft_itoa_base_max(uintmax_t value, int base)
{
	char		*tab;
	char		*nbr;
	int			size;

	tab = "0123456789ABCDEF";
	size = nbr_size(value, base);
	if (value == 0)
		return ((nbr = ft_strdup("0")));
	if (!(nbr = ft_strnew((size + 1))))
		return (NULL);
	return (ft_i_b(value, base, nbr, tab));
}
