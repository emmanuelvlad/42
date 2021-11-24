/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:46:57 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 17:53:38 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			init_arena(unsigned char *arena)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		arena[i] = 0;
		i++;
	}
}

static void		save_color(t_env *env, int start, int size, char champ_nb)
{
	int i;

	i = 0;
	champ_nb++;
	while (i < size)
	{
		ft_memcpy(env->color + start + i, &(champ_nb), 1);
		i++;
	}
}

void			insert_players(t_champ *champ, t_env *env)
{
	t_champ	*tmp;
	int		start;

	start = 0;
	tmp = champ;
	while (tmp)
	{
		ft_memcpy(env->arena + start, tmp->champ, tmp->size);
		save_color(env, start, tmp->size, tmp->champ_nb);
		tmp = tmp->next;
		start += MEM_SIZE / env->nb_players;
	}
}

void			create_arena(t_champ *champ, t_env *env)
{
	init_arena(env->arena);
	init_arena(env->color);
	insert_players(champ, env);
}
