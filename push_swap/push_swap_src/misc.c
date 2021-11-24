/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:38:04 by evlad             #+#    #+#             */
/*   Updated: 2017/04/21 17:27:18 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		closest(t_stack *stack, int value)
{
	t_element	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		if (tmp->value <= value)
			break ;
		tmp = tmp->next;
	}
	return (tmp->value);
}
