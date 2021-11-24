/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:22:36 by evlad             #+#    #+#             */
/*   Updated: 2017/05/18 14:18:40 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "./lem_in.h"

void				show_all_rooms(t_all *all);
void				show_links_of(t_room *room);
void				show_all_links(t_all *all);
void				show_path(t_path *path);

#endif
