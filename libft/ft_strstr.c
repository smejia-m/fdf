/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:41:04 by smejia-m          #+#    #+#             */
/*   Updated: 2015/12/02 11:04:12 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int l;

	j = 0;
	i = 0;
	l = ft_strlen(s2);
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	while (s1[i])
	{
		while (s2[j] == s1[j + i])
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
