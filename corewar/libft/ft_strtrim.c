/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:57:06 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/09 10:53:19 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			j;
	size_t			len_s;
	unsigned int	start;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	j = len_s - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (len_s == 0 || i == len_s)
		return (ft_strsub(s, 0, 0));
	start = i;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (ft_strsub(s, start, j - i + 1));
}
