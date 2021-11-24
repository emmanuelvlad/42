/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions_bis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:19:05 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/19 17:03:39 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_instruction_bis(char *res, char *tab, t_gi *gi)
{
	while (gi->start < gi->len + gi->start_init)
	{
		res[gi->j] = tab[gi->start];
		(gi->j)++;
		(gi->start)++;
	}
	res[gi->j] = '\0';
}

void	get_label_bis(char **tab, int *k, int *i)
{
	while (tab[*k][*i] && (tab[*k][*i] == ' ' \
				|| tab[*k][*i] == '\v' || tab[*k][*i] == '\t'))
		(*i)++;
	while (tab[*k][*i] && ft_strchr(LABEL_CHARS, tab[*k][*i]) != NULL)
		(*i)++;
	if (tab[*k][*i] == LABEL_CHAR)
		(*i)++;
	while (tab[*k][*i] && (tab[*k][*i] == ' ' \
				|| tab[*k][*i] == '\v' || tab[*k][*i] == '\t'))
		(*i)++;
	if (tab[*k][*i] == '\0')
	{
		(*k)++;
		*i = 0;
	}
}

int		check_instructions_ter(char **tab, int *k, t_main **main, t_ci **ci)
{
	ME->I->N = ft_strdup((*ci)->str);
	free((*ci)->str);
	(*ci)->str = NULL;
	if ((*ci)->j == 16)
		return (error_msg(9));
	while (tab[*k][(*ci)->i] == ' ' \
			|| tab[*k][(*ci)->i] == '\t' || tab[*k][(*ci)->i] == '\v')
		((*ci)->i)++;
	if (get_param(&ME->I, tab[*k], (*ci)->i) == 0)
		return (0);
	(*k)++;
	if (initialize_instr(&ME->I->next) == 0)
		return (error_msg(13));
	ME->I = ME->I->next;
	return (1);
}

int		check_instructions_bis(char **tab, int *k, t_main **main, t_ci **ci)
{
	if (tab[*k] == NULL)
		return (1);
	(*ci)->i = 0;
	(*ci)->j = -1;
	if (tab[*k] && only_comment(tab[*k], &((*ci)->i)) == 1)
	{
		(*k)++;
		(*ci)->i = 0;
		return (1);
	}
	(*ci)->i_init = (*ci)->i;
	if (check_label(tab[*k], &((*ci)->i)) == 0)
	{
		(*ci)->i = (*ci)->i_init;
		get_label(tab, k, &(ME->L), &((*ci)->i));
		ME->I->lab = ft_strdup(ME->L->N);
	}
	(*ci)->str = get_instruction(tab[*k], &((*ci)->i), -1);
	while (g_op_tab[((*ci)->j)++].nom != 0 && (*ci)->j < 16)
	{
		if (ft_strcmp((*ci)->str, g_op_tab[(*ci)->j].nom) == 0)
			break ;
	}
	return (check_instructions_ter(tab, k, &(*main), &(*ci)));
}
