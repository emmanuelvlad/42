/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:22:19 by evlad             #+#    #+#             */
/*   Updated: 2017/06/26 12:14:40 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*stock_room_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[++i] == ' ')
			break ;
	}
	return (ft_strsub(str, 0, i));
}

int			stock_room_x(t_all *all, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[++i] == ' ')
			break ;
	}
	j = i + 1;
	while (str[j])
	{
		if (str[++j] == ' ')
			break ;
	}
	tmp = ft_strsub(str, i, j - i);
	if (ft_atoi(tmp) > 2147483647 || ft_atoi(tmp) < -2147483648)
	{
		free(tmp);
		print_free_exit("ERROR\n", all);
	}
	return (return_and_free(ft_atoi(tmp), tmp));
}

int			stock_room_y(t_all *all, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[++i] == ' ')
			break ;
	}
	j = i;
	while (str[j])
	{
		if (str[++j] == ' ')
			break ;
	}
	if (ft_atoi(str + j + 1) > 2147483647 || ft_atoi(str + j + 1) < -2147483648)
	{
		print_free_exit("ERROR\n", all);
	}
	return (ft_atoi(str + j + 1));
}

t_room		*stock_link_1(t_all *all, char *str)
{
	char	*tmp;
	t_room	*result;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			break ;
		i++;
	}
	tmp = ft_strsub(str, 0, i);
	result = find_room(all, tmp);
	ft_strdel(&tmp);
	return (result);
}

t_room		*stock_link_2(t_all *all, char *str)
{
	char	*tmp;
	int		i;
	t_room	*result;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			break ;
		i++;
	}
	tmp = ft_strnew(ft_strlen(str) - i - 1);
	tmp = ft_strcpy(tmp, str + i + 1);
	result = find_room(all, tmp);
	ft_strdel(&tmp);
	return (result);
}
