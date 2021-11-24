/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubwchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:07:22 by evlad             #+#    #+#             */
/*   Updated: 2017/04/11 17:04:38 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	wwstrlen(wchar_t *str, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (ret < len && str[j])
	{
		if (str[j] <= 0x7F)
			i = 1;
		else if (str[j] <= 0x7FF)
			i = 2;
		else if (str[j] <= 0xFFFF)
			i = 3;
		else if (str[j] <= 0x10FFFF)
			i = 4;
		ret += i;
		j++;
		if (ret == len)
			return (ret);
	}
	return (len - (4 - i));
}

char	*strsubwchar(char *s, int start, t_flag *active)
{
	size_t	wlen;

	(void)start;
	if (!(s))
		return (NULL);
	if (active->precision > 0)
		wlen = wwstrlen(active->buff, active->precision);
	else
		wlen = wwstrlen(active->buff, active->precision);
	s[wlen] = '\0';
	return (s);
}
