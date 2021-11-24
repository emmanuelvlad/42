/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:05:36 by evlad             #+#    #+#             */
/*   Updated: 2017/06/26 11:34:14 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_entry(t_entry *entry)
{
	t_entry		*tmp;

	tmp = NULL;
	if (entry == NULL)
		return ;
	while (entry)
	{
		tmp = entry;
		entry = entry->next;
		if (tmp->str)
			ft_strdel(&tmp->str);
		free(tmp);
	}
	free(entry);
}

void		free_link(t_link *link)
{
	t_link		*tmp;

	tmp = NULL;
	if (link == NULL)
		return ;
	while (link)
	{
		tmp = link;
		link = link->next;
		free(tmp);
	}
}

void		free_room(t_room *room)
{
	t_room		*tmp;

	tmp = NULL;
	if (room == NULL)
		return ;
	while (room)
	{
		tmp = room;
		room = room->next;
		if (tmp->links)
			free_link(tmp->links);
		if (tmp->name)
			ft_strdel(&tmp->name);
		if (tmp)
			free(tmp);
	}
}

void		free_all(t_all *all)
{
	free_entry(all->entry);
	free_queue(all->queue);
	free_history(all->history);
	free_path(all->path);
	free_room(all->room);
	free(all);
}
