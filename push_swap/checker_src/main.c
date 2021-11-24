/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:08:31 by evlad             #+#    #+#             */
/*   Updated: 2017/05/30 12:51:00 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(int ac, char **av, t_malloc *malloc)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;

	a = init_a(av[ac - 1], malloc);
	b = init_b();
	stock(a, ac, av, malloc);
	free_malloc(malloc);
	while (get_next_line(0, &line))
	{
		make_op(line, a, b);
		free(line);
	}
	free(line);
	if (check_stack(a) && !b->first)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	freestack(a);
	freestack(b);
}

int		main(int ac, char **av)
{
	char		*str;
	t_malloc	*malloc;

	if (!(str = ft_strjoin("checker ", av[1])))
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
		checker(ac, av, malloc);
	}
	return (0);
}
