/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsletter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:08:37 by evlad             #+#    #+#             */
/*   Updated: 2016/11/11 17:10:05 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countsletter(const char *s, char c)
{
	int	letter;

	letter = 0;
	while (*s++)
	{
		letter++;
		if (*s == c)
			break ;
	}
	return (letter);
}
