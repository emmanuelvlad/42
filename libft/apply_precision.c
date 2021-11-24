/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:13:17 by evlad             #+#    #+#             */
/*   Updated: 2017/04/21 12:27:43 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_precision_p(char *buffer, t_flag *active)
{
	char	*str;
	int		i;
	int		j;

	str = ft_strnew(active->precision + 2);
	i = 0;
	j = 2;
	if (ft_strlen(buffer) == 3)
	{
		while (i < active->precision + 2)
			str[i++] = '0';
	}
	else
	{
		while (i < (active->precision + 4) - (int)ft_strlen(buffer))
			str[i++] = '0';
		while (str[j])
			str[i++] = buffer[j++];
	}
	str[1] = 'x';
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_precision_negative(char *buffer, int length, t_flag *active)
{
	char	*str;
	int		i;

	str = ft_strnew(active->precision + 2);
	i = 0;
	while (i < (active->precision - length + 2))
		str[i++] = '0';
	str[0] = '-';
	ft_strcpy(str + i, buffer + 1);
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_precision_3(char *buffer, t_flag *active)
{
	if (!active->width && active->precision == 0)
	{
		freemalloc(buffer, active, 0);
		return ("");
	}
	else
		return (strsubwchar(buffer, 0, active));
}

char	*apply_precision_2(char *buffer, int length, t_flag *active)
{
	char	*str;
	int		i;

	if (active->type == 'b')
		return (buffer);
	if (active->type == 'o' && active->precision == 0)
		return (buffer);
	if (ft_atoi(buffer) < 0)
		return (apply_precision_negative(buffer, length, active));
	str = ft_strnew(active->precision + 1);
	i = 0;
	while ((i < (active->precision - length)) && active->type != 's')
		str[i++] = '0';
	ft_strcpy(str + i, buffer);
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_precision(char *buffer, int length, t_flag *active)
{
	if (active->precision == 0 && active->type == 'p')
		return (buffer);
	else if (active->precision >= (int)ft_strlen(buffer) && active->type == 'p')
		return (apply_precision_p(buffer, active));
	else if (length >= active->precision && active->type == 's')
	{
		active->second_malloc = 1;
		return (ft_strsub(buffer, 0, active->precision));
	}
	else if (length >= active->precision && active->type == 'S')
		return (apply_precision_3(buffer, active));
	else if (ft_atoi(buffer) == 0 && active->precision == 0)
	{
		freemalloc(buffer, active, 0);
		return ("\0");
	}
	else if (length >= active->precision || active->type == '%' ||
			(active->plus && active->minus && active->precision == 0))
		return (buffer);
	else if (length < active->precision && ft_strchr("cC", active->type))
		return (buffer);
	else
		return (apply_precision_2(buffer, length, active));
}
