/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:39:23 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:06:12 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	introduce_champ(t_champ *champ)
{
	t_champ	*tmp;
	int		i;

	i = 1;
	tmp = champ;
	ft_putendl("Introducing contestants...");
	while (tmp)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			i, tmp->h->prog_size, tmp->h->prog_name, tmp->h->comment);
		i++;
		tmp = tmp->next;
	}
}
