/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:23:05 by evlad             #+#    #+#             */
/*   Updated: 2017/06/26 09:30:42 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_history	*find_parent(t_room *room, t_history *history)
{
	t_history	*tmp;

	tmp = history;
	while (tmp)
	{
		if (tmp->room == room)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void				stock_path(t_all *all, t_history *history)
{
	t_history	*tmp;
	int			i;

	tmp = history;
	all->path = init_path(all, find_end(all));
	i = 0;
	while (tmp)
	{
		if (i++ > 0)
		{
			all->path->prev = init_path(all, tmp->room);
			all->path->prev->next = all->path;
			all->path = all->path->prev;
		}
		tmp = find_parent(tmp->parent, history);
	}
}
