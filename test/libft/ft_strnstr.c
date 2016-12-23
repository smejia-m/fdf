/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:10:28 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/09 16:39:10 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	l = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	l = ft_strlen(s2);
	while (s1[i] != '\0' && i < n)
	{
		while (s2[j] == s1[j + i] && i + j < n)
		{
			j++;
			if (j == l)
				return ((char *)&s1[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
