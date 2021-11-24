/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:29:10 by evlad             #+#    #+#             */
/*   Updated: 2016/11/14 13:54:14 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		count(long int n)
{
	int		len;

	len = 0;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

char			*ft_itoa(int lol)
{
	char		*retour;
	int			len;
	int			sign;
	long	int	n;

	n = lol;
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n < 0)
		n *= -1;
	len = count(n) + sign;
	if (!(retour = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	retour[len] = '\0';
	if (n == 0)
		retour[0] = '0';
	while (n != 0)
	{
		retour[len-- - 1] = (char)(n % 10) + 48;
		n /= 10;
	}
	if (sign == 1)
		retour[len - 1] = '-';
	return (retour);
}
