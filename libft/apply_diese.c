/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diese.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:27:44 by evlad             #+#    #+#             */
/*   Updated: 2017/04/21 12:27:31 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_diese_x(char *buffer, t_flag *active)
{
	char	*str;

	str = ft_strnew(ft_strlen(buffer) + 2);
	str[0] = '0';
	str[1] = 'x';
	if (active->type == 'X')
		str[1] = 'X';
	ft_strcpy(str + 2, buffer);
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_diese_2(char *buffer, t_flag *active)
{
	char	*str;
	int		i;

	i = 0;
	if (buffer[0] == '0')
		return (buffer);
	if (buffer[0] == ' ')
	{
		while (buffer[i] == ' ')
			i++;
		buffer[i - 1] = '0';
		return (buffer);
	}
	else
	{
		str = ft_strnew(ft_strlen(buffer) + 1);
		str[0] = '0';
		ft_strcpy(str + 1, buffer);
		freemalloc(buffer, active, 1);
	}
	return (str);
}

char	*apply_diese(char *buffer, t_flag *active)
{
	if (ft_strchr("csdiupUCDS%", active->type) || ft_atoi(buffer) == 0)
		return (buffer);
	else if (active->type == 'o' && !active->hh)
		return (apply_diese_2(buffer, active));
	else if (ft_strchr("xX", active->type))
		return (apply_diese_x(buffer, active));
	return (buffer);
}
