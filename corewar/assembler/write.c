/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:32:44 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:04:41 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static unsigned int		reverse_byte_32(unsigned int num)
{
	unsigned int	reverse;

	reverse = 0x000000FF & num;
	reverse = (reverse << 8) + ((0x0000FF00 & num) >> 8);
	reverse = (reverse << 8) + ((0x00FF0000 & num) >> 16);
	reverse = (reverse << 8) + ((0xFF000000 & num) >> 24);
	return (reverse);
}

static unsigned short	reverse_byte_16(unsigned int num)
{
	unsigned short	reverse;

	reverse = 0x00FF & num;
	reverse = (reverse << 8) + ((0xFF00 & num) >> 8);
	return (reverse);
}

ssize_t					fixed_write(int fd, const void *buf, size_t nbyte)
{
	unsigned int	fixed;

	if (nbyte == 4)
		fixed = reverse_byte_32(*(unsigned int*)buf);
	else if (nbyte == 2)
		fixed = reverse_byte_16(*(unsigned int*)buf);
	else
		fixed = *(unsigned int*)buf;
	return (write(fd, &fixed, nbyte));
}

int						write_header(t_main **main, int fd)
{
	t_header	header;

	header.magic = COREWAR_EXEC_MAGIC;
	header.prog_size = (*main)->prog_size;
	ft_bzero(header.prog_name, PROG_NAME_LENGTH);
	ft_bzero(header.comment, COMMENT_LENGTH);
	ft_strcpy(header.prog_name, (*main)->nom);
	ft_strcpy(header.comment, (*main)->comment);
	if (fixed_write(fd, &header.magic, sizeof(header.magic)) == -1)
		return (0);
	if (write(fd, header.prog_name, PROG_NAME_LENGTH) == -1)
		return (0);
	if (fixed_write(fd, &header.prog_size, sizeof(header.prog_size)) == -1)
		return (0);
	if (write(fd, header.comment, COMMENT_LENGTH) == -1)
		return (0);
	return (1);
}
