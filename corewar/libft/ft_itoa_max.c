/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:20:35 by fpipart           #+#    #+#             */
/*   Updated: 2016/12/31 13:07:48 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static uintmax_t	ft_pow_max(uintmax_t x, int y)
{
	uintmax_t a;

	a = 1;
	if (y == 0)
		return (1);
	if (y == 1)
		return (x);
	while (y--)
		a = a * x;
	return (a);
}

static char			*fill(uintmax_t n, int len, int sgn)
{
	char	*nbr;
	int		i;

	nbr = (char*)malloc(sizeof(char) * (len + sgn + 1));
	if (!nbr)
		return (NULL);
	i = len;
	if (sgn == 1)
		nbr[0] = '-';
	nbr[len + sgn] = '\0';
	while (i--)
		nbr[len - (i + 1) + sgn] = ((n / ft_pow_max(10, i)) % 10) + '0';
	return (nbr);
}

char				*ft_itoa_max(intmax_t n)
{
	int			i;
	uintmax_t	n2;
	int			sgn;

	i = 0;
	sgn = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n >= 0)
		n2 = n;
	if (n < 0)
	{
		sgn = 1;
		n2 = -n;
	}
	while (i <= 19 && n2 >= ft_pow_max(10, i) && n != 0)
		i++;
	return (fill(n2, i, sgn));
}
