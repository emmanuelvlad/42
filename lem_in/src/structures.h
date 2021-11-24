/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:30:16 by evlad             #+#    #+#             */
/*   Updated: 2017/05/18 13:49:36 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "./lem_in.h"

/*
** --------------------------------------------------------------------------
**									STRUCTURES
** --------------------------------------------------------------------------
*/

typedef struct			s_link
{

	struct s_room		*room;
	struct s_link		*next;
	struct s_link		*prev;
}						t_link;

typedef struct			s_room
{
	char				*name;
	int					start;
	int					end;
	int					x;
	int					y;
	int					occuped;
	struct s_link		*links;
	struct s_room		*next;
	struct s_room		*prev;
}						t_room;

typedef struct			s_entry
{
	char				*str;
	int					line;
	struct s_entry		*next;
	struct s_entry		*prev;
}						t_entry;

typedef struct			s_queue
{
	struct s_room		*room;
	struct s_queue		*next;
	struct s_queue		*prev;
}						t_queue;

typedef struct			s_history
{
	struct s_room		*room;
	struct s_room		*parent;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

typedef struct			s_path
{
	struct s_room		*room;
	struct s_path		*next;
	struct s_path		*prev;
}						t_path;

typedef struct			s_all
{
	int					ants;
	struct s_room		*room;
	struct s_entry		*entry;
	struct s_queue		*queue;
	struct s_history	*history;
	struct s_path		*path;
}						t_all;

#endif
