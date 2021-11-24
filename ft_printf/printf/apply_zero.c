/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:03:12 by evlad             #+#    #+#             */
/*   Updated: 2017/04/12 15:22:01 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_zero_x(char *buffer, t_flag *active)
{
	int		i;

	i = 2;
	buffer[0] = '0';
	buffer[1] = active->type;
	while (buffer[i] != active->type)
		buffer[i++] = '0';
	buffer[i] = '0';
	return (buffer);
}

char	*apply_zero_p(char *buffer, t_flag *active)
{
	char	*str;
	int		i;

	str = ft_strdup(buffer);
	str[0] = '0';
	str[1] = 'x';
	i = 2;
	while (str[i] != 'x' && str[i])
		str[i++] = '0';
	if (str[i] == 'x')
		str[i] = '0';
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_zero_3(char *buffer)
{
	int		j;

	buffer[0] = '-';
	j = 1;
	while (buffer[j])
	{
		if (buffer[j] == '-' || buffer[j] == ' ')
			buffer[j] = '0';
		j++;
	}
	return (buffer);
}

char	*apply_zero_2(char *buffer, t_flag *active)
{
	int		i;

	i = 0;
	if (active->precision >= 0 && !ft_strchr("cCsS%Z", active->type))
		i = ft_strlen(buffer) - active->precision;
	if (active->space)
		i += 1;
	if ((active->type == 'x' || active->type == 'X') && active->diese)
		return (apply_zero_x(buffer, active));
	else if (active->type == 'p' && check_address(buffer))
		return (apply_zero_p(buffer, active));
	else
	{
		while (buffer[i] == ' ')
		{
			buffer[i] = '0';
			i++;
		}
	}
	return (buffer);
}

char	*apply_zero(char *buffer, t_flag *active)
{
	if (active->type == 'c' && *buffer == '\0')
		active->null = 1;
	if (active->minus)
		return (buffer);
	else if (ft_atoi(buffer) < 0)
		return (apply_zero_3(buffer));
	else
		return (apply_zero_2(buffer, active));
}
