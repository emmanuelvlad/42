/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:25:00 by evlad             #+#    #+#             */
/*   Updated: 2017/04/11 18:18:44 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putwchar_2(wchar_t w)
{
	char	*str;

	if (w <= 0xFFFF)
	{
		str = ft_strnew(4);
		str[0] = (w >> 12) + 0xE0;
		str[1] = ((w >> 6) & 0x3F) + 0x80;
		str[2] = (w & 0x3F) + 0x80;
		str[3] = '\0';
	}
	else
	{
		str = ft_strnew(5);
		str[0] = (w >> 18) + 0xF0;
		str[1] = ((w >> 12) & 0x3F) + 0x80;
		str[2] = ((w >> 6) & 0x3F) + 0x80;
		str[3] = (w & 0x3F) + 0x80;
		str[4] = '\0';
	}
	return (str);
}

char	*ft_putwchar(wchar_t w)
{
	char	*str;

	if (w <= 0x7F)
	{
		str = ft_strnew(2);
		str[0] = w;
		str[1] = '\0';
	}
	else if (w <= 0x7FF)
	{
		str = ft_strnew(3);
		str[0] = (w >> 6) + 0xC0;
		str[1] = (w & 0x3F) + 0x80;
		str[2] = '\0';
	}
	else
		str = ft_putwchar_2(w);
	return (str);
}
