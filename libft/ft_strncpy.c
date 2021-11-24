/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:50:52 by evlad             #+#    #+#             */
/*   Updated: 2016/11/09 18:04:52 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*cdest;

	cdest = dest;
	while (len > 0 && *src != '\0')
	{
		*cdest++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*cdest++ = '\0';
		len--;
	}
	return (dest);
}
