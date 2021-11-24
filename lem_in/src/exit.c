/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 09:02:52 by evlad             #+#    #+#             */
/*   Updated: 2017/06/26 11:10:54 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_exit(t_all *all)
{
	free_all(all);
	exit(EXIT_FAILURE);
}

void		print_exit(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

void		print_free_exit(char *str, t_all *all)
{
	free_all(all);
	print_exit(str);
}
