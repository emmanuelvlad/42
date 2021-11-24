/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 11:18:47 by evlad             #+#    #+#             */
/*   Updated: 2017/05/18 13:51:01 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_history		*init_history(t_all *all, t_room *room)
{
	t_history	*history;

	if (!(history = (t_history*)malloc(sizeof(t_history))))
		free_exit(all);
	history->room = room;
	history->parent = NULL;
	history->next = NULL;
	history->prev = NULL;
	return (history);
}

t_queue			*init_queue(t_all *all, t_room *room)
{
	t_queue		*queue;

	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		free_exit(all);
	queue->room = room;
	queue->next = NULL;
	queue->prev = NULL;
	return (queue);
}

t_path			*init_path(t_all *all, t_room *room)
{
	t_path		*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		free_exit(all);
	path->room = room;
	path->next = NULL;
	path->prev = NULL;
	return (path);
}
