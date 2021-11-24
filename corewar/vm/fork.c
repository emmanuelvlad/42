/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:59:36 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 18:10:27 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	nfork(t_prog *pc, t_env *env)
{
	int		adress;
	t_prog	*new;
	int		i;

	i = 0;
	pc->arg[0] = hex_sum(env->arena[MODA(pc->pc_position + 1)],
				env->arena[MODA(pc->pc_position + 2)]);
	pc->pc_next = 3;
	adress = pc->pc_position + MODR(neg(pc->arg[0]));
	new = pc_new(adress, env, pc->champ_nb);
	pc_add(env, new);
	while (i < REG_NUMBER)
	{
		new->reg[i] = pc->reg[i];
		i++;
	}
	new->carry = pc->carry;
	new->pc_position = adress;
	new->nb_life = pc->nb_life;
	new->pc_next = 1;
}
