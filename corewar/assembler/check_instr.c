/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:30:40 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/20 12:00:22 by mkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		num_param(t_instr *instr)
{
	int		count;

	count = 0;
	if (instr->param[0] != NULL)
		count = 1;
	if (instr->param[1] != NULL)
		count = 2;
	if (instr->param[2] != NULL)
		count = 3;
	if (instr->param[3] != NULL)
		count = 4;
	return (count);
}

int		check_instr(t_instr *instr, t_lab *label)
{
	int		i;
	t_instr	*tmp;

	tmp = instr;
	if (tmp == NULL || tmp->nom == NULL)
	{
		ft_putstr("\x1b[31mError: no instruction in the file.\x1b[0m\n");
		return (0);
	}
	while (tmp && tmp->nom)
	{
		i = 0;
		while (i < 16)
		{
			if (ft_strcmp(tmp->nom, g_op_tab[i].nom) == 0)
				break ;
			i++;
		}
		if (num_param(tmp) != g_op_tab[i].nb_param)
			return (error_msg(6));
		if (check_param(tmp, label, i) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
