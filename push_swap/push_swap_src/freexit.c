/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:54:56 by evlad             #+#    #+#             */
/*   Updated: 2017/05/30 12:51:18 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_stack(t_stack *stack)
{
	t_element	*tmp;
	int			value;

	tmp = stack->first;
	if (tmp == NULL)
		return (0);
	value = tmp->value;
	tmp = tmp->next;
	while (tmp)
	{
		if (value > tmp->value)
			return (0);
		value = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

void	freestack(t_stack *stack)
{
	t_element	*tmp;

	tmp = NULL;
	if (!stack)
		return ;
	while (stack->first)
	{
		tmp = stack->first;
		stack->first = stack->first->next;
		free(tmp);
	}
	free(stack);
}

void	free_malloc(t_malloc *malloc)
{
	int		i;

	i = 0;
	if (!malloc)
		return ;
	if (malloc->av)
	{
		while (i < malloc->ac)
			free(malloc->av[i++]);
	}
	free(malloc->av);
	free(malloc);
}

void	freexit(t_stack *stack, char *str, int first, t_malloc *malloc)
{
	size_t	i;

	i = 0;
	if (str[0] == '-' && str[1])
		i++;
	if (!ft_strisdigit(str + i))
	{
		freestack(stack);
		free_malloc(malloc);
		printexit("Error\n");
	}
	if ((ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648) ||
			(!first && !check_if_exists(stack->first, ft_atoi(str))))
	{
		freestack(stack);
		free_malloc(malloc);
		printexit("Error\n");
	}
}

void	printexit(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}
