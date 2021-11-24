/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:14:34 by evlad             #+#    #+#             */
/*   Updated: 2017/04/12 14:56:39 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		formating(const char *restrict format, va_list args, t_length *len)
{
	t_flag	*active;
	int		i;

	active = init_flag();
	i = 1;
	if (format[i] == '\0')
		return (i);
	while (ft_strchr(" .0123456789+-#lhjz", format[i]) && format[i])
		i += 1 + check_flags(format + i, active);
	if (ft_strchr("bdiouxXDOUCcsSp%ZR", format[i]) && format[i])
	{
		conv(format[i], active, args, len);
		i++;
	}
	else if (!ft_strchr("bdiouxXDOUCcsSp", format[i]))
	{
		write(1, &format[i], 1);
		len->len++;
		i++;
	}
	free(active);
	return (i);
}
