/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:30:52 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/19 17:03:43 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*get_only_label(char *str)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	while (str[i] && ft_strchr(LABEL_CHARS, str[i]) != NULL)
		i++;
	len = i + 2;
	if ((res = malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len - 2)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		check_param_label(char *str, t_lab *label)
{
	char	*lab;
	t_lab	*tmp;

	tmp = label;
	if ((lab = get_only_label(str)) == NULL)
		return (0);
	while (tmp)
	{
		if (ft_strcmp(lab, tmp->nom) == 0)
		{
			free(lab);
			return (1);
		}
		tmp = tmp->next;
	}
	free(lab);
	return (0);
}
