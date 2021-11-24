/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cor_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:10:40 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 17:07:41 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	read_cor_file(int fd, unsigned char *file, t_champ **champ, int player_nb)
{
	char			buf[1024];
	int				i;
	int				tot_char;
	t_champ			*new;

	tot_char = 0;
	while ((i = read(fd, buf, 1023)) > 0)
	{
		if (tot_char + i > 4000)
			return (-1);
		ft_memcpy(file + tot_char, buf, i);
		tot_char += i;
	}
	if (tot_char < 2192)
		return (handle_error(5));
	new = champ_new(file, tot_char, player_nb);
	champ_add(champ, &new);
	return (0);
}
