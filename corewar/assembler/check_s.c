/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:30:59 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/20 12:01:02 by mkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_name(char *argv)
{
	int		len;

	len = (int)ft_strlen(argv);
	if (len < 3)
		return (error_msg(1));
	if (ft_strcmp(&argv[len - 2], ".s") != 0)
		return (error_msg(1));
	return (1);
}

int		check_tab(char **tab, t_main **main)
{
	int		len;

	len = strlenet(tab);
	if (len < 3)
	{
		ft_putstr("\x1b[31mError: not enough info in the file.\x1b[0m\n");
		return (0);
	}
	if ((ME->L = malloc(sizeof(t_lab))) == NULL)
		return (0);
	ME->L->line = NULL;
	ME->L->N = NULL;
	ME->L->next = NULL;
	if (check_instructions(tab, 0, &ME) == 0)
		return (0);
	if (check_instr(ME->I, ME->L) == 0)
		return (0);
	return (1);
}

int		check_s(char **tab, t_main **main)
{
	if (check_tab(tab, &ME) == 0)
		return (0);
	return (1);
}
