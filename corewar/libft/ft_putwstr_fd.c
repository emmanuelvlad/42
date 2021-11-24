/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:36:53 by fpipart           #+#    #+#             */
/*   Updated: 2016/12/22 11:36:27 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <locale.h>

void	ft_putwstr_fd(wchar_t *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putwchar_fd(str[i], fd);
		i++;
	}
}
