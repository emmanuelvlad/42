/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:09:50 by evlad             #+#    #+#             */
/*   Updated: 2016/11/24 18:07:58 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swap(char *pt1, char *pt2)
{
	char	temp;

	temp = *pt1;
	*pt1 = *pt2;
	*pt2 = temp;
}
