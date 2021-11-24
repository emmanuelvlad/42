/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:11:55 by evlad             #+#    #+#             */
/*   Updated: 2017/05/18 14:52:44 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *a)
{
	t_element	*tmp;
	t_element	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (a->first && a->first->next)
	{
		tmp = a->first;
		tmp2 = a->first->next->next;
		a->first = a->first->next;
		a->first->next = tmp;
		a->first->next->next = tmp2;
	}
}

void	sb(t_stack *b)
{
	t_element	*tmp;
	t_element	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (b->first && b->first->next)
	{
		tmp = b->first;
		tmp2 = b->first->next->next;
		b->first = b->first->next;
		b->first->next = tmp;
		b->first->next->next = tmp2;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_element	*tmp;

	tmp = NULL;
	if (b->first)
	{
		tmp = b->first;
		b->first = b->first->next;
		tmp->next = a->first;
		a->first = tmp;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_element	*tmp;

	tmp = NULL;
	if (a->first)
	{
		tmp = a->first;
		a->first = a->first->next;
		tmp->next = b->first;
		b->first = tmp;
	}
}
