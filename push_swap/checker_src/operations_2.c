/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:36:37 by evlad             #+#    #+#             */
/*   Updated: 2017/04/21 18:23:14 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

void	ra(t_stack *a)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (!a->first || !a->first->next)
		return ;
	tmp = a->first;
	tmp2 = a->first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	a->first = a->first->next;
	tmp2->next = NULL;
}

void	rb(t_stack *b)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (!b->first || !b->first->next)
		return ;
	tmp = b->first;
	tmp2 = b->first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	b->first = b->first->next;
	tmp2->next = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (!a->first || !a->first->next)
		return ;
	tmp = a->first;
	while (tmp->next)
	{
		if (!tmp->next->next)
			break ;
		tmp = tmp->next;
	}
	tmp2 = tmp->next;
	tmp2->next = a->first;
	tmp->next = NULL;
	a->first = tmp2;
}

void	rrb(t_stack *b)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (!b->first || !b->first->next)
		return ;
	tmp = b->first;
	while (tmp->next)
	{
		if (!tmp->next->next)
			break ;
		tmp = tmp->next;
	}
	tmp2 = tmp->next;
	tmp2->next = b->first;
	tmp->next = NULL;
	b->first = tmp2;
}
