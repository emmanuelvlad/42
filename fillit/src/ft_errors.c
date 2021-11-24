/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:59:10 by evlad             #+#    #+#             */
/*   Updated: 2016/12/03 10:28:53 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_errors(int ac, t_coord *crd)
{
	if (ac == 1 || ac > 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (-1);
	}
	if (crd == NULL)
	{
		ft_putstr("error\n");
		return (-1);
	}
	if (crd->total_tetri == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (0);
}
