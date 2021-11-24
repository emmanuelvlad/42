/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:43:40 by evlad             #+#    #+#             */
/*   Updated: 2017/06/26 11:34:04 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*init_link(t_all *all, t_room *room)
{
	t_link		*link;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		free_exit(all);
	link->room = room;
	link->next = NULL;
	return (link);
}

t_room		*init_room(char *name, int startend, int x, int y)
{
	t_room		*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	room->name = name;
	if (startend == 1)
		room->start = 1;
	else
		room->start = 0;
	if (startend == 2)
		room->end = 1;
	else
		room->end = 0;
	room->x = x;
	room->y = y;
	room->occuped = 0;
	room->next = NULL;
	room->links = NULL;
	return (room);
}

t_all		*init_all(void)
{
	t_all	*all;

	if (!(all = (t_all*)malloc(sizeof(t_all))))
		exit(EXIT_FAILURE);
	all->ants = 0;
	all->room = NULL;
	all->entry = NULL;
	all->queue = NULL;
	all->history = NULL;
	all->path = NULL;
	return (all);
}

t_entry		*init_entry(t_all *all, char *str, int line)
{
	t_entry		*entry;

	if (!(entry = (t_entry*)malloc(sizeof(t_entry))))
		free_exit(all);
	entry->str = str;
	entry->line = line;
	entry->next = NULL;
	entry->prev = NULL;
	return (entry);
}
