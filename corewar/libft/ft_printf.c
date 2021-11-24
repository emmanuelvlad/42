/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:07:28 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:22:55 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fill_d(t_display *d, int *j, const char *str_i)
{
	if (!(fill_flag(str_i + *j)) && !(str_i[*j] >= '0' && str_i[*j] <= '9')
		&& !(str_i[*j] == '.'))
		return (0);
	if (fill_flag(str_i + *j))
		d->flag |= fill_flag(str_i + *j);
	else if (str_i[*j] >= '0' && str_i[*j] <= '9')
		d->size = ft_atoi(str_i + *j);
	else if (str_i[*j] == '.')
		d->prec = ft_atoi(str_i + *j + 1);
	if ((str_i[*j] >= '1' && str_i[*j] <= '9') || str_i[*j] == '.')
	{
		(*j)++;
		while (str_i[*j] >= '0' && str_i[*j] <= '9')
			(*j)++;
	}
	else
		(*j)++;
	return (1);
}

int		find_conv(const char *str_i, va_list ap, int *tot)
{
	int			i;
	int			j;
	t_display	d;
	int			x;

	j = 1;
	x = -1;
	d.flag = 0;
	d.size = 0;
	d.prec = -1;
	while (x == -1)
	{
		if (!str_i[j])
			return (j);
		x = conversion_type(ap, str_i[j], d);
		i = fill_d(&d, &j, str_i);
		if (x == -1 && i == 0)
		{
			*tot += no_conversion(d);
			return (j);
		}
	}
	*tot += x;
	return (++j);
}

int		next_prct(int i, const char *str, int *tot)
{
	int		j;
	char	*s;

	s = NULL;
	j = 0;
	while (str[i + j] != '\0' && str[i + j] != '%')
		j++;
	s = ft_strsub(str, i, j);
	ft_putstr(s);
	ft_strdel(&s);
	*tot += j;
	return (j);
}

int		printf_next(const char *str, va_list ap, int *tot)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = find_conv(str + i, ap, tot);
			i += j;
		}
		else
			i += next_prct(i, str, tot);
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	int		tot;
	va_list	ap;

	tot = 0;
	if (str)
	{
		va_start(ap, str);
		printf_next(str, ap, &tot);
		va_end(ap);
	}
	return (tot);
}
