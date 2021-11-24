/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:10:07 by evlad             #+#    #+#             */
/*   Updated: 2017/05/30 11:26:25 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int ac, char **av, t_malloc *malloc)
{
	t_stack		*a;
	t_stack		*b;

	a = init_a(av[ac - 1], malloc);
	b = init_b();
	stock(a, ac, av, malloc);
	sort(a, b, stack_size(a));
	free_malloc(malloc);
	freestack(a);
	freestack(b);
}

int		main(int ac, char **av)
{
	char		*str;
	t_malloc	*malloc;

	if (!(str = ft_strjoin("push_swap ", av[1])))
		exit(EXIT_FAILURE);
	malloc = init_malloc();
	if (ac > 1)
	{
		if (ac == 2)
		{
			ac = ft_countsword(av[1], ' ') + 1;
			if (!(av = ft_strsplit(str, ' ')))
				exit(EXIT_FAILURE);
			malloc->av = av;
			malloc->ac = ac;
		}
		free(str);
		push_swap(ac, av, malloc);
	}
	return (0);
}
