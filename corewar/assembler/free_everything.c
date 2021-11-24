/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 12:44:24 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/20 12:01:31 by mkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			return_free_ci(t_ci **ci, int nb)
{
	if ((*ci)->str != NULL)
		free((*ci)->str);
	free(*ci);
	return (nb);
}

void		free_lab(t_lab **lab)
{
	t_lab	*tmp;
	t_lab	*tmp2;

	tmp = *lab;
	while (tmp)
	{
		tmp2 = tmp;
		if (tmp->nom)
			ft_strdel(&tmp->nom);
		if (tmp->line)
			ft_strdel(&tmp->line);
		tmp = tmp->next;
		free(tmp2);
	}
}

void		free_instr(t_instr **instr)
{
	int		i;
	t_instr	*tmp;

	while ((*instr))
	{
		tmp = *instr;
		i = 0;
		if (tmp->nom)
			ft_strdel(&tmp->nom);
		if (tmp->lab)
			ft_strdel(&tmp->lab);
		while (i < MAX_ARGS_NUMBER)
		{
			free(tmp->param[i]);
			i++;
		}
		ft_bzero(tmp->ocp, 9);
		(*instr) = (*instr)->next;
		free(tmp);
	}
}

int			return_main(t_main **main)
{
	free(*main);
	ft_putstr("\x1b[31mError: non-existent file\x1b[0m\n");
	return (0);
}

void		free_everything(t_main **main, char **tab)
{
	int		i;

	i = 0;
	if ((*main) != NULL)
	{
		free_instr(&((*main)->instr));
		free_lab(&((*main)->label));
		free(*main);
	}
	if (tab != NULL)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
