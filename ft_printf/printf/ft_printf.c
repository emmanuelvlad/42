/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 08:33:26 by evlad             #+#    #+#             */
/*   Updated: 2017/04/11 14:59:37 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *restrict format, ...)
{
	int			i;
	t_length	*len;
	va_list		args;

	i = 0;
	len = init_length();
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			i += formating(format + i, args, len);
		else
		{
			write(1, &(format[i]), 1);
			len->len++;
			i++;
		}
	}
	free(len);
	va_end(args);
	return (len->len);
}
