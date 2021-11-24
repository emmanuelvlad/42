/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_winner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:21:43 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/20 13:00:02 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		select_winner(t_env env, t_champ *champ)
{
	int		i;
	t_champ	*tmp;

	tmp = champ;
	i = env.last_alive;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	if (env.last_alive > 0 && env.last_alive <= 4)
		ft_printf("Contestant %d, \"%s\", has won!\n",
		env.last_alive, tmp->h->prog_name);
	else
		ft_printf("No winner, give me better champions!\n");
	return (1);
}
