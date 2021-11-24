/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 13:24:32 by evlad             #+#    #+#             */
/*   Updated: 2017/04/28 17:41:27 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b, int amount)
{
	if (amount <= 1)
		return ;
	else if (check_stack(a))
		return ;
	else if (amount == 2)
	{
		if (a->first->value > a->first->next->value)
			ra(a);
	}
	else if (amount == 3)
		sort_3(a);
	else if (amount <= 30)
		sort_30(a, b);
	else
		sort_plus(a, b);
}

void	sort_3(t_stack *stack)
{
	int		min;
	int		max;

	min = parse_min(stack);
	max = parse_max(stack);
	if (stack->first->value == max && stack->first->next->next->value == min)
	{
		sa(stack);
		rra(stack);
	}
	else if (stack->first->next->value == max &&
			stack->first->next->next->value == min)
		rra(stack);
	else if (stack->first->next->value == min &&
			stack->first->next->next->value == max)
		sa(stack);
	else if (stack->first->value == max && stack->first->next->value == min)
		ra(stack);
	else if (stack->first->value == min && stack->first->next->value == max)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_30(t_stack *a, t_stack *b)
{
	while (stack_size(a) > 3)
	{
		put_first_a(a, parse_min(a));
		pb(a, b);
	}
	sort_3(a);
	while (stack_size(b))
		pa(a, b);
}

void	sort_plus(t_stack *a, t_stack *b)
{
	int		percent;

	percent = (stack_size(a) / 10) + (((stack_size(a) / 10) % 10) / 2);
	if (stack_size(a) > 200)
		percent /= 2;
	while (stack_size(a))
	{
		put_first_a(a, closest(a, parse_max_min(a, percent)));
		pb(a, b);
	}
	while (stack_size(b))
	{
		put_first_b(b, parse_max(b));
		pa(a, b);
	}
}
