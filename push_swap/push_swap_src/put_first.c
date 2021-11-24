/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:53:22 by evlad             #+#    #+#             */
/*   Updated: 2017/04/21 16:04:12 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_first_a(t_stack *stack, int value)
{
	int			pos;

	pos = parse_pos(stack, value);
	if (pos > stack_size(stack) / 2 + stack_size(stack) % 2)
	{
		while (stack->first->value != value)
			rra(stack);
	}
	else
	{
		while (stack->first->value != value)
			ra(stack);
	}
}

void	put_first_b(t_stack *stack, int value)
{
	int			pos;

	pos = parse_pos(stack, value);
	if (pos > stack_size(stack) / 2 + stack_size(stack) % 2)
	{
		while (stack->first->value != value)
			rrb(stack);
	}
	else
	{
		while (stack->first->value != value)
			rb(stack);
	}
}
