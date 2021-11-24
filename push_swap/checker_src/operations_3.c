/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:36:52 by evlad             #+#    #+#             */
/*   Updated: 2017/04/21 18:49:10 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

void	make_op_2(t_stack *a, t_stack *b, char *line)
{
	free(line);
	freestack(a);
	freestack(b);
	printexit("Error\n");
}

void	make_op(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "sa") == 0)
		sa(a);
	else if (ft_strcmp(str, "sb") == 0)
		sb(b);
	else if (ft_strcmp(str, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(str, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(str, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(str, "ra") == 0)
		ra(a);
	else if (ft_strcmp(str, "rb") == 0)
		rb(b);
	else if (ft_strcmp(str, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(str, "rra") == 0)
		rra(a);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(a, b);
	else
		make_op_2(a, b, str);
}
