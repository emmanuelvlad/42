/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:21:47 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/11 16:57:12 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*fill(unsigned int n, int len, int sgn)
{
	char	*nbr;
	int		i;

	nbr = (char*)malloc(sizeof(char) * (len + sgn + 1));
	if (!nbr)
		return (NULL);
	i = len;
	if (n == 0)
	{
		nbr[0] = '0';
		nbr[1] = '\0';
		return (nbr);
	}
	if (sgn == 1)
		nbr[0] = '-';
	nbr[len + sgn] = '\0';
	while (i--)
		nbr[len - (i + 1) + sgn] = (ft_abs((n / ft_pow(10, i)) % 10) + '0');
	return (nbr);
}

char		*ft_itoa(int n)
{
	int				i;
	unsigned int	n2;
	int				sgn;

	i = 0;
	sgn = 0;
	if (n >= 0)
	{
		n2 = n;
		if (n == 0)
			i = 1;
	}
	if (n < 0)
	{
		sgn = 1;
		n2 = -n;
	}
	while (n2 / ft_pow(10, i) && n != 0)
		i++;
	if (i > 10)
		i = 10;
	return (fill(n2, i, sgn));
}
