/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:31:18 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/19 17:04:14 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			initialize_instr(t_instr **instr)
{
	int		i;

	i = 0;
	if ((*instr = malloc(sizeof(t_instr))) == NULL)
		return (0);
	(*instr)->lab = NULL;
	(*instr)->nom = NULL;
	(*instr)->param[0] = NULL;
	(*instr)->param[1] = NULL;
	(*instr)->param[2] = NULL;
	(*instr)->param[3] = NULL;
	ft_bzero((*instr)->ocp, 9);
	while (i < 8)
	{
		(*instr)->ocp[i] = '0';
		i++;
	}
	(*instr)->index = 0;
	(*instr)->next = NULL;
	return (1);
}
