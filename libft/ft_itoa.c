/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:29:10 by evlad             #+#    #+#             */
/*   Updated: 2021/12/03 19:21:32 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	count(long int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int number)
{
	char		*retour;
	int			len;

	len = count(number);
	retour = (char *)malloc(sizeof(char) * (len + 1));
	if (!retour)
		return (NULL);
	retour[len] = '\0';
	if (number == 0)
		retour[0] = '0';
	else if (number < 0)
	{
		retour[0] = '-';
		number *= -1;
	}
	while (number != 0)
	{
		retour[len-- - 1] = (char)(number % 10) + 48;
		number /= 10;
	}
	return (retour);
}
