/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_with.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:31:40 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/19 17:04:30 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_len(char *tab, int start)
{
	int		i;

	i = start;
	while (tab[i] != '"' && tab[i])
		i++;
	if (tab[start] == '\0')
		return (0);
	return (i);
}

int		get_name(char *tab, t_main **main)
{
	int	start;
	int	len;
	int	i;

	start = idx_start(tab, ".name");
	if (check_quote(tab, start - 1) == 0)
		return (error_msg(0));
	if ((len = get_len(tab, start)) == 0)
		return (0);
	i = 0;
	while (start < len)
	{
		ME->N[i] = tab[start];
		start++;
		i++;
	}
	ME->N[i] = '\0';
	return (1);
}

int		get_comment(char *tab, t_main **main)
{
	int		start;
	int		len;
	int		i;

	start = idx_start(tab, ".comment");
	if (check_quote(tab, start - 1) == 0)
		return (error_msg(11));
	if ((len = get_len(tab, start)) == 0)
		return (0);
	i = 0;
	while (start < len)
	{
		ME->comment[i] = tab[start];
		start++;
		i++;
	}
	ME->comment[i] = '\0';
	return (1);
}

int		start_with(char *tab, char *str)
{
	int	i;
	int	len;

	i = 0;
	if (tab == NULL)
		return (0);
	len = ft_strlen(str);
	while (i < len)
	{
		if (tab[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

int		get_info(char **tab, t_main **main, int *k)
{
	if (start_with(tab[*k], ".name") == 1)
	{
		if (get_name(tab[*k], &ME) == 0)
			return (0);
		(*k)++;
	}
	if (start_with(tab[*k], ".comment") == 1)
	{
		if (get_comment(tab[*k], &ME) == 0)
			return (0);
		(*k)++;
	}
	return (1);
}
