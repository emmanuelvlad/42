/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:31:12 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/19 17:04:11 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*copy_param(char *tab, int i, int j)
{
	char	*res;
	int		len;
	int		k;

	len = j - i + 1;
	k = 0;
	if ((res = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (k < len)
	{
		res[k] = tab[i];
		k++;
		i++;
	}
	res[k] = '\0';
	return (res);
}

int		get_param_bis(char *tab, int j, int *i, int *num)
{
	if (tab[j] == '\0' || tab[j] == ';')
		return (1);
	if (tab[j + 1] == '\0' || tab[j + 1] == ';')
		return (1);
	if (tab[j + 2] == '\0' || tab[j + 2] == ';')
		return (1);
	if (tab[j] == ',' && tab[j + 1] != ' ')
		j = j + 1;
	else
		j = j + 2;
	*i = j;
	(*num)++;
	return (0);
}

int		get_param(t_instr **instr, char *tab, int i)
{
	int		num;
	int		j;
	int		next;

	num = 0;
	next = 1;
	j = i;
	while (tab[j] && tab[j] != ';' && next == 1 && num <= 3)
	{
		j = i;
		while (tab[j] && tab[j] != ';' && tab[j] != ',' \
		&& tab[j] != ' ' && tab[j] != '\t' && tab[j] != '\v')
			j++;
		if (((*instr)->param[num] = copy_param(tab, i, j - 1)) == NULL)
			return (0);
		if (tab[j] == ',')
			next = 1;
		else
			next = 0;
		if (get_param_bis(tab, j, &i, &num) == 1)
			return (1);
	}
	while (tab[j] && tab[j] != ';')
		j++;
	return (1);
}
