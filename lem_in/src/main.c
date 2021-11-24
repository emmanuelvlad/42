/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:05:40 by evlad             #+#    #+#             */
/*   Updated: 2017/06/26 12:15:06 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	process(t_all *all)
{
	t_entry	*tmp;

	parse_ants(all);
	tmp = all->entry->next;
	while (tmp)
	{
		if (ft_strcmp("##start", tmp->str) == 0)
		{
			tmp = tmp->next;
			tmp = parse_line(all, tmp, 1, 0);
		}
		else if (ft_strcmp("##end", tmp->str) == 0)
		{
			tmp = tmp->next;
			tmp = parse_line(all, tmp, 0, 1);
		}
		else
			tmp = parse_line(all, tmp, 0, 0);
		tmp = tmp->next;
	}
	if (!is_possible(all))
		print_free_exit("ERROR\n", all);
	else
		lem_in(all);
	free_all(all);
}

void	read_gnl(t_all *all)
{
	char		*line;
	int			i;
	t_entry		*entry;

	i = 1;
	while (get_next_line(0, &line))
	{
		if (i++ == 1)
		{
			entry = init_entry(all, line, i);
			all->entry = entry;
		}
		else
		{
			entry->next = init_entry(all, line, i);
			entry->next->prev = entry;
			entry = entry->next;
		}
	}
	ft_strdel(&line);
	if (i == 1)
		print_free_exit("ERROR\n", all);
}

int		main(void)
{
	t_all		*all;

	all = init_all();
	read_gnl(all);
	process(all);
	return (0);
}
