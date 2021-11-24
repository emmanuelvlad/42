/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:41:01 by evlad             #+#    #+#             */
/*   Updated: 2017/05/30 11:36:06 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_if_exists(t_element *element, int value)
{
	while (element)
	{
		if (element->value == value)
			return (0);
		element = element->next;
	}
	return (1);
}
