/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_and_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:05:33 by smejia-m          #+#    #+#             */
/*   Updated: 2018/04/09 14:06:47 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_and_free(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	int		j;

	j = 0;
	i = len;
	dest = NULL;
	if (s)
	{
		if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i > 0)
		{
			dest[j] = s[start];
			i--;
			j++;
			start++;
		}
		dest[j] = '\0';
		ft_strdel(&s);
		return (dest);
	}
	return (NULL);
}
