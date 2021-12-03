/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsletter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:08:37 by evlad             #+#    #+#             */
/*   Updated: 2021/12/03 18:50:20 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countsletter(const char *s, char c)
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
