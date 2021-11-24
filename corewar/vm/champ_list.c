/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 14:12:29 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 17:05:11 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	champ_add(t_champ **champ, t_champ **new)
{
	t_champ	*tmp;

	if (*champ)
	{
		tmp = *champ;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *new;
	}
	else
		*champ = *new;
}

int		store_magic(unsigned char *file, t_header **h)
{
	(*h)->magic = little_to_big(*(unsigned int*)(file));
	if ((*h)->magic != COREWAR_EXEC_MAGIC)
		return (handle_error(4));
	return (0);
}

int		store_champ_info(unsigned char *file, t_champ **new, int tot_char)
{
	int i;

	if ((i = ft_strlen((char*)file + 4)) <= PROG_NAME_LENGTH)
	{
		ft_memcpy((*new)->h->prog_name, file + 4, i);
		(*new)->h->prog_name[i + 1] = '\0';
	}
	else
		return (handle_error(1));
	(*new)->h->prog_size = 0;
	(*new)->h->prog_size = *((unsigned char*)file + 139);
	(*new)->h->prog_size += (*((unsigned char*)file + 138) << 8) & 0xFF00;
	if ((i = ft_strlen((char*)file + 140)) <= COMMENT_LENGTH)
	{
		ft_memcpy((*new)->h->comment, file + 140, i);
		(*new)->h->comment[i + 1] = '\0';
	}
	else
		return (handle_error(2));
	if (tot_char - 2192 <= CHAMP_MAX_SIZE)
		ft_memcpy((*new)->champ, file + 2192, tot_char - 2192);
	else
		return (handle_error(3));
	(*new)->size = tot_char - 2192;
	return (0);
}

t_champ	*champ_new(unsigned char *file, int tot_char, int player_nb)
{
	t_champ *champ;

	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		return (NULL);
	if (!(champ->h = (t_header*)malloc(sizeof(t_header))))
		return (NULL);
	if (store_champ_info(file, &champ, tot_char) == -1)
		return (NULL);
	champ->champ_nb = player_nb;
	champ->next = NULL;
	return (champ);
}
