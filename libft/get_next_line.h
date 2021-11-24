/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:41:33 by evlad             #+#    #+#             */
/*   Updated: 2017/04/18 15:31:08 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

typedef struct	s_struct
{
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;
	char		*free;
	int			len;
}				t_struct;

int				get_next_line(const int fd, char **line);

#endif
