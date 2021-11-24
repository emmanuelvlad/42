/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:28:35 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/11 16:11:20 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		d_len;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (*d != '\0' && size != 0)
	{
		d++;
		size--;
	}
	d_len = d - dst;
	if (size == 0)
		return (d_len + ft_strlen(src));
	while (*s != '\0')
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = '\0';
	return (d_len + (s - src));
}
