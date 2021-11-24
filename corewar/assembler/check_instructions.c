/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:30:48 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/20 11:59:42 by mkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*get_instruction(char *tab, int *i, int i_init)
{
	char	*res;
	t_gi	*gi;

	if ((gi = malloc(sizeof(t_gi))) == NULL)
		return (NULL);
	gi->j = 0;
	gi->len = 0;
	while (tab[*i] && (tab[*i] == ' ' || tab[*i] == '\t' || tab[*i] == '\v'))
		(*i)++;
	gi->start = *i;
	while (tab[*i] && tab[*i] != ' ' && tab[*i] != '\t' && tab[*i] != '\v')
	{
		(gi->len)++;
		(*i)++;
	}
	if ((res = malloc(sizeof(char) * gi->len + 1)) == NULL)
		return (NULL);
	gi->start_init = gi->start;
	get_instruction_bis(res, tab, gi);
	free(gi);
	if (i_init != -1)
		*i = i_init;
	return (res);
}

int		only_comment(char *tab, int *i)
{
	if (tab[*i] == '#')
		return (1);
	while (tab[*i] == ' ' || tab[*i] == '\t' || tab[*i] == '\v')
		(*i)++;
	if (tab[*i] == ';' || tab[*i] == '\0' || tab[*i] == '#')
		return (1);
	return (0);
}

int		check_label(char *tab, int *i)
{
	char	*instr;
	int		i_init;
	int		j;

	i_init = *i;
	j = 0;
	instr = get_instruction(tab, i, i_init);
	while (g_op_tab[j].nom != 0)
	{
		if (ft_strcmp(instr, g_op_tab[j].nom) == 0)
			break ;
		j++;
	}
	free(instr);
	if (j < 16)
	{
		*i = i_init;
		return (1);
	}
	while (ft_strchr(LABEL_CHARS, tab[*i]) != NULL && tab[*i] != '\0')
		(*i)++;
	if (tab[*i] == LABEL_CHAR)
		return (0);
	*i = i_init;
	return (1);
}

void	get_label(char **tab, int *k, t_lab **label, int *i)
{
	int		i_init;

	i_init = *i;
	if (LE->line != NULL)
	{
		if ((LE->next = malloc(sizeof(t_lab))) == NULL)
			return ;
		LE = LE->next;
		LE->line = NULL;
		LE->next = NULL;
	}
	LE->N = get_only_label(&tab[*k][i_init]);
	*i = 0;
	get_label_bis(tab, &(*k), &(*i));
	LE->line = ft_strdup(&tab[*k][*i]);
	LE->pos = 0;
	if (tab[*k + 1] != NULL)
	{
		while (only_comment(tab[*k], i) == 1)
			(*k)++;
	}
}

int		check_instructions(char **tab, int k, t_main **main)
{
	t_ci		*ci;

	if ((ci = malloc(sizeof(t_ci))) == NULL)
		return (error_msg(13));
	ci->i = 0;
	if (initialize_instr(&ME->I) == 0)
		return (return_free_ci(&ci, 0));
	ci->tmp = ME->I;
	ci->start = ME->L;
	ci->str = NULL;
	while (tab[k] != NULL)
	{
		while (start_with(tab[k], ".name") == 1 \
				|| start_with(tab[k], ".comment") == 1)
		{
			if (get_info(tab, &ME, &k) == 0)
				return (return_free_ci(&ci, 0));
		}
		if ((check_instructions_bis(tab, &k, &(*main), &ci)) == 0)
			return (return_free_ci(&ci, 0));
	}
	ME->I = NULL;
	ME->L = ci->start;
	ME->I = ci->tmp;
	return (return_free_ci(&ci, 1));
}
