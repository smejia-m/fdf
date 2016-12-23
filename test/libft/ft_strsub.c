/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:21:30 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/23 09:09:26 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	j = 0;
	if (s)
	{
		i = len;
		dst = (char *)malloc(sizeof(*dst) * (len + 1));
		if (dst == NULL)
			return (NULL);
		while (i != 0)
		{
			dst[j] = s[start];
			start++;
			i--;
			j++;
		}
		dst[j] = '\0';
		return (dst);
	}
	return (NULL);
}
