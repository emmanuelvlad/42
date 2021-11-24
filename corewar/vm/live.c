/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:44:18 by evlad             #+#    #+#             */
/*   Updated: 2017/07/20 12:53:34 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	live(t_prog *pc, t_env *env)
{
	int		arg;

	arg = -1 * hex_sum2(env->arena[MODA(pc->pc_position + 1)],
				env->arena[MODA(pc->pc_position + 2)],
				env->arena[MODA(pc->pc_position + 3)],
				env->arena[MODA(pc->pc_position + 4)]);
	if (arg && arg > 0 && arg < 5)
	{
		env->last_alive = arg;
		env->players_lives[arg - 1]++;
	}
	pc->nb_life++;
	pc->pc_next = 5;
}
