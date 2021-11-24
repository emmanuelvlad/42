/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:47:35 by evlad             #+#    #+#             */
/*   Updated: 2017/04/20 15:46:14 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element			*init_element(int value)
{
	t_element	*element;

	if (!(element = (t_element*)malloc(sizeof(t_element))))
		exit(EXIT_FAILURE);
	element->value = value;
	element->next = NULL;
	return (element);
}

t_stack				*init_a(char *str, t_malloc *mal)
{
	t_stack		*stack;
	t_element	*element;

	if (!(element = (t_element*)malloc(sizeof(t_element))))
		exit(EXIT_FAILURE);
	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		exit(EXIT_FAILURE);
	stack->first = NULL;
	freexit(stack, str, 1, mal);
	element->value = ft_atoi(str);
	element->next = NULL;
	stack->first = element;
	return (stack);
}

t_stack				*init_b(void)
{
	t_stack		*stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		exit(EXIT_FAILURE);
	stack->first = NULL;
	return (stack);
}

t_malloc			*init_malloc(void)
{
	t_malloc	*mal;

	if (!(mal = (t_malloc*)malloc(sizeof(t_malloc))))
		exit(EXIT_FAILURE);
	mal->av = NULL;
	return (mal);
}
