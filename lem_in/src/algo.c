/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:25:37 by evlad             #+#    #+#             */
/*   Updated: 2017/06/26 09:30:45 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_in_queue(t_all *all, t_queue *queue, t_room *room)
{
	t_queue *tmp;

	tmp = queue;
	while (tmp->prev)
		tmp = tmp->prev;
	tmp->prev = init_queue(all, room);
	tmp->prev->next = tmp;
}

static void		add_history(t_all *all, t_room *room, t_room *parent)
{
	all->history->prev = init_history(all, room);
	all->history->prev->parent = parent;
	all->history->prev->next = all->history;
	all->history = all->history->prev;
}

int				check_path(t_all *all)
{
	t_link	*tmp;

	all->queue = init_queue(all, find_start(all));
	all->history = init_history(all, all->queue->room);
	while (all->queue)
	{
		if (all->queue->room == find_end(all))
			return (1);
		tmp = all->queue->room->links;
		while (tmp)
		{
			if (!find_history(tmp->room, all->history))
			{
				add_in_queue(all, all->queue, tmp->room);
				add_history(all, tmp->room, all->queue->room);
			}
			tmp = tmp->next;
		}
		if (!all->queue->prev)
			break ;
		all->queue = all->queue->prev;
	}
	return (0);
}

static int		move_to_next(t_all *all, int ant)
{
	t_path		*tmp;
	t_room		*room;

	tmp = all->path;
	if (find_ant(all, ant))
		room = find_ant(all, ant);
	else
		room = find_start(all);
	while (tmp->room != room)
		tmp = tmp->next;
	if (tmp->next->room && !tmp->next->room->occuped)
	{
		ft_printf("L%d-%s ", ant, tmp->next->room->name);
		room->occuped = 0;
		if (tmp->next->room == find_end(all))
			return (1);
		tmp->next->room->occuped = ant;
	}
	return (0);
}

void			lem_in(t_all *all)
{
	int		need_to_move;
	int		i;

	need_to_move = 1;
	i = 1;
	stock_path(all, all->history);
	while (need_to_move <= all->ants)
	{
		i = need_to_move;
		while (i <= all->ants)
		{
			if (move_to_next(all, i))
				need_to_move++;
			i++;
		}
		write(1, "\n", 1);
	}
}
